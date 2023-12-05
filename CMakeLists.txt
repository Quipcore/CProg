cmake_minimum_required(VERSION 3.26)
project(Cprog_Project)

set(CMAKE_CXX_STANDARD 17)

set(COMPILER_DIR C:/msys64/mingw64)
set(SDL2_INCLUDE_DIR ${COMPILER_DIR}/include)
set(SDL2_BIN_DIR ${COMPILER_DIR}/bin)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_BIN_DIR})
link_directories(${SDL2_BIN_DIR}/../lib)

include_directories(./include)
add_subdirectory(src)

# Set the source and destination directories
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/resources)
set(DESTINATION_DIR ${CMAKE_SOURCE_DIR}/build/debug/resources)

# Add a custom command to copy the entire directory
add_custom_command(
        OUTPUT ${DESTINATION_DIR}  # Specify the output directory of the command
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${SOURCE_DIR} ${DESTINATION_DIR}
        COMMENT "Copying directory to destination"
)

# Add a custom target to make sure the custom command is executed before building the main target
add_custom_target(CopyDirectoryTarget DEPENDS ${DESTINATION_DIR})


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

# Add dependencies so that CopyDirectoryTarget is built before YourExecutable
add_dependencies(${PROJECT_NAME} CopyDirectoryTarget)