cmake_minimum_required(VERSION 4.2.1)
project(PingPong)

add_library(includes 
  src/Ball.cpp
)

target_include_directories(includes
  INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRECT_SOURCE_DIR/include}>
  $<INSTALL_INTERFACE:include>
)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} 
  includes
	raylib
)
