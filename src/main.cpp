#include <iostream>

#include <shape.hpp>
#include <screen.hpp>
#include <writer.hpp>

signed main(int argc, char *argv[]) {
  triangle_t<int> t1(
    point_t<int>(3, 3), point_t<int> (7, 9), point_t<int> (13, 5),
    color_t(255, 153, 153)
  );

  triangle_t<int> t2(
    point_t<int>(2, 7), point_t<int> (7, 1), point_t<int> (10, 9),
    color_t(138, 255, 255)
  );

  std::vector<triangle_t<int>> triangles = {t1, t2};

  screen_t screen(20, 20);
  for(auto t: triangles) {
    for(int i=1; i<=20; ++i) {
      for(int j=1; j<=20; ++j) {
        point_t<int> p(i, j);
        if(t.inside(p)) {
          screen.set_pixel(i, j, t.color);
        }
      }
    }
  }
  
  screen.set_pixel(3, 3, color_t(255, 153, 153));

  write_screen("./out/output.ppm", screen);

  return 0;
}