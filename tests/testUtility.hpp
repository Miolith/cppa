#pragma once

template <typename T>
image2d<T> generate_iota(int w, int h)
{
  image2d<T> f(w, h);

  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x)
      f(x, y) = static_cast<T>(w * y + x);

  return f;
}


template <typename T>
void print(image2d<T> in, std::string file)
{
  std::ofstream s(file);

  for (int i = 0; i < in.height(); ++i)
  {
    for (int j = 0; j < in.width(); ++j)
    {
      s << in(j, i) << ' ';
    }
    s << std::endl;
  }
  s.close();
}
