#include <iostream>
#include <string>
#include "board.h"

int main(void) {
  Board board = new_board();
  put_piece(&board, White | Pawn, algebraic_to_index("e4"));
  put_piece(&board, Black | Pawn, algebraic_to_index("e5"));
  put_piece(&board, White | Knight, algebraic_to_index("c3"));
  put_piece(&board, Black | Knight, algebraic_to_index("f6"));
  print_board(board);
}
