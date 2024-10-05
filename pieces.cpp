#include "pieces.h"
#include <raylib/raylib.h>

/**
 * @brief Rotates a piece clockwise to any rotational-position
 * 
 * @param piece The piece to rotate
 * @param rotations The number of 90 degree rotations to apply to the piece
 *                  (must be in range [1, 3])
 */
static Piece rotate_piece(const Piece& piece, int rotations);


Piece rotate_piece_cw(const Piece& piece){

    int next_state = piece.current_state; // Next rotational-state of piece.
    
    for(int i = 0; i < 3; i++){ // Check validity of clockwise rotational-state 

        next_state++; // Keep state in bounds and loop through
        if(next_state > 3){
            next_state %= 4;
        }

        if(piece.valid_states[next_state]){ // Piece can be rotated
            
            return rotate_piece(piece, i+1); // Rotate piece
        }
    }
    return piece;
}

Piece rotate_piece_ccw(const Piece& piece){

    int next_state = piece.current_state; // Next rotational-state of piece.
    
    for(int i = 0; i < 3; i++){ // Check validity of clockwise rotational-state 

        next_state--; // Keep state in bounds and loop through
        if(next_state < 0){
            next_state += 4;
        }

        if(piece.valid_states[next_state]){ // Piece can be rotated

            return rotate_piece(piece, 3-i); // Rotate piece
        }
    }
    return piece;
}

static Piece rotate_piece(const Piece &piece, int rotations){

    static Piece new_piece;

    switch (rotations){ // Load temporary place-holder piece

        case 1: // 90 degrees clockwise

            for(int i = 0; i < piece.size; i++){
                for(int j = 0; j < piece.size; j++){
                    new_piece.grid[i][j] = piece.grid[piece.size - j - 1][i];
                }
            }
        break;

        case 2: // 180 degrees clockwise

            for(int i = 0; i < piece.size; i++){
                for(int j = 0; j < piece.size; j++){
                    new_piece.grid[i][j] = piece.grid[piece.size - i - 1][piece.size - j - 1];
                }
            }
        break;

        case 3: // 270 degrees clockwise

            for(int i = 0; i < piece.size; i++){
                for(int j = 0; j < piece.size; j++){
                    new_piece.grid[i][j] = piece.grid[j][piece.size - i - 1];
                }
            }
        break;
    }

    return new_piece;
}

void draw_piece(const Piece& piece, int x, int y, int sqr_size){

    for(int i = 0; i < piece.size; i++){
        for(int j = 0; j < piece.size; j++){
            if(piece.grid[i][j]){
                DrawRectangle(x + j * sqr_size, y + i * sqr_size,
                sqr_size, sqr_size, piece.color);
                DrawRectangleLines(x + j * sqr_size, y + i * sqr_size,
                sqr_size, sqr_size, BLACK);
            }
        }
    }
}

Piece new_piece(){

    return game_pieces[GetRandomValue(0, PIECES_COUNT - 1)];
}