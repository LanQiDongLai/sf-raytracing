#include "object/infinite_chess.h"
#include "vec3.h"
#include <cmath>

namespace sf {

InfiniteChess::InfiniteChess(float height, float cell_size,
                             std::shared_ptr<Material> material1,
                             std::shared_ptr<Material> material2)
    : height(height), cell_size(cell_size), material1(material1),
      material2(material2) {}

bool InfiniteChess::hit(const Ray &r, float ray_tmin, float ray_tmax,
                        HitRecord &rec) const {
  auto current_height = r.point()[1];
  auto height_diff = height - current_height;
  auto v = r.direction();
  auto v_y = v[1];
  auto t = height_diff / v_y;
  if (t <= 0) {
    return false;
  }
  v *= t;
  auto chess_x = v[0];
  auto chess_z = v[2];
  if ((chess_x - std::floor(chess_x / cell_size / 2) * cell_size * 2 -
       cell_size) *
          (chess_z - std::floor(chess_z / cell_size / 2) * cell_size * 2 -
           cell_size) <
      0) {
    rec.t = t;
    rec.p = r.at(t);
    rec.normal = height_diff < 0 ? Vec3(0, 1, 0) : Vec3(0, -1, 0);
    rec.material = material1;
  } else {
    rec.t = t;
    rec.p = r.at(t);
    rec.normal = height_diff < 0 ? Vec3(0, 1, 0) : Vec3(0, -1, 0);
    rec.material = material2;
  }
  return true;
}

} // namespace sf