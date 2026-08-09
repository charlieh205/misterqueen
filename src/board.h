#ifndef BOARD_H
#define BOARD_H

#include "bb.h"

enum
{
    // Board geometry
    BOARD_RANKS              = 8,
    BOARD_FILES              = 8,
    BOARD_SQUARE_COUNT       = BOARD_RANKS * BOARD_FILES,
    BOARD_SIDE_TO_MOVE_SLOTS = 1,
    BOARD_CASTLE_SLOTS       = 4,
    BOARD_ARRAY_SIZE         = BOARD_SQUARE_COUNT + BOARD_SIDE_TO_MOVE_SLOTS + BOARD_CASTLE_SLOTS,

    // Board colors
    BOARD_WHITE = 0x00,
    BOARD_BLACK = 0x10,

    // Generic pieces
    BOARD_EMPTY  = 0x00,
    BOARD_PAWN   = 0x01,
    BOARD_KNIGHT = 0x02,
    BOARD_BISHOP = 0x03,
    BOARD_ROOK   = 0x04,
    BOARD_QUEEN  = 0x05,
    BOARD_KING   = 0x06,

    // White pieces
    BOARD_WHITE_PAWN   = 0x01,
    BOARD_WHITE_KNIGHT = 0x02,
    BOARD_WHITE_BISHOP = 0x03,
    BOARD_WHITE_ROOK   = 0x04,
    BOARD_WHITE_QUEEN  = 0x05,
    BOARD_WHITE_KING   = 0x06,

    // Black pieces
    BOARD_BLACK_PAWN   = 0x11,
    BOARD_BLACK_KNIGHT = 0x12,
    BOARD_BLACK_BISHOP = 0x13,
    BOARD_BLACK_ROOK   = 0x14,
    BOARD_BLACK_QUEEN  = 0x15,
    BOARD_BLACK_KING   = 0x16,

    // Bit values of Board.castle, in order encoders peel them off
    BOARD_CASTLE_MASK_NONE        = 0,
    BOARD_CASTLE_MASK_WHITE_KING  = 1,
    BOARD_CASTLE_MASK_WHITE_QUEEN = 2,
    BOARD_CASTLE_MASK_WHITE       = 3,
    BOARD_CASTLE_MASK_BLACK_KING  = 4,
    BOARD_CASTLE_MASK_BLACK_QUEEN = 8,
    BOARD_CASTLE_MASK_BLACK       = 12,
    BOARD_CASTLE_MASK_ALL         = 15,

    // Material values of pieces on board
    BOARD_MATERIAL_PAWN   = 100,
    BOARD_MATERIAL_KNIGHT = 320,
    BOARD_MATERIAL_BISHOP = 330,
    BOARD_MATERIAL_ROOK   = 500,
    BOARD_MATERIAL_QUEEN  = 900,
    BOARD_MATERIAL_KING   = 20000
};

#define PIECE(x) ((x) & 0x0f)
#define COLOR(x) ((x) & 0x10)

extern const int BOARD_POSITION_WHITE_PAWN[BOARD_SQUARE_COUNT];
extern const int BOARD_POSITION_WHITE_KNIGHT[BOARD_SQUARE_COUNT];
extern const int BOARD_POSITION_WHITE_BISHOP[BOARD_SQUARE_COUNT];
extern const int BOARD_POSITION_WHITE_ROOK[BOARD_SQUARE_COUNT];
extern const int BOARD_POSITION_WHITE_QUEEN[BOARD_SQUARE_COUNT];
extern const int BOARD_POSITION_WHITE_KING[BOARD_SQUARE_COUNT];
extern const int BOARD_POSITION_BLACK_PAWN[BOARD_SQUARE_COUNT];
extern const int BOARD_POSITION_BLACK_KNIGHT[BOARD_SQUARE_COUNT];
extern const int BOARD_POSITION_BLACK_BISHOP[BOARD_SQUARE_COUNT];
extern const int BOARD_POSITION_BLACK_ROOK[BOARD_SQUARE_COUNT];
extern const int BOARD_POSITION_BLACK_QUEEN[BOARD_SQUARE_COUNT];
extern const int BOARD_POSITION_BLACK_KING[BOARD_SQUARE_COUNT];

typedef struct
{
    int squares[BOARD_SQUARE_COUNT];
    int color;
    int castle;
    int white_material;
    int black_material;
    int white_position;
    int black_position;
    bb  ep;
    bb  all;
    bb  white;
    bb  black;
    bb  white_pawns;
    bb  black_pawns;
    bb  white_knights;
    bb  black_knights;
    bb  white_bishops;
    bb  black_bishops;
    bb  white_rooks;
    bb  black_rooks;
    bb  white_queens;
    bb  black_queens;
    bb  white_kings;
    bb  black_kings;
    bb  hash;
    bb  pawn_hash;
} Board;

void board_clear (Board * board);
void board_reset (Board * board);
void board_set (Board * board, int square, int piece);
void board_print (Board * board);
void board_load_fen (Board * board, char * fen);

#endif
