#include <iostream>
#include <optional>

#include "object/hittable_list.h"
#include "object/sphere.h"
#include "camera.h"

int main() {
  sf::Surface surface(800, 600);
  sf::Viewport viewport(800, 600, 1.0);
  sf::HittableList world;
  world.add(std::make_shared<sf::Sphere>(sf::Point(0, 0, -1), 0.5));
  world.add(std::make_shared<sf::Sphere>(sf::Point(0, -100.5, -1), 100));

  sf::Camera camera;
  camera.render(world);

  return 0;
}