#include "viewport.h"

namespace sf {

Viewport::Viewport() : width(0), height(0), focal_length(1.0) {}

Viewport::Viewport(double width, double height, double focal_length)
    : width(width), height(height), focal_length(focal_length) {}

Viewport::~Viewport() {}

void Viewport::setWidth(double width) { this->width = width; }

void Viewport::setHeight(double height) { this->height = height; }

void Viewport::setFocalLength(double focal_length) {
  this->focal_length = focal_length;
}

double Viewport::getWidth() const { return width; }

double Viewport::getHeight() const { return height; }

double Viewport::getFocalLength() const { return focal_length; }

Vec3 Viewport::getPixelPos(double x, double y) {
  return Vec3(x - width / 2, -y + height / 2,
              -focal_length);
}

}  // namespace sf