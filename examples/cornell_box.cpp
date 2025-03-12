#include <iostream>
#include <optional>

#include "camera.h"
#include "material/dielectric.h"
#include "material/lambertian.h"
#include "material/luminous.h"
#include "material/metal.h"
#include "object/hittable_list.h"
#include "object/sphere.h"
#include "object/triangle.h"
#include "sky/gradient.h"
#include "sky/monochrome.h"
#include "utils/math.h"

int main() {
  sf::HittableList world;
  std::shared_ptr<sf::Material> white_wall =
      std::make_shared<sf::Lambertian>(sf::Color(1., 1., 1.));
  std::shared_ptr<sf::Material> red_wall =
      std::make_shared<sf::Lambertian>(sf::Color(1., 0., 0.));
  std::shared_ptr<sf::Material> green_wall =
      std::make_shared<sf::Lambertian>(sf::Color(0., 1., 0.));
  // back
  world.add(std::make_shared<sf::Triangle>(sf::Point(-1, -1, -1),
                                           sf::Point(1, -1, -1),
                                           sf::Point(1, 1, -1), white_wall));
  world.add(std::make_shared<sf::Triangle>(sf::Point(-1, -1, -1),
                                           sf::Point(1, 1, -1),
                                           sf::Point(-1, 1, -1), white_wall));
  // left
  world.add(std::make_shared<sf::Triangle>(
      sf::Point(-1, 1, -1), sf::Point(-1, 1, 1), sf::Point(-1, -1, 1), red_wall));
  world.add(std::make_shared<sf::Triangle>(
      sf::Point(-1, 1, -1), sf::Point(-1, -1, 1), sf::Point(-1, -1, -1), red_wall));
  // right
  world.add(std::make_shared<sf::Triangle>(
      sf::Point(1, 1, -1), sf::Point(1, -1, -1), sf::Point(1, 1, 1), green_wall));
  world.add(std::make_shared<sf::Triangle>(
      sf::Point(1, 1, 1), sf::Point(1, -1, -1), sf::Point(1, -1, 1), green_wall));
  // top
  world.add(std::make_shared<sf::Triangle>(
      sf::Point(-1, 1, 1), sf::Point(1, 1, -1), sf::Point(1, 1, 1), white_wall));
  world.add(std::make_shared<sf::Triangle>(
      sf::Point(-1, 1, 1), sf::Point(-1, 1, -1), sf::Point(1, 1, -1), white_wall));
  // bottom
  world.add(std::make_shared<sf::Triangle>(
      sf::Point(-1, -1, 1), sf::Point(1, -1, 1), sf::Point(1, -1, -1), white_wall));
  world.add(std::make_shared<sf::Triangle>(
      sf::Point(-1, -1, 1), sf::Point(1, -1, -1), sf::Point(-1, -1, -1), white_wall));

  std::shared_ptr<sf::Material> light =
      std::make_shared<sf::Luminous>(sf::Color(20., 20., 20.));
  // light
  world.add(std::make_shared<sf::Triangle>(sf::Point(-0.2, 1, 0.2),
                                           sf::Point(0.2, 1, -0.2),
                                           sf::Point(0.2, 1, 0.2), light));
  world.add(std::make_shared<sf::Triangle>(sf::Point(-0.2, 1, 0.2),
                                           sf::Point(-0.2, 1, -0.2),
                                           sf::Point(0.2, 1, -0.2), light));

  world.add(std::make_shared<sf::Sphere>(
      sf::Point(0, -0.2, 0), 0.2,
      std::make_shared<sf::Lambertian>(sf::Color(1., 1., 1.))));
  sf::Camera cam;
  cam.setPosition(sf::Point(0, 0, 8));
  cam.setLookat(sf::Point(0, 0, 0));
  cam.setUp(sf::Vec3(0, 1, 0));
  cam.setFov(18.);
  cam.setAspectRadio(1.);
  cam.setMaxDepth(500);
  cam.setMultiSample(500);
  cam.setDefocusAngle(0.);
  cam.setSurfaceHeight(675);
  cam.setFocusDist(8.);
  cam.setSky(std::make_shared<sf::Monochrome>(sf::Color(0., 0., 0.)));
  cam.render(world);
}