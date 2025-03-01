#include "camera.h"

namespace sf {

const int Camera::surface_width = 800;
const int Camera::surface_height = 600;

Camera::Camera()
    : surface(surface_width, surface_height),
      viewport(surface_width, surface_height, 1.0) {}

void Camera::render(const sf::Hittable& world) {
  for (int i = 0; i < 600; i++) {
    for (int j = 0; j < 800; j++) {
      auto pixel_pos = viewport.getPixelPos(j, i);
      Ray ray(Vec3(0, 0, 0), pixel_pos);
      auto color = ray_color(ray, world);
      surface.setPixel(j, i, 255 * color[0], 255 * color[1], 255 * color[2]);
    }
  }
  surface.save("1.ppm");
}

Color Camera::ray_color(const Ray& r, const Hittable& world) {
  HitRecord rec;
  if (world.hit(r, 0, std::numeric_limits<double>::infinity(), rec)) {
      return (Color(1, 1, 1) + rec.normal) * 0.5;
  }
  
  Vec3 unit_direction = r.direction().normalize();
  auto a = 0.5 * (unit_direction.y() + 1.0);
  return Color(1.0, 1.0, 1.0) * (1.0 - a) + Color(0.5, 0.7, 1.0) * a;
}

}