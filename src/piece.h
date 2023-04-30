#include <stdint.h>

typedef uint8_t Piece;

enum {
  NONE = 0,
  PAWN = 1,
  BISHOP = 2,
  KNIGHT = 3,
  ROOK = 4,
  QUEEN = 5,
  KING = 6,
  WHITE = 8,
  BLACK = 16,
};

Piece base_piece(Piece piece);
bool is_white(Piece piece);
bool is_none(Piece piece);
char piece_repr(Piece piece);
