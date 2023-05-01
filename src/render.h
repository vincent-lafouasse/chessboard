#pragma once

#include <SDL2/SDL.h>
#include <string>

#define SQUARE_SIZE 64

enum class Color { Black, White, MossGreen, Eggshell };

struct RGB {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};

void init_SDL(SDL_Window** return_window, SDL_Renderer** return_renderer);
void set_render_color(Color color, SDL_Renderer* renderer);
std::string load_svg(std::string path);
