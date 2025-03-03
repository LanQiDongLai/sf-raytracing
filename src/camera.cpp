#include "camera.h"

#include "utils/math.h"

namespace sf {

const int Camera::surface_width = 800;
const int Camera::surface_height = 600;
const int Camera::samples_per_pixel = 10;
const int Camera::max_depth = 10;

Camera::Camera()
    : surface(surface_width, surface_height),
      viewport(surface_width, surface_height, 1.0) {}

void Camera::render(const sf::Hittable& world) {
  for (int i = 0; i < surface_height; i++) {
    for (int j = 0; j < surface_width; j++) {
      auto color = sample_on_pixel(j, i, world);
      surface.setPixel(j, i, 255 * math::clamp(color[0], 0., 1.),
                       255 * math::clamp(color[1], 0., 1.),
                       255 * math::clamp(color[2], 0., 1.));
    }
  }
  surface.save("1.ppm");
}

Color Camera::ray_color(const Ray& r, int depth, const Hittable& world) {
  if(depth < 0) {
    return Color(0., 0., 0.);
  }
  HitRecord rec;
  if (world.hit(r, 0.01, std::numeric_limits<double>::infinity(), rec)) {
    Vec3 direction = rec.normal + Vec3::random_in_unit_sphere();
    return ray_color(Ray(rec.p, direction), depth - 1, world) * 0.5;
  }

  Vec3 unit_direction = r.direction().normalize();
  auto a = 0.5 * (unit_direction.y() + 1.0);
  return Color(1.0, 1.0, 1.0) * (1.0 - a) + Color(0.5, 0.7, 1.0) * a;
}

Ray Camera::get_ray(int j, int i) {
  auto pixel_pos = viewport.getPixelPos(j + math::random_double(-0.5, 0.5), i + math::random_double(-0.5, 0.5));
  return Ray(Vec3(0, 0, 0), pixel_pos);
}

Color Camera::sample_on_pixel(int j, int i, const sf::Hittable& world) {
  Color final_color(0., 0., 0.);
  for (int k = 0; k < samples_per_pixel; k++) {
    Ray ray = get_ray(j, i);
    auto color = ray_color(ray, max_depth, world);
    final_color += color;
  }
  final_color /= samples_per_pixel;
  return final_color;
}

}  // namespace sf