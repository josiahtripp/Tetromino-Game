#include "pieces.h"

/**
 * @brief Rotates a piece clockwise to any rotational-position
 * 
 * @param piece The piece to rotate
 * @param rotations The number of 90 degree rotations to apply to the piece
 *                  (must be in range [1, 3])
 */
static void rotate_piece(Piece &piece, int rotations);


void rotate_piece_cw(Piece &piece){

    int next_state = piece.current_state; // Next rotational-state of piece.
    
    for(int i = 0; i < 3; i++){ // Check validity of clockwise rotational-state 

        next_state++; // Keep state in bounds and loop through
        if(next_state > 3){
            next_state %= 4;
        }

        if(piece.valid_states[next_state]){ // Piece can be rotated

            rotate_piece(piece, i+1); // Rotate piece
            piece.current_state = next_state; // Update state
            return;
        }
    }
}

void rotate_piece_ccw(Piece &piece){

    int next_state = piece.current_state; // Next rotational-state of piece.
    
    for(int i = 0; i < 3; i++){ // Check validity of clockwise rotational-state 

        next_state--; // Keep state in bounds and loop through
        if(next_state < 0){
            next_state += 4;
        }

        if(piece.valid_states[next_state]){ // Piece can be rotated

            rotate_piece(piece, 3-i); // Rotate piece
            piece.current_state = next_state; // Update state
            return;
        }
    }
}

static void rotate_piece(Piece &piece, int rotations){

    static Piece tmp_piece;

    switch (rotations){ // Load temporary place-holder piece

        case 1: // 90 degrees clockwise

            for(int i = 0; i < piece.size; i++){
                for(int j = 0; j < piece.size; j++){
                    tmp_piece.grid[i][j] = piece.grid[piece.size - j - 1][i];
                }
            }
        break;

        case 2: // 180 degrees clockwise

            for(int i = 0; i < piece.size; i++){
                for(int j = 0; j < piece.size; j++){
                    tmp_piece.grid[i][j] = piece.grid[piece.size - i - 1][piece.size - j - 1];
                }
            }
        break;

        case 3: // 270 degrees clockwise

            for(int i = 0; i < piece.size; i++){
                for(int j = 0; j < piece.size; j++){
                    tmp_piece.grid[i][j] = piece.grid[j][piece.size - i - 1];
                }
            }
        break;
    }

    // Propogate placeholder-grid to piece-grid
    for(int i = 0; i < piece.size; i++){
        for(int j = 0; j < piece.size; j++){
            piece.grid[i][j] = tmp_piece.grid[i][j];
        }
    }
}

void draw_piece(Piece piece, int x, int y, int sqr_size){

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