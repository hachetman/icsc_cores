
cmake_minimum_required(VERSION 3.12)


set(CMAKE_CXX_STANDARD 17)

enable_testing()


find_package(SVC REQUIRED)

add_subdirectory(src)
