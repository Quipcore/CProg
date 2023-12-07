SET(FILES
        springhawk/Engine.cpp
        springhawk/Input.cpp
        springhawk/Scene.cpp
        springhawk/SceneBuilder.cpp
        springhawk/Input.cpp
        springhawk/Time.cpp
        springhawk/Vector2.cpp

#        springhawk/maps/Map.cpp
        springhawk/maps/Sectormap.cpp
        springhawk/maps/Tilemap.cpp
        springhawk/maps/Tile.cpp

        springhawk/renderers/Renderer.cpp
        springhawk/renderers/DoomRender.cpp
        springhawk/renderers/Raycaster.cpp
        springhawk/renderers/ui/UIRenderer.cpp

        springhawk/ui/TextField.cpp

        scripts/GameObject.cpp
        scripts/Player.cpp
        scripts/Square.cpp

        games/Wolfenstein.cpp
        games/Tetris.cpp
        games/Game.cpp
        games/PacMan.cpp
        scripts/Wall.cpp
        springhawk/renderers/PlaneRenderer.cpp
        scripts/PacmanController.cpp

)

add_library(CProg STATIC ${FILES})

#target_link_libraries(scripts)
#target_link_libraries(Springhawk)
#target_link_libraries(games)
##add_library(src STATIC ${FILES})