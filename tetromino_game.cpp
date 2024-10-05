#include <raylib/raylib.h>
#include "pieces.h"
#include <time.h>

#define GRID_W 10
#define GRID_H 20
#define BACKGROUND_COLOR WHITE
#define TICK_DELAY 1

using namespace std;

typedef struct Coord{
    int x;
    int y;
} Coord;

// The grid used for display & game dynamics
static Color game_grid[GRID_W][GRID_H];

/**
 * @brief Sets all elements of the game_grid to the background color
 * 
 */
void initialize_grid();

/**
 * @brief Plays the background music if it has stopped playing
 * 
 * @param background_music The background music to loop
 */
void loop_audio(const Sound& background_music);


int lower_piece(Piece piece, Coord& coordinates);

int is_background(int x, int y);

int main(){

    // Initialize contexts
    InitWindow(500, 1000, "Tetromino Game");
    SetRandomSeed(time(NULL));
    InitAudioDevice();

    // Load Background music
    Sound background_music = LoadSound("tetromino.wav");

    // Load random initial pieces
    Piece current_piece, next_piece;
    current_piece = new_piece();
    next_piece = new_piece();

    // Set initial piece location
    Coord piece_location = {
        (GRID_W - current_piece.size) / 2,

        0
    };

    // Set grid to background color
    initialize_grid();
    char str[] = "9999999";

    while(!WindowShouldClose()){

        // Start music / loop
        loop_audio(background_music);
        if(!lower_piece(current_piece, piece_location)){

            str[0] = 'D';
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        draw_piece(current_piece, 50 * piece_location.x, 50 * piece_location.y, 50);
        DrawText(str, 0, 0, 30, BLACK);
        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();
    return 0;
}

void initialize_grid(){

    for(int i = 0; i < GRID_W; i++){
        for(int j = 0; j < GRID_H; j++){
            game_grid[i][j] = BACKGROUND_COLOR;
        }
    }
}

void loop_audio(const Sound& background_music){

    if(!IsSoundPlaying(background_music)){

        PlaySound(background_music);
    }
}

int lower_piece(Piece piece, Coord& coordinates){

    static double last_update_time = GetTime();

    double current_time = GetTime();

    if(current_time - last_update_time >= TICK_DELAY){

        int piece_can_drop = 1;

        for(int i = 0; i < piece.size; i++){

            if(!is_background(coordinates.x + i, GRID_H - 2 - coordinates.y)){

                piece_can_drop = 0;
            }
        }

        if(coordinates.y == GRID_H - 1){
            piece_can_drop = 0;
        }

        if(piece_can_drop){
            coordinates.y++;
        }

        last_update_time = current_time;
        return piece_can_drop;
    }
    return 1;
}

int is_background(int x, int y){

    if(game_grid[x][y].a != BACKGROUND_COLOR.a){
        return 0;
    }
    if(game_grid[x][y].r != BACKGROUND_COLOR.r){
        return 0;
    }
    if(game_grid[x][y].g != BACKGROUND_COLOR.g){
        return 0;
    }
    if(game_grid[x][y].b != BACKGROUND_COLOR.b){
        return 0;
    }
    return 1;
}