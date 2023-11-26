cmake_minimum_required(VERSION 3.26)
project(Play)

set(CMAKE_CXX_STANDARD 17)

set(COMPILER_DIR C:/msys64/mingw64)
set(SDL2_INCLUDE_DIR ${COMPILER_DIR}/include)
set(SDL2_BIN_DIR ${COMPILER_DIR}/bin)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_BIN_DIR})
link_directories(${SDL2_BIN_DIR}/../lib)

include_directories(./include)
add_subdirectory(src)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} SDL2)
target_link_libraries(${PROJECT_NAME} SDL2main)
target_link_libraries(${PROJECT_NAME} SDL2_image)
target_link_libraries(${PROJECT_NAME} SDL2_ttf)
target_link_libraries(${PROJECT_NAME} SDL2_mixer)

target_link_libraries(${PROJECT_NAME} CProg)

# Set the output directory for the executable
set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/debug)