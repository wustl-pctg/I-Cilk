file(REMOVE_RECURSE
  "../../../lib/libPolly.pdb"
  "../../../lib/libPolly.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/Polly.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
