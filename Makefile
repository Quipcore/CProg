SRC_DIR = src
OBJ_NAME = play
BUILD_DIR = build/debug

PATH_TO_COMPILER = C:/msys64/mingw64

CC = g++
COMPILER_FLAGS = -std=c++17 -Wall -O0 -g

#From https://stackoverflow.com/a/12959764
# RECURSIVE_WILDCARD = $(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call RECURSIVE_WILDCARD,$d/,$2))
# SRC_FILES = $(call RECURSIVE_WILDCARD,$(SRC_DIR)/,*.cpp)

SRC_FILES = src/main.cpp src/springhawk/Engine.cpp src/springhawk/Input.cpp src/springhawk/Scene.cpp src/springhawk/SceneBuilder.cpp src/springhawk/Input.cpp src/springhawk/Time.cpp src/springhawk/Vector2.cpp src/springhawk/maps/Sectormap.cpp src/springhawk/maps/Tilemap.cpp src/springhawk/maps/Tile.cpp src/springhawk/renderers/Renderer.cpp src/springhawk/renderers/PlaneRenderer.cpp src/springhawk/renderers/DoomRender.cpp src/springhawk/renderers/Raycaster.cpp src/springhawk/renderers/UIRenderer.cpp src/scripts/UIComponents/TextField.cpp src/scripts/Gamecomponents/GameObject.cpp src/scripts/Gamecomponents/Player.cpp src/scripts/Gamecomponents/Wall.cpp src/scripts/Gamecomponents/PacmanController.cpp src/scripts/Gamecomponents/WolfensteinController.cpp src/games/Wolfenstein.cpp src/games/Tetris.cpp src/games/PacMan.cpp src/scripts/UIComponents/UIComponent.cpp src/scripts/UIComponents/ScoreField.cpp src/scripts/Gamecomponents/Blinky.cpp src/springhawk/Audio.cpp src/scripts/Gamecomponents/TeleportPad.cpp

INCLUDE_PATHS = -Iinclude -I$(PATH_TO_COMPILER)/include
LIBRARY_PATHS = -Llib -L$(PATH_TO_COMPILER)/lib
LINKER_FLAGS = -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf -lSDL2_mixer

#if user is on windows, use powershell needs to copy resources to build directory
RESOURCE_COPY =
ifeq ($(OS),Windows_NT)
RESOURCE_COPY := powershell -Command "Copy-Item -Path .\resources\ -Destination $(BUILD_DIR) -Recurse -Force -ErrorAction SilentlyContinue"
endif

all:
	$(CC) $(COMPILER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) $(LINKER_FLAGS) -o $(BUILD_DIR)/$(OBJ_NAME)
	$(RESOURCE_COPY)

run: all
	./$(BUILD_DIR)/$(OBJ_NAME).exe


.PHONY: all run
