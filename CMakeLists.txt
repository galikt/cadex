cmake_minimum_required (VERSION 3.8)
project ("cadex")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/executable)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/executable)
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/executable)

add_compile_definitions(_USE_MATH_DEFINES)

add_subdirectory ("cadex")
add_subdirectory ("core")
