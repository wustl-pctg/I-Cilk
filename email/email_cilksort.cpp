#include <cstring>

#include <cilk/sync_handle.h>

#include "inbox.h"
#include "email_cilksort.h"

#define MERGESIZE     (5)
#define QUICKSIZE     (10)
#define INSERTIONSIZE (5)

email** binsplit(email *val, email **low, email **high, int fieldId) {

  /*
   * returns index which contains greatest element <= val.  If val is
   * less than all elements, returns low-1
   */
  email **mid;

  while (low != high) {
    mid = low + ((high - low + 1) / 2);
    if (val->compareByField(*mid, fieldId) <= 0)
      high = mid - 1;
    else
      low = mid;
  }

  if ((*low)->compareByField(val, fieldId) > 0)
    return low - 1;
  else
    return low;
}

void seqmerge(email **low1, email **high1, 
    email **low2, email **high2, email **lowDest, int fieldId) {

  email *a1;
  email *a2;

  if (low1 < high1 && low2 < high2) {
    a1 = *low1;
    a2 = *low2;
    for (;;) {
      if (a1->compareByField(a2, fieldId) < 0) {
        *lowDest++ = a1;
        a1 = *++low1;
        if (low1 >= high1)
          break;
      } else {
        *lowDest++ = a2;
        a2 = *++low2;
        if (low2 >= high2)
          break;
      }
    }
  }
  if (low1 <= high1 && low2 <= high2) {
    a1 = *low1;
    a2 = *low2;
    for (;;) {
      if (a1->compareByField(a2, fieldId) < 0) {
        *lowDest++ = a1;
        ++low1;
        if (low1 > high1)
          break;
        a1 = *low1;
      } else {
        *lowDest++ = a2;
        ++low2;
        if (low2 > high2)
          break;
        a2 = *low2;
      }
    }
  }
  if (low1 > high1) {
    memcpy(lowDest, low2, sizeof(email*) * (high2 - low2 + 1));
  } else {
    memcpy(lowDest, low1, sizeof(email*) * (high1 - low1 + 1));
  }
}

void cilkmerge(email **low1, email **high1, email **low2, email **high2, email **lowDest, int fieldId) {
  email **split1;
  email **split2;
  long int lowsize;

  if (high2 - low2 > high1 - low1) {
    std::swap(high2, high1);
    std::swap(low2, low1);
  }

  // It is empty!
  if (high1 < low1) {
    memcpy(lowDest, low2, (high2 - low2) * sizeof(email*));
    return;
  }

  if (high2 - low2 < MERGESIZE) {
    seqmerge(low1, high1, low2, high2, lowDest, fieldId);
    return;
  }

  split1 = ((high1 - low1 + 1) / 2) + low1;
  split2 = binsplit(*split1, low2, high2, fieldId);
  lowsize = split1 - low1 + split2 - low2;

  *(lowDest + lowsize + 1) = *split1;

  cilk_enable_spawn_in_this_func();
  cilk_spawn3_void(cilkmerge, low1, split1 - 1, low2, split2, lowDest, fieldId);
  cilkmerge(split1 + 1, high1, split2 + 1, high2, lowDest + lowsize + 2, fieldId);
  cilk_sync2();
}

static inline email* med3(email* a, email* b, email* c, int fieldId) {
  if (a->compareByField(b, fieldId) < 0) {
    if (b->compareByField(c, fieldId) < 0) {
      return b;
    } else {
      if (a->compareByField(c, fieldId) < 0)
        return c;
      else
        return a;
    }
  } else {
    if (b->compareByField(c, fieldId) > 0) {
      return b;
    } else {
      if (a->compareByField(c, fieldId) > 0)
        return c;
      else
        return a;
    }
  }
}

static inline email* choose_pivot(email **low, email **high, int fieldId) {

  return med3(*low, *high, low[(high - low) / 2], fieldId);
}

static email** seqpart(email **low, email **high, int fieldId) {

  email* pivot;
  email *h, *l;
  email **curr_low = low;
  email **curr_high = high;

  pivot = choose_pivot(low, high, fieldId);

  while (1) {
    while ((h = *curr_high)->compareByField(pivot, fieldId) > 0)
      curr_high--;

    while ((l = *curr_low)->compareByField(pivot, fieldId) < 0)
      curr_low++;

    if (curr_low >= curr_high)
      break;

    *curr_high-- = l;
    *curr_low++ = h;
  }

  /*
   * I don't know if this is really necessary.
   * The problem is that the pivot is not always the
   * first element, and the partition may be trivial.
   * However, if the partition is trivial, then
   * *high is the largest element, whence the following
   * code.
   */
  if (curr_high < high)
    return curr_high;
  else
    return curr_high - 1;
}

static void insertion_sort(email **low, email **high, int fieldId) {

  email **p, **q;
  email *a, *b;

  for (q = low + 1; q <= high; ++q) {
    a = q[0];
    for (p = q - 1; p >= low && (b = p[0])->compareByField(a, fieldId) > 0; p--)
      p[1] = b;
    p[1] = a;
  }
}

/*
 * tail-recursive quicksort, almost unrecognizable :-)
 */
void seqquick(email **low, email **high, int fieldId) {

  email **p;

  while (high - low >= INSERTIONSIZE) {
    p = seqpart(low, high, fieldId);
    seqquick(low, p, fieldId);
    low = p + 1;
  }

  insertion_sort(low, high, fieldId);
}

void cilksort_inner(email **mail, email **tmpArray, int n, int fieldId) {
  if (n < QUICKSIZE) {
    seqquick(mail, mail + n - 1, fieldId);
    return;
  }

  int quarterN = n / 4;
  email **a = mail;
  email **b = a + quarterN;
  email **c = b + quarterN;
  email **d = c + quarterN;

  email **tmpA = tmpArray;
  email **tmpB = tmpA + quarterN;
  email **tmpC = tmpB + quarterN;
  email **tmpD = tmpC + quarterN;

  cilk_enable_spawn_in_this_func();

  cilk_spawn3_void(cilksort_inner, a, tmpA, quarterN, fieldId);
  cilk_spawn3_void(cilksort_inner, b, tmpB, quarterN, fieldId);
  cilk_spawn3_void(cilksort_inner, c, tmpC, quarterN, fieldId);
  cilksort_inner(d, tmpD, n - 3*quarterN, fieldId);
  cilk_sync2();

  cilk_spawn3_void(cilkmerge, a, a + quarterN - 1, b, b + quarterN - 1, tmpA, fieldId);
  cilkmerge(c, c + quarterN - 1, d, mail + n - 1, tmpC, fieldId);
  cilk_sync2();

  cilkmerge(tmpA, tmpC - 1, tmpC, tmpA + n - 1, a, fieldId);
}

void cilksort(email **mail, int n, int fieldId) {
  email **tmpArray = (email **) malloc(sizeof(email) * n);
  cilksort_inner(mail, tmpArray, n, fieldId);
}
