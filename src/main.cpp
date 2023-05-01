#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "board.h"
#include "notation.h"
#include "render.h"

void cap_fps(uint32_t frame_beginning_tick, int target_fps);

int main(void) {
  const int TARGET_FPS = 60;

  SDL_Window* window = NULL;
  SDL_Renderer* renderer = NULL;
  init_SDL(&window, &renderer);

  SDL_Texture* static_board_texture =
      make_static_board_texture(RELAXED_GREEN, renderer);

  std::string funny_position =
      "rnbq1bnr/ppppkppp/8/4p3/4P3/8/PPPPKPPP/RNBQ1BNR";
  Board board = board_from_FEN(funny_position);
  board.print();

  const char* white_pawn_png_path = PNG_PATHS.at(WHITE | PAWN).c_str();
  SDL_Surface* white_pawn_surface = IMG_Load(white_pawn_png_path);
  SDL_Texture* white_pawn_texture =
      SDL_CreateTextureFromSurface(renderer, white_pawn_surface);

  Square e4 = algebraic_to_square("e4");
  SDL_Rect e4_rect = {e4.column * SQUARE_SIZE, e4.row * SQUARE_SIZE,
                      SQUARE_SIZE, SQUARE_SIZE};

  uint32_t frame_beginning_tick;
  bool running = true;
  while (running) {
    frame_beginning_tick = SDL_GetTicks();
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
        break;
      }
    }

    set_render_color(Color::Eggshell, renderer);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, static_board_texture, NULL, NULL);

    SDL_RenderCopy(renderer, white_pawn_texture, NULL, &e4_rect);

    SDL_RenderPresent(renderer);
    cap_fps(frame_beginning_tick, TARGET_FPS);
  }

  SDL_DestroyTexture(white_pawn_texture);
  SDL_DestroyTexture(static_board_texture);
  SDL_FreeSurface(white_pawn_surface);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return EXIT_SUCCESS;
}

void cap_fps(uint32_t frame_beginning_tick, int target_fps) {
  int ms_per_frame = 1000.0 / target_fps;
  uint32_t frame_end_tick = SDL_GetTicks();
  int time_to_wait = ms_per_frame - (frame_end_tick - frame_beginning_tick);
  SDL_Delay((time_to_wait > 0) * time_to_wait);
}
