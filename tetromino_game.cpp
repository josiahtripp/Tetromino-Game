#include <raylib/raylib.h>
#include "pieces.h"
#include <time.h>

#define GRID_W 10
#define GRID_H 20
#define BACKGROUND_COLOR RAYWHITE

using namespace std;

static Color game_grid[GRID_W][GRID_H];

Piece new_piece();

void initialize_grid();



int main(){

    InitWindow(800, 800, "Tetromino Game");
    SetRandomSeed(time(NULL));

    Piece current_piece, next_piece;

    current_piece = new_piece();
    next_piece = new_piece();

    initialize_grid();

    while(!WindowShouldClose()){

        if(!lower_piece()){

            add_piece_to_grid();
            check_lines();
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        draw_piece(current_piece, 100, 100, 50);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

Piece new_piece(){

    return game_pieces[GetRandomValue(0, PIECES_COUNT - 1)];
}

void initialize_grid(){

    for(int i = 0; i < GRID_W; i++){
        for(int j = 0; j < GRID_H; j++){
            game_grid[i][j] = BACKGROUND_COLOR;
        }
    }
}