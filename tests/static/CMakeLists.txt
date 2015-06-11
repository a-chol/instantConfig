cmake_minimum_required(VERSION 2.8)

project(icfg-static-tests)


include_directories(
  ../..
  .
)

file(
  GLOB
  TestFiles
  "*.cpp"
)



foreach (TestFile ${TestFiles})
  get_filename_component(TestFilename ${TestFile} NAME_WE)
  add_executable(${TestFilename} ${TestFile})

  if (NOT WIN32 AND NOT MSYS AND NOT MINGW)
    target_link_libraries(${TestFilename} stdc++)
  endif (WIN32 OR MSYS OR MINGW)
  
endforeach (TestFile ${TestFiles})
