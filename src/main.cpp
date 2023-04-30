#include <iostream>
#include <string>
#include "board.h"
#include "notation.h"

int main(void) {
  std::string funny_position =
      "rnbq1bnr/ppppkppp/8/4p3/4P3/8/PPPPKPPP/RNBQ1BNR";
  Board board = board_from_FEN(funny_position);
  print_board(board);
}
