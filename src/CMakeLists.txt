#resources
qt5_add_resources(
  resources_added 
  "../res/icons.qrc")

add_library(
  maze
  Cell.h
  Cell.cpp
  Grid.h
  Grid.cpp
  BinTreeMaker.cpp
)

add_executable(mazer 
  main.cpp
  MazeWindow.h
  MazeWindow.cpp
  ${resources_added}
  )

qt5_use_modules(mazer Core Gui Widgets)

target_link_libraries(
  mazer
  maze)

add_executable(ascii 
  shell.cpp
  )

target_link_libraries(
  ascii
  maze)

