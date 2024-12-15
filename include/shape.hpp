#ifndef __SHAPE_HPP_INCLUDED__
#define __SHAPE_HPP_INCLUDED__

#include <color.hpp>

template<typename T>
struct point_t {
  T x, y;

  point_t(T _x, T _y):
    x(_x), y(_y) {}
  point_t() {}

  bool operator < (const point_t& o) const {
    if(x != o.x) {
      return x < o.x;
    }
    return y < o.y;
  }

  bool operator == (const point_t& o) const {
    return x == o.x && y == o.y;
  }
};

template<typename T>
struct triangle_t {
  point_t<T> a, b, c;
  color_t color;

  triangle_t(point_t<T> _a, point_t<T> _b, point_t<T> _c, color_t _color):
    a(_a), b(_b), c(_c), color(_color) {} 

  double area_times2() {
    // shoelace formula
    return abs(
      a.x * b.y - a.y * b.x +
      b.x * c.y - b.y * c.x +
      c.x * a.y - c.y * a.x
    );
  }

  bool inside(point_t<T> p) {
    if(p == a || p == b || p == c) {
      return true;
    }
    triangle_t<T> abp(a, b, p, color);
    triangle_t<T> bcp(b, c, p, color);
    triangle_t<T> cap(c, a, p, color);
    double total_area = area_times2();
    if(abp.area_times2() + bcp.area_times2() + cap.area_times2() == total_area) {
      return true;
    }
    return false;
  }
};

#endif 