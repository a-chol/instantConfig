cmake_minimum_required(VERSION 2.8)

project( icfg-static-tests)


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
endforeach (TestFile ${TestFiles})