cmake_minimum_required(VERSION 4.2.1)
project(Inventory)
find_package(SQLite3)

add_library(includes
  src/Item.cpp
  src/Database.cpp
)

target_include_directories(includes
  INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRECT_SOURCE_DIR/include}>
  $<INSTALL_INTERFACE:include>
)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} includes
  SQLite::SQLite3
)
