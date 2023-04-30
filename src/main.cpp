#include <iostream>
#include <string>
#include "board.h"
#include "notation.h"

int main(void) {
  std::string after_e4 = "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR";
  Board board = board_from_FEN(after_e4);
  print_board(board);
}
