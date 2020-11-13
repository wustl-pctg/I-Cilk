file(REMOVE_RECURSE
  "libRTAsanTest.x86_64-inline.pdb"
  "libRTAsanTest.x86_64-inline.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang ASM CXX)
  include(CMakeFiles/RTAsanTest.x86_64-inline.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
