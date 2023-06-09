#include "board.h"

#include <iostream>

void Board::put_piece(Piece piece, size_t index) {
  squares.at(index) = piece;
}

Board::Board(void) {
  squares.fill(NONE);
}

size_t square_to_index(Square square) {
  return square.column + 8 * square.row;
}

Square index_to_square(size_t index) {
  Square square;
  square.column = index % 8;
  square.row = index / 8;
  return square;
}

Piece Board::at(size_t index) const {
  return squares.at(index);
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
