cmake_minimum_required(VERSION 3.1.0)

project(Mazer)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set (CMAKE_CXX_STANDARD 17)


find_package(Qt5Core)
find_package(Qt5Widgets)
find_package(Qt5Gui)
#find_package(Qt5OpenGL)
 
add_subdirectory(src)
add_subdirectory(gmock-1.7.0)
enable_testing()
add_subdirectory(test)
