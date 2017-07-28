cmake_minimum_required(VERSION 3.8)
project(imageBlur)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BlurClass.cpp BlurClass.h)
add_executable(imageBlur ${SOURCE_FILES})

find_package(OpenCV REQUIRED core imgproc highgui)
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui)
target_link_libraries(imageBlur ${OpenCV_LIBS})
