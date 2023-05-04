file(REMOVE_RECURSE
  "libsqlite.a"
  "libsqlite.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/sqlite.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
