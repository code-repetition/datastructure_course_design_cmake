cmake_minimum_required(VERSION 3.23)
project("datastructure_course_design")
include_directories(${PROJECT_SOURCE_DIR}/include/)
file (GLOB_RECURSE src_dir
    "./src/*.cpp"
    "./src/*.c"
    "./src/*.h"
)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_NAME}/bin)
add_executable(${PROJECT_NAME} ${src_dir})