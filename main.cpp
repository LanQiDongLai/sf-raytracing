#include <iostream>
#include <optional>

#include "color.h"
#include "ray.h"
#include "surface.h"
#include "vec3.h"
#include "viewport.h"
#include "object/hit_record.h"
#include "object/hittable.h"
#include "object/hittable_list.h"
#include "object/sphere.h"

double hit_sphere(const sf::Vec3& center, double radius, const sf::Ray& r) {
  sf::Vec3 oc = r.point() - center;
  auto a = r.direction().dot(r.direction());
  auto half_b = oc.dot(r.direction());
  auto c = oc.dot(oc) - radius * radius;
  auto discriminant = half_b * half_b - a * c;
  if(discriminant < 0) {
    return -1;
  } else {
    return (-half_b - std::sqrt(discriminant)) / a;
  }
}

sf::Color ray_color(const sf::Ray& r, const sf::Hittable& world) {
    // shading with surface normals
    sf::HitRecord rec;
    if (world.hit(r, 0, std::numeric_limits<double>::infinity(), rec)) {
        return (sf::Color(1, 1, 1) + rec.normal) * 0.5;
    }
    
    sf::Vec3 unit_direction = r.direction().normalize();
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return sf::Color(1.0, 1.0, 1.0) * (1.0 - a) + sf::Color(0.5, 0.7, 1.0) * a;
}

int main() {
  sf::Surface surface(800, 600);
  sf::Viewport viewport(800, 600, 1.0);
  sf::HittableList world;
  world.add(std::make_shared<sf::Sphere>(sf::Point(0, 0, -1), 0.5));
  world.add(std::make_shared<sf::Sphere>(sf::Point(0, -100.5, -1), 100));

  for (int i = 0; i < 600; i++) {
    for (int j = 0; j < 800; j++) {
      auto pixel_pos = viewport.getPixelPos(j, i);
      sf::Ray ray(sf::Vec3(0, 0, 0), pixel_pos);
      auto color = ray_color(ray, world);
      surface.setPixel(j, i, 255 * color[0], 255 * color[1], 255 * color[2]);
    }
  }
  surface.save("1.ppm");
}