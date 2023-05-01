#pragma once

#include <string>
#include <unordered_map>

#include <SDL2/SDL.h>

#include "piece.h"

#define SQUARE_SIZE 64

enum class Color { Black, White, MossGreen, Eggshell };

struct Palette {
  Color white;
  Color dark;
};

SDL_Texture* make_static_board_texture(const Palette palette,
                                       SDL_Renderer* renderer);
void init_SDL(SDL_Window** return_window, SDL_Renderer** return_renderer);
void set_render_color(Color color, SDL_Renderer* renderer);

constexpr Palette RELAXED_GREEN = {Color::Eggshell, Color::MossGreen};
constexpr Palette BLACK_WHITE = {Color::White, Color::Black};

const std::string PNG_DIR = "./assets/PNG/";

const std::unordered_map<Piece, std::string> PNG_PATHS = {
    {PAWN | WHITE, PNG_DIR + "white_pawn.png"},
    {BISHOP | WHITE, PNG_DIR + "white_bishop.png"},
    {KNIGHT | WHITE, PNG_DIR + "white_knight.png"},
    {ROOK | WHITE, PNG_DIR + "white_rook.png"},
    {QUEEN | WHITE, PNG_DIR + "white_queen.png"},
    {KING | WHITE, PNG_DIR + "white_king.png"},
    {PAWN | BLACK, PNG_DIR + "black_pawn.png"},
    {BISHOP | BLACK, PNG_DIR + "black_bishop.png"},
    {KNIGHT | BLACK, PNG_DIR + "black_knight.png"},
    {ROOK | BLACK, PNG_DIR + "black_rook.png"},
    {QUEEN | BLACK, PNG_DIR + "black_queen.png"},
    {KING | BLACK, PNG_DIR + "black_king.png"},
};
