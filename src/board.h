#pragma once

#include <array>
#include "piece.h"

#define N_SQUARES 64

struct Square {
  size_t row;
  size_t column;
};

class Board {
 public:
  Board();
  void put_piece(Piece piece, size_t index);
  Piece at(size_t index);
  void print(void);

 private:
  std::array<Piece, 64> squares;
};

size_t square_to_index(Square square);
Square index_to_square(size_t index);
