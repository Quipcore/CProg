SRC_DIR = src
OBJ_NAME = play
BUILD_DIR = build/debug

PATH_TO_COMPILER = C:/msys64/mingw64

CC = g++
COMPILER_FLAGS = -std=c++17 -Wall -O0 -g

#From https://stackoverflow.com/a/12959764
RECURSIVE_WILDCARD = $(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call RECURSIVE_WILDCARD,$d/,$2))
SRC_FILES = $(call RECURSIVE_WILDCARD,$(SRC_DIR)/,*.cpp)

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