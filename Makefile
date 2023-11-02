SRC_DIR = src
OBJ_NAME = play
BUILD_DIR = build/debug

CC = g++
COMPILER_FLAGS = -std=c++17 -Wall -O0 -g

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
INCLUDE_PATHS = -I ./include
LIBRARY_PATHS =  -L./lib

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

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