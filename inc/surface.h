#pragma once

class Surface {
public:
  Surface(int width, int height);
  ~Surface();
  void setPixel(int x, int y, int r, int g, int b);
  void save(const char* filename);
private:
  int width;
  int height;
  int* framebuffer;
};