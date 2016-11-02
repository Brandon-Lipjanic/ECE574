
set( CMAKE_CXX_FLAGS "-Wall -g" )
set( CMAKE_CXX_FLAGS "/W3 /EHsc" )
file( GLOB SRCS *.cpp *.h )
add_executable( Assignment2 ${SRCS} )