#include "piece.h"
#include <array>
#include <cctype>

std::array<char, 7> PIECE_REPRS = {'.', 'P', 'B', 'N', 'R', 'Q', 'K'};

Piece base_piece(Piece piece) {
  return piece % 8;
}

bool is_white(Piece piece) {
  return (piece & WHITE) == WHITE;
}

bool is_none(Piece piece) {
  return base_piece(piece) == NONE;
}

char piece_repr(Piece piece) {
  char repr = PIECE_REPRS[base_piece(piece)];
  return is_white(piece) ? repr : tolower(repr);
}
