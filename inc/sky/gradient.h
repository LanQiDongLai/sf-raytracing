#include "sky/sky.h"

namespace sf {

class Gradient : public Sky {
 public:
  Gradient(const Color& up, const Color& down);
  Color get_color(const Ray& r) const override;
 private:
  Color up_color;
  Color down_color;
};

}  // namespace sf
