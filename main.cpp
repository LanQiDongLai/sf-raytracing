#include <iostream>
#include <optional>

#include "object/hittable_list.h"
#include "object/sphere.h"
#include "material/metal.h"
#include "material/lambertian.h"
#include "material/dielectric.h"
#include "camera.h"

int main() {
  sf::Surface surface(800, 600);
  sf::Viewport viewport(800, 600, 1.0);
  sf::HittableList world;
  auto blue_lambertian = std::make_shared<sf::Lambertian>(sf::Color(0.2, 0.5, 1.0));
  auto gray_lambertian = std::make_shared<sf::Lambertian>(sf::Color(0.8, 0.8, 0.8));
  auto metal = std::make_shared<sf::Metal>(sf::Color(0.8, 0.8, 0.8), 0.);
  auto glass = std::make_shared<sf::Dielectric>(1.5);
  world.add(std::make_shared<sf::Sphere>(sf::Point(0, 0, -1.5), 0.5, blue_lambertian));
  world.add(std::make_shared<sf::Sphere>(sf::Point(0, -100.5, -1), 100, gray_lambertian));
  world.add(std::make_shared<sf::Sphere>(sf::Point(1, 0, -1), 0.5, glass));
  world.add(std::make_shared<sf::Sphere>(sf::Point(-1, 0, -1), 0.5, metal));

  sf::Camera camera;
  camera.render(world);

  return 0;
}