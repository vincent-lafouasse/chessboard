#include "piece.h"
#include <cctype>

Piece base_piece(Piece piece) {
  return piece % 8;
}

bool is_white(Piece piece) {
  return (piece & White) == White;
}

bool is_none(Piece piece) {
  return base_piece(piece) == None;
}

char piece_repr(Piece piece) {
  char output;
  switch (base_piece(piece)) {
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
    output = tolower(output);
  }
  return output;
}
