cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME cadex)

set(SOURCE_FILES
"src/CX_Cadex.cpp"
)

find_package(OpenMP)

project(${PROJECT_NAME} LANGUAGES CXX)

add_executable (${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} core::lib)
target_link_libraries(${PROJECT_NAME} OpenMP::OpenMP_CXX)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
