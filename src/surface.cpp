#include "surface.h"

#include <fstream>

namespace sf {

Surface::Surface(int width, int height) : width(width), height(height) {
  framebuffer = new int[width * height * 3];
}

Surface::~Surface() { delete[] framebuffer; }

void Surface::setPixel(int x, int y, int r, int g, int b) {
  framebuffer[(y * width + x) * 3 + 0] = r;
  framebuffer[(y * width + x) * 3 + 1] = g;
  framebuffer[(y * width + x) * 3 + 2] = b;
}

void Surface::save(const char* filename) {
  std::ofstream ofs(filename);
  ofs << "P3\n" << width << ' ' << height << "\n255\n";
  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      auto r = framebuffer[(j * width + i) * 3 + 0];
      auto g = framebuffer[(j * width + i) * 3 + 1];
      auto b = framebuffer[(j * width + i) * 3 + 2];  

      ofs << r << ' ' << g << ' ' << b << '\n';
    }
  }
  ofs.close();
}

}  // namespace sf
