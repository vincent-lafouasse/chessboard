#pragma once

#include <string>
#include "board.h"

Board board_from_FEN(std::string FEN);
bool is_valid_algebraic_notation(std::string notation);
size_t algebraic_to_index(std::string notation);
Piece piece_from_notation(char piece);
