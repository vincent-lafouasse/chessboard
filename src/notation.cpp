#include "notation.h"
#include <iostream>

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
