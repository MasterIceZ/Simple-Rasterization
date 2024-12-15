#ifndef __COLOR_H_INCLUDED__
#define __COLOR_H_INCLUDED__

struct color_t {
  int r, g, b;
  color_t(int _r, int _g, int _b):
    r(_r), g(_g), b(_b) {}
  color_t() {}
};

#endif