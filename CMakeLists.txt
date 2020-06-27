cmake_minimum_required(VERSION 2.8.12)
project(PointifyArabic)

add_definitions("-std=c++17")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
SET(CMAKE_BUILD_TYPE RelWithDebInfo)

add_executable(pointify-arabic pointify-arabic.cpp)
target_link_libraries(pointify-arabic ${CONAN_LIBS})
