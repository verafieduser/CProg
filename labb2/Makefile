# Mac, gcc och sdl2 genom homebrew
# Windows, gcc och sdl2 genom MSYS2 mingw-w64

SRC_DIR = src
BUILD_DIR = build/debug
CC = g++
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_NAME = play
# Mac INCLUDE_PATHS
#INCLUDE_PATHS = -Iinclude -I/usr/local/include
# Windows INCLUDE_PATHS
INCLUDE_PATHS = -Iinclude -ID:/Programming/libraries/msys2/mingw64/include
# Mac LIBRARY_PATHS
#LIBRARY_PATHS = -Llib -L/usr/local/lib
# Windows LIBRARY_PATHS
LIBRARY_PATHS = -Llib -LD:/Programming/libraries/msys2/mingw64/lib
COMPILER_FLAGS = -std=c++11 -Wall -Wextra -pedantic -O0 -g
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
# Om SDL2 används, Mac LINKER_FLAGS!
#LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
# Om SDL2 används, Windows LINKER_FLAGS!
#LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf


all:
	$(CC) $(COMPILER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) $(LINKER_FLAGS) -o $(BUILD_DIR)/$(OBJ_NAME)