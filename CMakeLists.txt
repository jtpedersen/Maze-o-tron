cmake_minimum_required(VERSION 3.0.0)

project(Mazer)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")


find_package(Qt5Core)
find_package(Qt5Widgets)
find_package(Qt5Gui)
#find_package(Qt5OpenGL)

#resources
qt5_add_resources(
  resources_added 
  "icons.qrc")


# Tell CMake to create the helloworld executable
add_executable(mazer 
main.cpp
MazeWindow.h
MazeWindow.cpp
${resources_added}
)

qt5_use_modules(mazer Core Gui Widgets)

# # Use the Widgets module from Qt 5.
# target_link_libraries(helloworld 
#   Qt5::Widgets
#   Qt5::Core
#   Qt5::Application
#   )