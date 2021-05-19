#include "../src/firstVersion.hpp"
#include <algorithm>
#include <bits/stdint-uintn.h>
#include <cfloat>
#include <cppa/image.hpp>
#include <cppa/mystd.hpp>
#include <fstream>
#include <gtest/gtest.h>


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

template <typename T>
void ASSERT_EQ_ARRAY(T* expected, image2d<T> got)
{
  for (int x = 0; x < got.width(); x++)
    for (int y = 0; y < got.height(); y++)
      ASSERT_EQ(expected[y * got.width() + x], got(x, y));
}


TEST(CPPA, test_lol)
{
  auto f = generate_iota<uint8_t>(10, 10);
  ASSERT_EQ(f(5, 5), 55);
}

TEST(CPPA, test_simple_dilate)
{
  auto             in = generate_iota<uint8_t>(3, 3);
  image2d<uint8_t> out(3, 3);

  /*  0  1  2  = out before
   *  3  4  5
   *  6  7  8
   */
  /*  1  2  2  = out after (k = 1)
   *  4  5  5
   *  7  8  8
   */

  dilate1d(in, out, 1, max<uint8_t>, (uint8_t)0);
  uint8_t expected[] = {1, 2, 2, 4, 5, 5, 7, 8, 8};
  ASSERT_EQ_ARRAY(expected, out);
}

TEST(CPPA, test_simple_erosion)
{
  auto             in = generate_iota<uint8_t>(3, 3);
  image2d<uint8_t> out(3, 3);

  /*  0  1  2  = out before
   *  3  4  5
   *  6  7  8
   */
  /*  0  0  1  = out after (k = 1)
   *  3  3  4
   *  6  6  7
   */

  dilate1d(in, out, 1, min<uint8_t>, (uint8_t)255);
  uint8_t expected[] = {0, 0, 1, 3, 3, 4, 6, 6, 7};
  ASSERT_EQ_ARRAY(expected, out);
}

TEST(CPPA, test_dilate_big_k)
{
  auto             in = generate_iota<uint8_t>(3, 3);
  image2d<uint8_t> out(3, 3);

  /*  0  1  2  = out before
   *  3  4  5
   *  6  7  8
   */
  /*  2  2  2  = out after (k = 4)
   *  5  5  5
   *  8  8  8
   */

  dilate1d(in, out, 4, max<uint8_t>, (uint8_t)0);
  uint8_t expected[] = {2, 2, 2, 5, 5, 5, 8, 8, 8};
  ASSERT_EQ_ARRAY(expected, out);
}

TEST(CPPA, test_dilate_k0)
{
  auto             in = generate_iota<uint8_t>(3, 3);
  image2d<uint8_t> out(3, 3);

  /*  0  1  2  = out before
   *  3  4  5
   *  6  7  8
   */
  /*  0  1  2  = out after k = 0
   *  3  4  5
   *  6  7  8
   */

  dilate1d(in, out, 0, max<uint8_t>, (uint8_t)0);
  uint8_t expected[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  ASSERT_EQ_ARRAY(expected, out);
}

TEST(CPPA, test_erosion_float64)
{
  auto            in = generate_iota<double>(3, 3);
  image2d<double> out(3, 3);

  /*  0  1  2  = out before
   *  3  4  5
   *  6  7  8
   */
  /*  0  0  0  = out after k = 2
   *  3  3  3
   *  6  6  6
   */

  dilate1d(in, out, 2, min<double>, DBL_MAX);
  double expected[] = {0,0,0,3,3,3,6,6,6};
  ASSERT_EQ_ARRAY(expected, out);
}

TEST(CPPA, test_dilate_bigger_size)
{
  auto            in = generate_iota<double>(8, 2);
  image2d<double> out(8, 2);

  /*  0  1  2  3  4  5  6  7  = out before
   *  8  9  10 11 12 13 14 15
   */
  /*  2  3  4  5  6  7  7  7 = out after (k = 2)
   *  10 11 12 13 14 15 15 15
   */
    
  dilate1d(in, out, 2, max<double>, (double)0);
  double expected[] = {2,3,4,5,6,7,7,7,10,11,12,13,14,15,15,15};
  ASSERT_EQ_ARRAY(expected, out);
}