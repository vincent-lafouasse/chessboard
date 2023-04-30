#include "board.h"
#include <iostream>

void put_piece(Board* board, Piece piece, size_t index) {
  board->at(index) = piece;
}

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

bool is_white(Piece piece) {
  return (piece & White) == White;
}

bool is_none(Piece piece) {
  return (piece % 2) == 0;
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

  if (!is_none(piece) && !is_white(piece)) {
    output += 32;
  }
  return output;
}
