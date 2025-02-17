#include <iostream>
#include <optional>

#include "color.h"
#include "ray.h"
#include "surface.h"
#include "vec3.h"
#include "viewport.h"

double hit_sphere(const sf::Vec3& center, double radius, const sf::Ray& r) {
  sf::Vec3 oc = r.point() - center;
  auto a = r.direction().dot(r.direction());
  auto b = 2.0 * oc.dot(r.direction());
  auto c = oc.dot(oc) - radius * radius;
  auto discriminant = b * b - 4 * a * c;
  if(discriminant < 0) {
    return -1;
  } else {
    return (-b - std::sqrt(discriminant)) / (2.0 * a);
  }
}

sf::Color ray_color(const sf::Ray& r) {
  double t = hit_sphere(sf::Vec3(0, 0, -1), 0.5, r);
  if (t > 0) {
    sf::Vec3 N = (r.at(t) - sf::Vec3(0, 0, -1)).normalize();
    return sf::Color(N.x() + 1, N.y() + 1, N.z() + 1) * 0.5;
  }
  sf::Vec3 unit_direction = r.direction().normalize();
  auto a = 0.5 * (unit_direction.y() + 1.0);
  return sf::Color(1.0, 1.0, 1.0) * (1.0 - a) + sf::Color(0.5, 0.7, 1.0) * a;
}

int main() {
  sf::Surface surface(800, 600);
  sf::Viewport viewport(800, 600, 1.0);
  for (int i = 0; i < 600; i++) {
    for (int j = 0; j < 800; j++) {
      auto pixel_pos = viewport.getPixelPos(j, i);
      sf::Ray ray(sf::Vec3(0, 0, 0), pixel_pos);
      auto color = ray_color(ray);
      surface.setPixel(j, i, 255 * color[0], 255 * color[1], 255 * color[2]);
    }
  }
  surface.save("1.ppm");
}