#pragma once

#include <string>

#include "board.h"

Board board_from_FEN(std::string FEN);
Square algebraic_to_square(std::string notation);
Piece piece_from_notation(char piece);
