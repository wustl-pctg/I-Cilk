file(REMOVE_RECURSE
  "libRTSanitizerCommon.test.nolibc.x86_64.pdb"
  "libRTSanitizerCommon.test.nolibc.x86_64.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang ASM CXX)
  include(CMakeFiles/RTSanitizerCommon.test.nolibc.x86_64.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
