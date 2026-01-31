cmake_minimum_required(VERSION 4.2.1)
project(Blackjack)

add_library(includes 
  src/Card.cpp 
  src/Deck.cpp 
  src/Player.cpp
  src/Dealer.cpp
  src/Hand.cpp
  src/Game.cpp
  src/Display.cpp
)

target_include_directories(includes
  INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRECT_SOURCE_DIR/include}>
  $<INSTALL_INTERFACE:include>
)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} includes)
