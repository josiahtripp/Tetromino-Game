#Compiler setup
CC = g++
CFLAGS = -Wall -Wextra

#Paths
INCLUDE_PATH = /devlib/include
LIB_PATH = /devlib/raylib/lib

#Files
SRC_FILES = tetromino_game.cpp pieces.cpp
OBJ_FILES = tetromino_game.o pieces.o
BINARY = tetromino_game

desktop:
	$(CC) $(CFLAGS) -I $(INCLUDE_PATH) -c $(SRC_FILES)
	$(CC) $(CFLAGS) -o $(BINARY) $(OBJ_FILES) -L $(LIB_PATH) $(LIB_PATH)/libraylib.a -lGL
	$(RM) *.o

thinkpad:
	$(CC) $(CFLAGS) -c $(SRC_FILES)
	$(CC) $(CFLAGS) -o $(BINARY) $(OBJ_FILES) -lraylib
	$(RM) *.o