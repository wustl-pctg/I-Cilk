#pragma once

#ifdef NO_PRIO
  #include "noprio_macros.h"
#else
  #include <cilk/cilk_priority.h>
#endif


using cilk::Low;

CilkDeclareNewPriority(PeriodicCompressP, Low);
CilkDeclareNewPriority(PrintOrCompressP, PeriodicCompressP);
CilkDeclareNewPriority(SortP, PrintOrCompressP);
CilkDeclareNewPriority(SendP, SortP);
CilkDeclareNewPriority(LoopP, SendP);
