#include "render.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include "piece.h"

void render_column(int col,
                   Color first_color,
                   Color second_color,
                   SDL_Renderer* renderer) {
  Color color;

  for (int row = 0; row < 8; row++) {
    SDL_Rect rect = {col * SQUARE_SIZE, row * SQUARE_SIZE, SQUARE_SIZE,
                     SQUARE_SIZE};
    color = (row % 2 == 0) ? first_color : second_color;
    set_render_color(color, renderer);
    SDL_RenderFillRect(renderer, &rect);
  }
}

void render_empty_chessboard(Color dark, Color white, SDL_Renderer* renderer) {
  Color first_color;
  Color second_color;

  for (int col = 0; col < 8; col++) {
    if (col % 2 == 0) {
      first_color = white;
      second_color = dark;
    } else {
      first_color = dark;
      second_color = white;
    }
    render_column(col, first_color, second_color, renderer);
  }
}

void init_SDL(SDL_Window** return_window, SDL_Renderer** return_renderer) {
  const int SCREEN_X_POS = 0;
  const int SCREEN_Y_POS = 0;
  const int SCREEN_WIDTH = 8 * SQUARE_SIZE;
  const int SCREEN_HEIGHT = 8 * SQUARE_SIZE;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  *return_window =
      SDL_CreateWindow("Chess", SCREEN_X_POS, SCREEN_Y_POS, SCREEN_WIDTH,
                       SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
  if (*return_window == NULL) {
    SDL_Log("Could not create a window: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  *return_renderer =
      SDL_CreateRenderer(*return_window, -1, SDL_RENDERER_ACCELERATED);
  if (*return_renderer == NULL) {
    SDL_Log("Could not create a renderer: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }
}

std::unordered_map<Color, RGB> COLOR_TO_RGB = {
    {Color::White, {255, 255, 255}},
    {Color::Black, {0, 0, 0}},
    {Color::MossGreen, {118, 150, 86}},
    {Color::Eggshell, {238, 238, 210}},
};

void set_render_color(Color color, SDL_Renderer* renderer) {
  RGB rgb = COLOR_TO_RGB[color];
  const uint8_t alpha = 255;

  SDL_SetRenderDrawColor(renderer, rgb.red, rgb.green, rgb.blue, alpha);
}

std::string load_svg(std::string path) {
  std::ifstream file_stream(path);
  std::stringstream buffer;
  buffer << file_stream.rdbuf();
  return buffer.str();
}

const std::string ASSETS_DIR = "./assets/";

const std::unordered_map<Piece, std::string> SVG_PATHS = {
    {PAWN | WHITE, ASSETS_DIR + "Chess_plt45.svg"},
    {BISHOP | WHITE, ASSETS_DIR + "Chess_blt45.svg"},
    {KNIGHT | WHITE, ASSETS_DIR + "Chess_nlt45.svg"},
    {ROOK | WHITE, ASSETS_DIR + "Chess_rlt45.svg"},
    {QUEEN | WHITE, ASSETS_DIR + "Chess_qlt45.svg"},
    {KING | WHITE, ASSETS_DIR + "Chess_klt45.svg"},
    {PAWN | BLACK, ASSETS_DIR + "Chess_pdt45.svg"},
    {BISHOP | BLACK, ASSETS_DIR + "Chess_bdt45.svg"},
    {KNIGHT | BLACK, ASSETS_DIR + "Chess_ndt45.svg"},
    {ROOK | BLACK, ASSETS_DIR + "Chess_rdt45.svg"},
    {QUEEN | BLACK, ASSETS_DIR + "Chess_qdt45.svg"},
    {KING | BLACK, ASSETS_DIR + "Chess_kdt45.svg"},
};
