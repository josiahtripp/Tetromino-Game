#include "pieces.h"

/**
 * @brief Rotates a piece clockwise to any rotational-position
 * 
 * @param piece The piece to rotate
 * @param rotations The number of 90 degree rotations to apply to the piece
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
        }
    }
}

void rotate_piece_ccw(Piece &piece){


}

static void rotate_piece(Piece &piece, int rotations){

    static Piece tmp_piece;

    switch (rotations){ // Load temporary place-holder piece

        case 0:

            for(int i = 0; i < piece.size; i++){
                for(int j = 0; j < piece.size; j++){
                    tmp_piece.grid[i][j] = 
                        piece.grid[piece.size - j - 1][i];
                }
            }

        break;

        case 1:

        break;

        case 2:

        break;
    }
}