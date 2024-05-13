cmake_minimum_required(VERSION 3.21)
project(image_processor)

set(CMAKE_CXX_STANDARD 23)

add_executable(image_processor bmp_image.cpp color.cpp crop.cpp filters_controller.cpp grayscale.cpp image_filter.cpp main.cpp)
