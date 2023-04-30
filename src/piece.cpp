#include "piece.h"
#include <cctype>

Piece base_piece(Piece piece) {
  return piece % 8;
}

bool is_white(Piece piece) {
  return (piece & WHITE) == WHITE;
}

bool is_none(Piece piece) {
  return base_piece(piece) == NONE;
}

char piece_repr(Piece piece) {
  char output;
  switch (base_piece(piece)) {
    case NONE: {
      output = '.';
      break;
    }
    case PAWN: {
      output = 'P';
      break;
    }
    case BISHOP: {
      output = 'B';
      break;
    }
    case KNIGHT: {
      output = 'N';
      break;
    }
    case ROOK: {
      output = 'R';
      break;
    }
    case QUEEN: {
      output = 'Q';
      break;
    }
    case KING: {
      output = 'K';
      break;
    }
  }

  if (!is_none(piece) && !is_white(piece)) {
    output = tolower(output);
  }
  return output;
}
