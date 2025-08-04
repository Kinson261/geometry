cmake_minimum_required(VERSION 3.25)


project(MyLibrary)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)


add_executable(MyLibrary main.cpp)
target_include_directories(MyLibrary PRIVATE src)


find_package(Catch2 REQUIRED)
add_executable(AllTests test/testPoint2D.cpp test/testPoint3D.cpp test/testPoint3D4.cpp)
add_executable(TestPoint2D test/testPoint2D.cpp)
add_executable(TestPoint3D test/testPoint3D.cpp)
add_executable(TestPoint3D4 test/testPoint3D4.cpp)
