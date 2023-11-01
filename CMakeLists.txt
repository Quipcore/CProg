cmake_minimum_required(VERSION 3.25)
project(CProg)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(SDL2_LIB_DIR ${CMAKE_SOURCE_DIR}/lib)

include_directories(${INCLUDE_DIR})

link_directories(${SDL2_LIB_DIR})

add_executable(${PROJECT_NAME} src/main.cpp)

include_directories(src)
add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} SDL2)

# Set the output directory for the executable
set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/debug)