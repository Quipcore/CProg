cmake_minimum_required(VERSION 3.26)
project(Cprog_Project)

set(CMAKE_CXX_STANDARD 17)

SET(FILES
        src/main.cpp

        src/springhawk/Engine.cpp
        src/springhawk/Input.cpp
        src/springhawk/Scene.cpp
        src/springhawk/SceneBuilder.cpp
        src/springhawk/Input.cpp
        src/springhawk/Time.cpp
        src/springhawk/Vector2.cpp

        src/springhawk/maps/Sectormap.cpp
        src/springhawk/maps/Tilemap.cpp
        src/springhawk/maps/Tile.cpp

        src/springhawk/renderers/Renderer.cpp
        src/springhawk/renderers/DoomRender.cpp
        src/springhawk/renderers/Raycaster.cpp
        src/springhawk/renderers/ui/UIRenderer.cpp

        src/springhawk/ui/TextField.cpp

        src/scripts/GameObject.cpp
        src/scripts/Player.cpp
        src/scripts/Square.cpp

        src/games/Wolfenstein.cpp
        src/games/Tetris.cpp
        src/games/Game.cpp
        src/games/PacMan.cpp
        src/scripts/Wall.cpp
        src/springhawk/renderers/PlaneRenderer.cpp
        src/scripts/PacmanController.cpp
        src/scripts/WolfensteinPlayerController.cpp
)

include_directories(include)

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

add_executable(${PROJECT_NAME} ${FILES})

find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME}
        PRIVATE $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

find_package(SDL2_ttf CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>)

find_package(SDL2_image CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)

# Set the output directory for the executable
set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/debug)

# Add dependencies so that CopyDirectoryTarget is built before YourExecutable
add_dependencies(${PROJECT_NAME} CopyDirectoryTarget)