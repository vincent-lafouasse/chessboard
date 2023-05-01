#include "render.h"
#include <iostream>
#include <unordered_map>
#include "piece.h"

static void render_empty_chessboard(Palette palette, SDL_Renderer* renderer);
static void render_column(int col,
                          Color first_color,
                          Color second_color,
                          SDL_Renderer* renderer);

static SDL_Texture* get_writable_texture(const int width,
                                         const int height,
                                         SDL_Renderer* renderer);
static void set_as_render_target(SDL_Texture* texture, SDL_Renderer* renderer);
static void reset_render_target(SDL_Renderer* renderer);

// -----------------------------------------------------------------------------

SDL_Texture* make_static_board_texture(const Palette palette,
                                       SDL_Renderer* renderer) {
  constexpr int width = SQUARE_SIZE * 8;
  constexpr int height = SQUARE_SIZE * 8;

  SDL_Texture* static_board_texture =
      get_writable_texture(width, height, renderer);
  set_as_render_target(static_board_texture, renderer);

  render_empty_chessboard(palette, renderer);

  reset_render_target(renderer);

  return static_board_texture;
}

static void render_empty_chessboard(Palette palette, SDL_Renderer* renderer) {
  for (int col = 0; col < 8; col++) {
    if (col % 2 == 0) {
      render_column(col, palette.white, palette.dark, renderer);
    } else {
      render_column(col, palette.dark, palette.white, renderer);
    }
  }
}

static void render_column(int col,
                          Color first_color,
                          Color second_color,
                          SDL_Renderer* renderer) {
  for (int row = 0; row < 8; row++) {
    SDL_Rect rect = {col * SQUARE_SIZE, row * SQUARE_SIZE, SQUARE_SIZE,
                     SQUARE_SIZE};
    Color color = (row % 2 == 0) ? first_color : second_color;
    set_render_color(color, renderer);
    SDL_RenderFillRect(renderer, &rect);
  }
}

static SDL_Texture* get_writable_texture(const int width,
                                         const int height,
                                         SDL_Renderer* renderer) {
  SDL_Texture* writable_texture =
      SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                        SDL_TEXTUREACCESS_TARGET, width, height);
  if (writable_texture == NULL) {
    printf("Unable to create writable texture, %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  return writable_texture;
}

static void set_as_render_target(SDL_Texture* texture, SDL_Renderer* renderer) {
  if (SDL_SetRenderTarget(renderer, texture) != 0) {
    printf("Unable to set texture as render target, %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
}

static void reset_render_target(SDL_Renderer* renderer) {
  if (SDL_SetRenderTarget(renderer, NULL) != 0) {
    printf(
        "unable to stop rendering to a texture and render to the window again, "
        "%s\n",
        SDL_GetError());
    exit(EXIT_FAILURE);
  }
}

void init_SDL(SDL_Window** return_window, SDL_Renderer** return_renderer) {
  constexpr int SCREEN_X_POS = 0;
  constexpr int SCREEN_Y_POS = 0;
  constexpr int SCREEN_WIDTH = 8 * SQUARE_SIZE;
  constexpr int SCREEN_HEIGHT = 8 * SQUARE_SIZE;

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

struct RGB {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};

const std::unordered_map<Color, RGB> COLOR_TO_RGB = {
    {Color::White, {255, 255, 255}},
    {Color::Black, {0, 0, 0}},
    {Color::MossGreen, {118, 150, 86}},
    {Color::Eggshell, {238, 238, 210}},
};

void set_render_color(Color color, SDL_Renderer* renderer) {
  RGB rgb = COLOR_TO_RGB.at(color);
  constexpr uint8_t alpha = 255;

  SDL_SetRenderDrawColor(renderer, rgb.red, rgb.green, rgb.blue, alpha);
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
