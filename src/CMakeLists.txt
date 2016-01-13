#resources
qt5_add_resources(
  resources_added 
  "../res/icons.qrc")

add_executable(mazer 
  main.cpp
  MazeWindow.h
  MazeWindow.cpp
  Cell.h
  Cell.cpp
  Grid.h
  Grid.cpp
  ${resources_added}
  )

qt5_use_modules(mazer Core Gui Widgets)

add_executable(ascii 
  shell.cpp
  Cell.h
  Cell.cpp
  Grid.h
  Grid.cpp
  )

