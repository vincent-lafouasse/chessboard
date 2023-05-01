#pragma once

#include <SDL2/SDL.h>
#include <string>

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
