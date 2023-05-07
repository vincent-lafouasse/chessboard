#pragma once

#include <string>
#include <unordered_map>

#include <SDL2/SDL.h>

#include "board.h"
#include "piece.h"

#define SQUARE_SIZE 64

enum class Color { Black, White, MossGreen, Eggshell };

struct Palette {
  Color white;
  Color dark;
};

class PieceSet {
 public:
  PieceSet(const std::unordered_map<Piece, std::string>& png_paths,
           SDL_Renderer* renderer);
  ~PieceSet();
  SDL_Texture* get(Piece piece) const;

 private:
  std::unordered_map<Piece, SDL_Texture*> textures;
};

void render_pieces(const Board& board,
                   const PieceSet& piece_set,
                   SDL_Renderer* renderer);
SDL_Texture* make_static_board_texture(const Palette palette,
                                       SDL_Renderer* renderer);
void init_SDL(SDL_Window** return_window, SDL_Renderer** return_renderer);
void set_render_color(Color color, SDL_Renderer* renderer);

constexpr Palette RELAXED_GREEN = {Color::Eggshell, Color::MossGreen};
constexpr Palette BLACK_WHITE = {Color::White, Color::Black};

const std::string PNG_DIR = "./assets/PNG/";

const std::unordered_map<Piece, std::string> PNG_PATHS = {
    {WHITE | PAWN, PNG_DIR + "white_pawn.png"},
    {WHITE | BISHOP, PNG_DIR + "white_bishop.png"},
    {WHITE | KNIGHT, PNG_DIR + "white_knight.png"},
    {WHITE | ROOK, PNG_DIR + "white_rook.png"},
    {WHITE | QUEEN, PNG_DIR + "white_queen.png"},
    {WHITE | KING, PNG_DIR + "white_king.png"},
    {BLACK | PAWN, PNG_DIR + "black_pawn.png"},
    {BLACK | BISHOP, PNG_DIR + "black_bishop.png"},
    {BLACK | KNIGHT, PNG_DIR + "black_knight.png"},
    {BLACK | ROOK, PNG_DIR + "black_rook.png"},
    {BLACK | QUEEN, PNG_DIR + "black_queen.png"},
    {BLACK | KING, PNG_DIR + "black_king.png"},
};
