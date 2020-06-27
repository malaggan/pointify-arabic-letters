cmake_minimum_required(VERSION 2.8.12)
project(PointifyArabic)

add_definitions("-std=c++17")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_CXX_COMPILER /usr/local/bin/g++-9)
set(CMAKE_C_COMPILER /usr/local/bin/gcc-9)

add_executable(pointify-arabic pointify-arabic.cpp)
target_link_libraries(pointify-arabic ${CONAN_LIBS})
