#include <stdlib.h>
#include <stdio.h>

#include "getoptions.h"
#include "fib.h"

extern int fib_n;
extern int fib_count;
extern int io_delay;
extern int nruns;

const char *specifiers[] = {"-n", "-b", "-count", "-delay", "-nruns", "-h", 0};
int opt_types[] = {INTARG, INTARG, INTARG, INTARG, INTARG, BOOLARG, 0};

void load_fib_mr_options(int argc, char *argv[]) {
  int help;

  int def_fib_n = fib_n;
  int def_sbc = serial_base_case;
  int def_fib_count = fib_count;
  int def_io_delay = io_delay;
  int def_nruns = nruns;

  get_options(argc, argv, specifiers, opt_types, &fib_n, &serial_base_case, &fib_count, &io_delay, &nruns, &help);

  if (help) {
      printf("Usage: %s [-n #] [-b #] [-count #] [-delay #] [-nruns #] [-h]\n\n\t-n Specifies the fibonacci number to compute (default: %d)\n\t-b Specifies the serial base case for fib (default: %d)\n\t-count Specifies how many fib jobs to create (default: %d)\n\t-delay Specifies the IO delay to simulate in microseconds (default %d)\n\t-nruns Specifies the number of times to run the benchmark (default: %d)\n\t-h Print this help message and exit\n\n", argv[0], def_fib_n, def_sbc, def_fib_count, def_io_delay, def_nruns);
      exit(0);
  }
}
