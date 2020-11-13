file(REMOVE_RECURSE
  "libRTInterception.test.x86_64.pdb"
  "libRTInterception.test.x86_64.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/RTInterception.test.x86_64.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
