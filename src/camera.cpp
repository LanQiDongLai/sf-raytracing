#include "camera.h"

#include "utils/math.h"

#include "material/material.h"
#include "mat4.h"
#include "sky/monochrome.h"
#include "sky/gradient.h"
#include "utils/threadpool.hpp"

namespace sf {

Camera::Camera()
    : surface_height(200),
      aspect_ratio(16. / 9.),
      samples_per_pixel(10),
      max_depth(50),
      fov(20),
      position(0., 0., 0.),
      up(0., 1., 0.),
      lookat(0., 0., -1.),
      focus_dist(10.),
      defocus_angle(0.6),
      sky(std::make_shared<Gradient>(sf::Color(0.3, 0.5, 1.0), sf::Color(1.0, 1.0, 1.0))) {
}

void Camera::render(const sf::Hittable& world) {
  init();
  ThreadPool pool(4);
  std::vector<std::future<void>> results;
  Surface surface(surface_width, surface_height);
  static int count = 0;
  for (int i = 0; i < surface_height; i++) {
    for (int j = 0; j < surface_width; j++) {
      results.emplace_back(pool.submit([this, &world, &surface, j, i]() {
        auto color = sample_on_pixel(j, i, world);
        surface.setPixel(j, i, 255 * math::clamp(color[0], 0., 1.),
                         255 * math::clamp(color[1], 0., 1.),
                         255 * math::clamp(color[2], 0., 1.));
        count++;
        std::printf("\r%.2f%%", 100. * count / (surface_width * surface_height));
        std::fflush(stdout);
      }));
    }
  }
  for (auto& result : results) {
    result.get();
  }
  surface.save("img.ppm");
}

void Camera::setPosition(const Point& pos) {
  this->position = pos;
}

void Camera::setLookat(const Point& lookat) {
  this->lookat = lookat;
}

void Camera::setUp(const Vec3& up) {
  this->up = up;
}

void Camera::setMaxDepth(int max_depth) {
  this->max_depth = max_depth;
}

void Camera::setSurfaceHeight(int height) {
  this->surface_height = height;
}

void Camera::setFov(double fov) {
  this->fov = fov;
}

void Camera::setMultiSample(int samples_per_pixel) {
  this->samples_per_pixel = samples_per_pixel;
}

void Camera::setDefocusAngle(double defocus_angle) {
  this->defocus_angle = defocus_angle;
}

void Camera::setFocusDist(double focus_dist) {
  this->focus_dist = focus_dist;
}

void Camera::setSky(std::shared_ptr<Sky> sky) {
  this->sky = sky;
}

void Camera::setAspectRadio(double aspect_radio) {
  this->aspect_ratio = aspect_radio;
}

void Camera::init() {
  surface_width = surface_height * aspect_ratio;
  viewport.setFocalLength(focus_dist);
  viewport.setHeight(std::tan(math::degrees_to_radians(fov) / 2) * 2 *
                      focus_dist);
  viewport.setWidth(viewport.getHeight() * aspect_ratio);
  right = (lookat - position).cross(up).normalize();
  front = (lookat - position).normalize();
  up = right.cross(front).normalize();
}

Color Camera::ray_color(const Ray& r, int depth, const Hittable& world) {
  if (depth < 0) {
    return Color(0., 0., 0.);
  }
  HitRecord rec;
  if (world.hit(r, 0.01, std::numeric_limits<double>::infinity(), rec)) {
    Ray r_out;
    Color attenuation;
    auto type = rec.material->scatter(r, rec, attenuation, r_out);
    switch(type) {
      case MaterialType::Luminous:
        return attenuation;
      case MaterialType::NonLuminous:
        return attenuation * ray_color(r_out, depth - 1, world);
      case MaterialType::BlackHole:
        return Color(0., 0., 0.);
    }
  }
  return sky->get_color(r);
}
Ray Camera::get_ray(double j, double i) {
  Vec3 pixel_pos =
      viewport.getPixelPos((j + math::random_double(-0.5, 0.5)) /
                               surface_width * viewport.getWidth(),
                           (i + math::random_double(-0.5, 0.5)) /
                               surface_height * viewport.getHeight());
  Mat4 view_matrix = Mat4(right[0],  up[0], -front[0], 0.,
                          right[1],  up[1], -front[1], 0.,
                          right[2],  up[2], -front[2], 0.,
                          0, 0, 0, 1);
  auto trans_pixel_pos = view_matrix * pixel_pos;
  auto defocus_radius = focus_dist * std::tan(math::degrees_to_radians(defocus_angle / 2));
  auto origin = position + up * math::random_double(-0.5, 0.5) * defocus_radius +
  right * math::random_double(-0.5, 0.5) * defocus_radius;
  trans_pixel_pos = trans_pixel_pos + position - origin;
  return Ray(origin, trans_pixel_pos);
}

Color Camera::sample_on_pixel(double j, double i, const sf::Hittable& world) {
  Color final_color(0., 0., 0.);
  for (int k = 0; k < samples_per_pixel; k++) {
    Ray ray = get_ray(j + 0.5, i + 0.5);
    auto color = ray_color(ray, max_depth, world);
    final_color += color;
  }
  final_color /= samples_per_pixel;
  return gamma_correction(final_color);
}

Color Camera::gamma_correction(const Color& color) {
  return Color(std::pow(color[0], 1. / 2.2), std::pow(color[1], 1. / 2.2),
               std::pow(color[2], 1. / 2.2));
}

}  // namespace sf