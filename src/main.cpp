#include <iostream>

enum Piece {
  Pawn = 0,
  Bishop = 1,
  Knight = 2,
  Rook = 3,
  Queen = 4,
  King = 5,
  White = 8,
  Black = 16,
};

int main(void) {
  std::cout << (Bishop | White) << std::endl;
}
