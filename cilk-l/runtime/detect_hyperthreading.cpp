#include <fstream>
#include <string>

#include "bug.h"

// Should be correct in OSX/BSD and Linux
static std::string construct_sibling_list_filename(unsigned long coreId) {
  std::string filename("/sys/devices/system/cpu/cpu");
  filename += std::to_string(coreId);
  filename += std::string("/topology/thread_siblings_list");
  return filename;
}

extern "C" {

unsigned int num_hyperthreads_per_core() {
  std::string siblingFilename = construct_sibling_list_filename(0ul);
  std::ifstream siblingFile(siblingFilename);
  CILK_ASSERT(siblingFile.good());

  std::string dummy;
  unsigned int count = 0;

  while (std::getline(siblingFile, dummy, ',')) {
    ++count;
  }

  CILK_ASSERT(count > 0);
  return count;
}

bool hyperthreading_is_enabled() {
  return num_hyperthreads_per_core() > 1;
}

}
