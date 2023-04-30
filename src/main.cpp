#include <iostream>
#include <string>
#include "board.h"
#include "notation.h"
#include "render.h"

int main(void) {
  std::string funny_position =
      "rnbq1bnr/ppppkppp/8/4p3/4P3/8/PPPPKPPP/RNBQ1BNR";
  Board board = board_from_FEN(funny_position);
  board.print();

  std::string white_pawn_svg = load_svg("./assets/Chess_plt45.svg");
  std::cout << white_pawn_svg << std::endl;
}
