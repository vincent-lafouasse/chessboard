#pragma once

#include <array>
#include "piece.h"

#define N_SQUARES 64

typedef std::array<Piece, 64> Board;

Board new_board(void);
void print_board(Board board);
void put_piece(Board* board, Piece piece, size_t index);
