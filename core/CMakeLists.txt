cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME core)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS ON)
#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(${PROJECT_NAME})
add_library(${PROJECT_NAME}::lib ALIAS ${PROJECT_NAME})

include(GenerateExportHeader)
set(FILE_NAME_SHARED "CX_ExportShared.h")
generate_export_header(${PROJECT_NAME} EXPORT_FILE_NAME include/${FILE_NAME_SHARED})

set(HEADER_FILES
  "include/CX_Export.h"
  "include/CX_ShapeBase.h"
  "include/CX_Circle.h"
  "include/CX_Ellipse.h"
  "include/CX_Spiral.h"
  "include/CX_Core.h"
  "include/CX_ShapeFactory.h"
  "include/CX_Type.h"
  "include/CX_Obj.h")

set(SOURCE_FILES
  "src/CX_ShapeBase.cpp"
  "src/CX_Circle.cpp"
  "src/CX_Ellipse.cpp"
  "src/CX_Spiral.cpp"
  "src/CX_ShapeFactory.cpp"
  "src/CX_Type.cpp"
  "src/CX_Obj.cpp")

project(${PROJECT_NAME} LANGUAGES CXX)

target_sources(${PROJECT_NAME} PRIVATE ${HEADER_FILES} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR}/include)
