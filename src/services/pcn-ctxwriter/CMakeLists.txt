cmake_minimum_required (VERSION 3.2)

set (CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/src/libs/bcc/src/cc/)
add_subdirectory(src)
