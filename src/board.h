#include <stdint.h>
#include <array>

#define N_SQUARES 64

typedef uint8_t Piece;
typedef std::array<Piece, 64> Board;

enum {
  None = 0,
  Pawn = 1,
  Bishop = 2,
  Knight = 3,
  Rook = 4,
  Queen = 5,
  King = 6,
  White = 8,
  Black = 16,
};

Board new_board(void);
void print_board(Board board);
char piece_repr(Piece piece);
