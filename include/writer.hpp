#ifndef __WRITER_HPP_INCLUDED__
#define __WRITER_HPP_INCLUDED__

#include <string>
#include <fstream>

#include <screen.hpp>

void write_screen(std::string filename, screen_t screen) {
  std::ofstream file(filename);
  file << "P3" << std::endl;
  file << screen.width << " " << screen.height << " 255" << std::endl;
  for(int i=1; i<=screen.height; ++i) {
    for(int j=1; j<=screen.width; ++j) {
      color_t color = screen.get_pixel(i, j);
      file << color.r << " " << color.g << " " << color.b << std::endl;
    }
  }
}

#endif