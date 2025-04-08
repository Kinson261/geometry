cmake_minimum_required(VERSION 3.5)


project(MyLibrary)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)


add_executable(MyLibrary main.cpp)
target_include_directories(MyLibrary PRIVATE src)


find_package(Catch2 REQUIRED)

add_executable(MyLibraryTest test/testPoint.cpp)
target_link_libraries(MyLibraryTest PRIVATE Catch2::Catch2)

enable_testing()
add_test(NAME MyLibraryTest COMMAND MyLibraryTest)
