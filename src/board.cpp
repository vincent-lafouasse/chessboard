#include "board.h"
#include <iostream>

void Board::put_piece(Piece piece, size_t index) {
  squares.at(index) = piece;
}

Board::Board(void) {
  squares.fill(NONE);
}

void Board::print(void) {
  for (int i = 0; i < N_SQUARES; i++) {
    std::cout << piece_repr(squares.at(i));
    if ((i + 1) % 8 == 0) {
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
}
