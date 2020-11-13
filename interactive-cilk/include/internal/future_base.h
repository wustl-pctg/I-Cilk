#pragma once

#include <internal/abi.h>

extern "C" {
__cilkrts_deque_link* __cilkrts_get_deque_link();
}

class future_base {
protected:
    __cilkrts_deque_link head = {
        .d = NULL, .next = NULL
    };

    __cilkrts_deque_link *volatile tail = &head;

    bool created;

    inline void suspend_deque() {
        __cilkrts_deque_link *l = __cilkrts_get_deque_link();
        __cilkrts_deque_link *t = tail;
        bool susp = false;

        while (t != NULL) {
            l->next = t;
            if (__atomic_compare_exchange_n(&tail, &t, l, false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)) {
                susp = true;
                break;
            }
            t = tail;
        }

        if (susp) {
            __cilkrts_suspend_deque(0,0);
        }
    }

    inline void resume_deques() {
        __cilkrts_deque_link *t = __atomic_exchange_n(&tail, NULL, __ATOMIC_SEQ_CST);
        __cilkrts_deque_link *next = NULL;

        if (t != &head) {
            while (t != &head && t->next != &head) {
                // Use the next variable to store the next
                // BEFORE resuming the current; once we
                // resume this deque, its deque link
                // can be modified by another thread
                next = t->next;
                __cilkrts_make_resumable(t->d);
                t = next;
            }

            if(t != &head) {
                // This is the oldest deque, so likely has
                // the most potential. If our deque is empty,
                // resume it and delete our deque; else mark
                // the deque as resumable and continue on our
                // own deque.
                assert(t->d);
                __cilkrts_resume_suspended(t->d, 2);
            }
        }
    }

public:
    future_base() {
      reset();
    }

    inline bool ready() {
        // We set the tail to NULL only when the
        // future completes
        return tail == NULL;
    }

    inline void reset() {
        tail = &head;
        created = false;
    }

    inline bool hasBeenCreated() {
      return created;
    }

    inline void __attribute__((always_inline)) __internal_mark_created() {
      created = true;
    }
};
