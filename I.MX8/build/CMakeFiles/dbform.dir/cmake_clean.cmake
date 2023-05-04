file(REMOVE_RECURSE
  "libdbform.a"
  "libdbform.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/dbform.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
