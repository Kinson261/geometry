cmake_minimum_required(VERSION 3.30)


project(Geometry)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_GENERATOR "Unix Makefiles")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Catch2 REQUIRED)
# add_executable(AllTests test/testPoint2D.cpp test/testPoint3D.cpp test/testPoint3D4.cpp)
add_executable(TestPoint2D test/testPoint2D.cpp)
add_executable(TestPoint3D test/testPoint3D.cpp)
add_executable(TestPoint3D4 test/testPoint3D4.cpp)
add_executable(TestVector test/testVector.cpp)

add_executable(Geometry main.cpp src/point2D.h src/point3D.h src/point3D4.h src/axis.h)
target_include_directories(Geometry PRIVATE src)
