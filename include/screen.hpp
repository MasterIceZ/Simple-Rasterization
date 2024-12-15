#ifndef __SCREEN_HPP_INCLUDED__
#define __SCREEN_HPP_INCLUDED__

#include <vector>

#include <color.hpp>

struct screen_t {
  int width, height;
  std::vector<std::vector<color_t>> pixels;
  screen_t(int _width, int _height):
    width(_width), height(_height) {
    pixels = std::vector<std::vector<color_t>>(
      height + 1, 
      std::vector<color_t>(width + 1)
    );
  }
  screen_t() {}

  void set_pixel(int x, int y, color_t color) {
    pixels[x][y] = color;
  }

  color_t get_pixel(int x, int y) {
    return pixels[x][y];
  }
};

#endif