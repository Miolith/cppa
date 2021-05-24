#include "src/thirdVersion.hpp"

int main()
{
  image2d<uint8_t> out(1 << 10, 1 << 10);
  image2d<uint8_t> in(1 << 10, 1 << 10);

  dilate1d(in, out, 2, true);
}
