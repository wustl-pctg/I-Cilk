file(REMOVE_RECURSE
  "libRTAsanTest.x86_64-with-calls.pdb"
  "libRTAsanTest.x86_64-with-calls.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang ASM CXX)
  include(CMakeFiles/RTAsanTest.x86_64-with-calls.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
