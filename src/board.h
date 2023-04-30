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
bool is_white(Piece piece);
bool is_none(Piece piece);
bool is_valid_algebraic_notation(std::string notation);
size_t algebraic_to_index(std::string notation);
void put_piece(Board* board, Piece piece, size_t index);
