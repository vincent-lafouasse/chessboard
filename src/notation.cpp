#include "notation.h"
#include <cctype>
#include <iostream>
#include "board.h"

static bool is_valid_piece_notation(char piece);
static bool is_valid_file(char file);
static bool is_valid_rank(char rank);

size_t algebraic_to_index(std::string notation) {
  if (!is_valid_algebraic_notation(notation)) {
    std::cout << "Invalid notation : " + notation << std::endl;
    exit(1);
  }
  char file = notation[0];
  char rank = notation[1];
  file -= 'a';
  char rank_from_top = '8' - rank;

  return file + 8 * rank_from_top;
}

Piece piece_from_notation(char piece) {
  if (!is_valid_piece_notation(piece)) {
    std::cout << "Invalid piece: " + std::string(1, piece) << std::endl;
    exit(1);
  }

  Piece color = isupper(piece) ? White : Black;
  piece = toupper(piece);
  switch (piece) {
    case 'P': {
      return Pawn | color;
    }
    case 'B': {
      return Bishop | color;
    }
    case 'N': {
      return Knight | color;
    }
    case 'R': {
      return Rook | color;
    }
    case 'Q': {
      return Queen | color;
    }
    case 'K': {
      return King | color;
    }
    default: {
      std::cout << "Invalid piece: " + std::string(1, piece) << std::endl;
      exit(1);
    }
  }
}

static bool is_valid_piece_notation(char piece) {
  piece = toupper(piece);
  return (piece == 'P') || (piece == 'B') || (piece == 'N') || (piece == 'R') ||
         (piece == 'Q') || (piece == 'K');
}

static bool is_valid_file(char file) {
  return file >= 'a' && file <= 'h';
}
static bool is_valid_rank(char rank) {
  return rank >= '1' && rank <= '8';
}

bool is_valid_algebraic_notation(std::string notation) {
  char file = notation[0];
  char rank = notation[1];

  if (!is_valid_file(file)) {
    std::cout << "Invalid file: " + std::string(1, file) << std::endl;
    exit(1);
  }
  if (!is_valid_rank(rank)) {
    std::cout << "Invalid rank: " + std::string(1, rank) << std::endl;
    exit(1);
  }
  return true;
}
