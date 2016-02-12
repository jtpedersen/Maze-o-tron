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
  util.cpp
  Maker.cpp
  BinTreeMaker.cpp
  SideWinderMaker.cpp
  RecursiveBacktrackerMaker.cpp
  PrimMaker.cpp
  Set.cpp
)

add_executable(mazer 
  main.cpp
  MazeWindow.h
  MazeWindow.cpp
  Colorizer.cpp
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

