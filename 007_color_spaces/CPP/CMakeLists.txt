cmake_minimum_required(VERSION 3.0.0)
project(interactive_color VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)
find_package(Threads REQUIRED)

add_executable(interactive_color_detect interactive_color_detect.cpp)
add_executable(interactive_color_segment interactive_color_segment.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX__STANDARD_REQUIRED ON)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(interactive_color_detect ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(interactive_color_segment ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})