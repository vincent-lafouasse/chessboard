#include "board.h"
#include <iostream>

Board new_board(void) {
  Board board;
  for (int i = 0; i < N_SQUARES; i++) {
    board[i] = None;
  }
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

char piece_repr(Piece piece) {
  char output;
  switch (piece % 8) {
    case None: {
      output = '.';
      break;
    }
    case Pawn: {
      output = 'P';
      break;
    }
    case Bishop: {
      output = 'B';
      break;
    }
    case Knight: {
      output = 'N';
      break;
    }
    case Rook: {
      output = 'R';
      break;
    }
    case Queen: {
      output = 'Q';
      break;
    }
    case King: {
      output = 'K';
      break;
    }
  }

  if (piece % 8 != None && (piece | White) != White) {
    output += 32;
  }
  return output;
}
