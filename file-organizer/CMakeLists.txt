cmake_minimum_required(VERSION 4.2.1)
project(Filer)

add_library(includes
  src/Organizer.cpp
  src/Creator.cpp
  src/Filer.cpp
)

target_include_directories(includes
  INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRECT_SOURCE_DIR/include}>
  $<INSTALL_INTERFACE:include>
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "-std=c++17")

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} includes)
