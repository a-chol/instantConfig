
set( TestProjectLocation "${CMAKE_BINARY_DIR}/tests_static")

configure_file(
  "ProjectSetup.h.IN"
  "ProjectSetup.h"
)


set(CurrentGenerator ${CMAKE_GENERATOR})

message("executing test_static generation : cmake -G\"${CurrentGenerator}\" ${CMAKE_CURRENT_SOURCE_DIR}/static")

file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/tests_static")

execute_process(
  COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" -DCMAKE_CXX_FLAGS=-std=c++11 ${CMAKE_CURRENT_SOURCE_DIR}/static
  # COMMAND dir ..
  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/tests_static"
  
  RESULT_VARIABLE TestProjectGenRes
  OUTPUT_VARIABLE TestProjectGenOut
  ERROR_VARIABLE TestProjectGenErr
)

if ( NOT TestProjectGenRes EQUAL 0)
  message( FATAL_ERROR "Could not generate test_static : ${TestProjectGenOut} \n  ${TestProjectGenErr}")
endif ( NOT TestProjectGenRes EQUAL 0)