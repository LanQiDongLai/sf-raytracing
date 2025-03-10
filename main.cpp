#include <iostream>
#include <optional>

#include "camera.h"
#include "material/dielectric.h"
#include "material/lambertian.h"
#include "material/metal.h"
#include "material/luminous.h"
#include "object/hittable_list.h"
#include "object/sphere.h"
#include "utils/math.h"

int main() {
  sf::HittableList world;

  auto ground_material = std::make_shared<sf::Lambertian>(sf::Color(0.5, 0.5, 0.5));
  world.add(std::make_shared<sf::Sphere>(sf::Point(0, -1000, 0), 1000,
                                         ground_material));

  for (int a = -11; a < 11; a++) {
    for (int b = -11; b < 11; b++) {
      auto choose_mat = sf::math::random_double(0., 1.);
      sf::Point center(a + 0.9 * sf::math::random_double(0., 1.), 0.2,
                       b + 0.9 * sf::math::random_double(0., 1.));

      if ((center - sf::Point(4, 0.2, 0)).length() > 0.9) {
        std::shared_ptr<sf::Material> sphere_material;

        if (choose_mat < 0.8) {
          auto albedo = sf::Vec3(sf::math::random_double(0.5, 1),
                                 sf::math::random_double(0.5, 1),
                                 sf::math::random_double(0.5, 1));
          sphere_material = std::make_shared<sf::Lambertian>(albedo);
          world.add(
              std::make_shared<sf::Sphere>(center, 0.2, sphere_material));
        } else if (choose_mat < 0.95) {
          auto albedo = sf::Vec3(sf::math::random_double(0.5, 1),
                                sf::math::random_double(0.5, 1),
                                sf::math::random_double(0.5, 1));
          auto fuzz = sf::math::random_double(0, 0.5);
          sphere_material = std::make_shared<sf::Metal>(albedo, fuzz);
          world.add(
              std::make_shared<sf::Sphere>(center, 0.2, sphere_material));
        } else {
          sphere_material = std::make_shared<sf::Dielectric>(1.5);
          world.add(
              std::make_shared<sf::Sphere>(center, 0.2, sphere_material));
        }
      }
    }
  }

  auto material1 = std::make_shared<sf::Luminous>(sf::Color(1.0, 0.5, 0.8));
  world.add(
      std::make_shared<sf::Sphere>(sf::Point(0.0, 1.0, 0.0), 1.0, material1));

  auto material2 = std::make_shared<sf::Lambertian>(sf::Color(0.4, 0.2, 0.1));
  world.add(
      std::make_shared<sf::Sphere>(sf::Point(-4.0, 1.0, 0.0), 1.0, material2));

  auto material3 = std::make_shared<sf::Metal>(sf::Color(0.7, 0.6, 0.5), 0.0);
  world.add(
      std::make_shared<sf::Sphere>(sf::Point(4.0, 1.0, 0.0), 1.0, material3));

  sf::Camera cam;
  cam.setPosition(sf::Point(13, 2, 3));
  cam.setLookat(sf::Point(0, 0, 0));
  cam.setUp(sf::Vec3(0, 1, 0));
  cam.setFov(20.);
  cam.setAspectRadio(16. / 9.);
  cam.setMaxDepth(50);
  cam.setMultiSample(500);
  cam.setDefocusAngle(0.6);
  cam.setSurfaceHeight(675);
  cam.setFocusDist(10.);
  cam.render(world);
}