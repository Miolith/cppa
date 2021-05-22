
template <typename T>
void myiota(image2d<T> out)
{
  int w = out.width();
  int h = out.height();

  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x)
      out(x, y) = w * y + x;
}
