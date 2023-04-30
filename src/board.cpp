#include "board.h"
#include <iostream>

void put_piece(Board* board, Piece piece, size_t index) {
  board->at(index) = piece;
}

Board new_board(void) {
  Board board;
  board.fill(NONE);
  return board;
}

void print_board(Board board) {
  for (int i = 0; i < N_SQUARES; i++) {
    std::cout << piece_repr(board[i]);
    if ((i + 1) % 8 == 0) {
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
}
