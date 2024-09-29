#ifndef PIECES_H
#define PIECES_H

#define MAX_SIZE 4 // The maximum piece-grid width & height
#define PIECES_COUNT 7 // The number of pre-defined pieces in game_pieces

/**
 * @brief Encompasses properties for each piece
 * @memberof size The size of the piece grid (length of the size of square)
 * @memberof current_state The currect rotational-state of the piece 
 *                         (default is 0, each successive 90-degree turn clockwise increments 1)
 * @memberof valid_states[] The allowed states of rotation of the piece. 1 = valid, 0 = invalid
 *                          (index n = state n)
 * @memberof grid The grid/array containing the piece. 1 = block, 0 = empty
 */
typedef struct Piece{

    int size;
    int current_state;
    int valid_states[4];
    int grid[MAX_SIZE][MAX_SIZE];
} Piece;

/**
 * @brief Pre-defined (classic) game pieces
 * @def [0] Square piece       ("O" piece)
 * @def [1] Straight bar piece ("I" piece)
 * @def [2] T piece            ("T" piece)
 * @def [3] Backwards L piece  ("J" piece)
 * @def [4] L piece            ("L" piece)
 * @def [5] Backwards Z piece  ("S" piece)
 * @def [6] Z piece            ("Z" piece)
 */
Piece game_pieces[PIECES_COUNT] = {

    {   // Square Piece
        2,
        0,
        {1, 0, 0, 0}, // Only default is valid (rotation is not needed)
        {
            {1, 1},
            {1, 1}
        }
    },
    {   // Straight bar piece
        4,
        0,
        {1, 0, 0, 1}, // Only default & 270-degree rotation valid (flat and standing)
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {1, 1, 1, 1},
            {0, 0, 0, 0}
        }
    },
    {
        // T piece
        3,
        0,
        {1, 1, 1, 1}, // Allow all rotations
        {
            {0, 0, 0},
            {1, 1, 1},
            {0, 0, 0}
        }
    },
    {   // Backwards L piece
        3,
        0,
        {1, 1, 1, 1}, // Allow all rotations
        {
            {0, 0, 0},
            {1, 1, 1},
            {0, 0, 1}
        }
    },
    {   // L piece
        3,
        0,
        {1, 1, 1, 1}, // Allow all rotations
        {
            {0, 0, 0},
            {1, 1, 1},
            {1, 0, 0}
        }
    },
    {
        // Backwards Z piece
        3,
        0,
        {1, 0, 0, 1}, // Only default & 270-degree rotation valid (flat and standing)
        {
            {0, 0, 0},
            {0, 1, 1},
            {1, 1, 0}
        }
    },
    {
        // Z piece
        3,
        0,
        {1, 0, 0, 1}, // Only default & 270-degree rotation valid (flat and standing)
        {
            {0, 0, 0},
            {1, 1, 0},
            {0, 1, 1}
        }
    }
};

/**
 * @brief Rotates a piece clockwise to its next valid state
 * 
 * @param piece The piece to rotate (passed by reference, modifies piece)
 */
void rotate_piece_cw(Piece &piece);

/**
 * @brief Rotates a piece counter-clockwise to its next value
 * 
 * @param piece The piece to rotate (passed by reference, modifies pieces)
 */
void rotate_piece_ccw(Piece &piece);

#endif