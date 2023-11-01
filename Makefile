# DIN KÄLLKOD-var dina egna .cpp-filer finns
SRC_DIR = src
# FILNAMNET för ditt program som skall byggas, och VAR
OBJ_NAME = play
BUILD_DIR = build/debug

# Windows GCC COMPILER
CC = g++

# Valbara kompileringsflaggor(options)
COMPILER_FLAGS = -std=c++17 -Wall -O0 -g

# ALLA filer med filändelsen .cpp i foldern SRC_DIR
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# INKLUDERINGSFILER–var dina header-filer finns
# Windows INCLUDE_PATHS!
INCLUDE_PATHS = -I ./include
#-Iinclude -IC:/msys64/ucrt64/include

# BIBLIOTEKSFILER–kompilerad objektkod
# Mac INTEL LIBRARY_PATHS!
#LIBRARY_PATHS = -Llib -L/usr/local/lib
# Mac ARM LIBRARY_PATHS!
#LIBRARY_PATHS = -Llib -L/opt/homebrew/lib
# Windows LIBRARY_PATHS
LIBRARY_PATHS =  -L./lib
#-Llib -LC:/msys64/ucrt64/lib

# LÄNKNING - objekfiler som används vid länkning. Enklare program utan SDL behöver normalt inte några speciella länk-flaggor
LINKER_FLAGS =
# Om SDL2 används, Mac LINKER_FLAGS!
#LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
# Om SDL2 används, Windows LINKER_FLAGS!
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
#LINKER_FLAGS = -lSDL2main -lSDL2

all:
	$(CC) $(COMPILER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) $(LINKER_FLAGS) -o $(BUILD_DIR)/$(OBJ_NAME)

run: all
	./$(BUILD_DIR)/$(OBJ_NAME).exe

test:
	g++ src/main.cpp -I.\include -L.\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o build/debug/main