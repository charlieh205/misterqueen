#ifndef BB_H
#define BB_H

enum
{
    HASH_EP_SIZE       = 8,
    HASH_CASTLE_SIZE   = 16,
    BB_BOARD_SIZE      = 64,
    ATTACK_BISHOP_SIZE = 5248,
    ATTACK_ROOK_SIZE   = 102400,
};

#define BIT(sq)        (1L << (sq))
#define RF(rank, file) ((rank) * 8 + (file))

#define LSB(x)  (__builtin_ctzll(x))
#define MSB(x)  (__builtin_clzll(x))
#define BITS(x) (__builtin_popcountll(x))

#define POP_LSB(b, x)                                                                                                  \
    (b)  = LSB((x));                                                                                                   \
    (x) &= ~BIT(b);
#define POP_MSB(b, x)                                                                                                  \
    (b)  = MSB((x));                                                                                                   \
    (x) &= ~BIT((b));

#define RANK_1 0x00000000000000ffL
#define RANK_2 0x000000000000ff00L
#define RANK_3 0x0000000000ff0000L
#define RANK_4 0x00000000ff000000L
#define RANK_5 0x000000ff00000000L
#define RANK_6 0x0000ff0000000000L
#define RANK_7 0x00ff000000000000L
#define RANK_8 0xff00000000000000L

#define FILE_A 0x0101010101010101L
#define FILE_B 0x0202020202020202L
#define FILE_C 0x0404040404040404L
#define FILE_D 0x0808080808080808L
#define FILE_E 0x1010101010101010L
#define FILE_F 0x2020202020202020L
#define FILE_G 0x4040404040404040L
#define FILE_H 0x8080808080808080L

typedef unsigned long long bb;

// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)
extern bb BB_KNIGHT[BB_BOARD_SIZE];
extern bb BB_KING[BB_BOARD_SIZE];

extern bb BB_BISHOP_6[BB_BOARD_SIZE];
extern bb BB_ROOK_6[BB_BOARD_SIZE];

extern const bb MAGIC_BISHOP[BB_BOARD_SIZE];
extern const bb MAGIC_ROOK[BB_BOARD_SIZE];

extern const int SHIFT_BISHOP[BB_BOARD_SIZE];
extern const int SHIFT_ROOK[BB_BOARD_SIZE];

extern int OFFSET_BISHOP[BB_BOARD_SIZE];
extern int OFFSET_ROOK[BB_BOARD_SIZE];

extern bb ATTACK_BISHOP[ATTACK_BISHOP_SIZE];
extern bb ATTACK_ROOK[ATTACK_ROOK_SIZE];

extern bb HASH_WHITE_PAWN[BB_BOARD_SIZE];
extern bb HASH_BLACK_PAWN[BB_BOARD_SIZE];
extern bb HASH_WHITE_KNIGHT[BB_BOARD_SIZE];
extern bb HASH_BLACK_KNIGHT[BB_BOARD_SIZE];
extern bb HASH_WHITE_BISHOP[BB_BOARD_SIZE];
extern bb HASH_BLACK_BISHOP[BB_BOARD_SIZE];
extern bb HASH_WHITE_ROOK[BB_BOARD_SIZE];
extern bb HASH_BLACK_ROOK[BB_BOARD_SIZE];
extern bb HASH_WHITE_QUEEN[BB_BOARD_SIZE];
extern bb HASH_BLACK_QUEEN[BB_BOARD_SIZE];
extern bb HASH_WHITE_KING[BB_BOARD_SIZE];
extern bb HASH_BLACK_KING[BB_BOARD_SIZE];
extern bb HASH_CASTLE[HASH_CASTLE_SIZE];
extern bb HASH_EP[HASH_EP_SIZE];
extern bb HASH_COLOR;
// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)

void bb_init (void);
void bb_print (bb value);
bb   bb_random (void);

bb bb_bishop (int square, bb obstacles);
bb bb_rook (int square, bb obstacles);
bb bb_queen (int square, bb obstacles);

#endif
