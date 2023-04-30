#pragma once

#include <array>
#include "piece.h"

#define N_SQUARES 64

class Board {
 public:
  Board();
  void print(void);
  void put_piece(Piece piece, size_t index);

 private:
  std::array<Piece, 64> squares;
};
