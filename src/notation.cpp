#include "notation.h"
#include <cctype>
#include <iostream>
#include <unordered_map>

std::unordered_map<char, Piece> CHAR_TO_PIECE = {
    {'P', PAWN | WHITE}, {'B', BISHOP | WHITE}, {'N', KNIGHT | WHITE},
    {'R', ROOK | WHITE}, {'Q', QUEEN | WHITE},  {'K', KING | WHITE},
    {'p', PAWN | BLACK}, {'b', BISHOP | BLACK}, {'n', KNIGHT | BLACK},
    {'r', ROOK | BLACK}, {'q', QUEEN | BLACK},  {'k', KING | BLACK},

};

static bool is_valid_piece_notation(char piece);
static bool is_valid_file(char file);
static bool is_valid_rank(char rank);
static bool is_valid_algebraic_notation(std::string notation);

Board board_from_FEN(std::string FEN) {
  Board board = Board();
  size_t board_idx = 0;
  size_t str_idx = 0;

  while (board_idx < N_SQUARES && str_idx < FEN.size()) {
    if (FEN[str_idx] == '/') {
      str_idx++;
      continue;
    }
    if (isdigit(FEN[str_idx])) {
      board_idx += FEN[str_idx] - '0';
      str_idx++;
      continue;
    }
    board.put_piece(piece_from_notation(FEN[str_idx]), board_idx);
    board_idx++;
    str_idx++;
  }
  return board;
}

Square algebraic_to_square(std::string notation) {
  if (!is_valid_algebraic_notation(notation)) {
    std::cout << "Invalid notation : " + notation << std::endl;
    exit(1);
  }
  char column = notation[0] - 'a';
  char row = '8' - notation[1];
  Square square;
  square.row = row;
  square.column = column;
  return square;
}

Piece piece_from_notation(char piece) {
  if (!is_valid_piece_notation(piece)) {
    std::cout << "Invalid piece: " + std::string(1, piece) << std::endl;
    exit(1);
  }
  return CHAR_TO_PIECE[piece];
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

static bool is_valid_algebraic_notation(std::string notation) {
  char file = notation[0];
  char rank = notation[1];

  if (!is_valid_file(file)) {
    std::cout << "Invalid file: " + std::string(1, file) + " in expression " +
                     notation
              << std::endl;
    exit(1);
  }
  if (!is_valid_rank(rank)) {
    std::cout << "Invalid rank: " + std::string(1, rank) + " in expression " +
                     notation
              << std::endl;
    exit(1);
  }
  return true;
}
