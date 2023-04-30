#include <stdint.h>

typedef uint8_t Piece;

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

bool is_white(Piece piece);
bool is_none(Piece piece);
char piece_repr(Piece piece);
