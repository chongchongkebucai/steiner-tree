cmake_minimum_required(VERSION 3.1)

project(tree)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE DEBUG)

include_directories(${PROJECT_SOURCE_DIR}/flute3/)
include_directories(${PROJECT_SOURCE_DIR}/SteinerTree/)
include_directories(${PROJECT_SOURCE_DIR}/Geometric/)
include_directories(${PROJECT_SOURCE_DIR}/DataStructure/)

add_subdirectory(flute3)
add_subdirectory(SteinerTree)

add_compile_options(-Wall -Werror -g)
add_executable(tree TestFlute.cc)
target_link_libraries(tree
    steiner_tree
    flute 
)

