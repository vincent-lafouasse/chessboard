#pragma once

#include <stdint.h>

#define NONE 0b000
#define PAWN 0b001
#define BISHOP 0b010
#define KNIGHT 0b011
#define ROOK 0b100
#define QUEEN 0b101
#define KING 0b110

#define WHITE 0b01000
#define BLACK 0b10000

typedef uint8_t Piece;

Piece base_piece(Piece piece);
bool is_white(Piece piece);
bool is_none(Piece piece);
char piece_repr(Piece piece);
