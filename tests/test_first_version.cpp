#include "../src/firstVersion.hpp"
#include "testUtility.hpp"
#include <algorithm>
#include <bits/stdint-uintn.h>
#include <cfloat>
#include <cmath>
#include <cppa/image.hpp>
#include <cppa/mystd.hpp>
#include <fstream>
#include <gtest/gtest.h>


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
  double expected[] = {0, 0, 0, 3, 3, 3, 6, 6, 6};
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
  double expected[] = {2, 3, 4, 5, 6, 7, 7, 7, 10, 11, 12, 13, 14, 15, 15, 15};
  ASSERT_EQ_ARRAY(expected, out);
}

TEST(CPPA, test_erosion_bigger_size)
{
  auto            in = generate_iota<double>(8, 2);
  image2d<double> out(8, 2);

  /*  0  1  2  3  4  5  6  7  = out before
   *  8  9  10 11 12 13 14 15
   */
  /*  0  0  0  1  2  3  4  5 = out after (k = 2)
   *  8  8  8  9  10 11 12 13
   */

  dilate1d(in, out, 2, min<double>, (double)DBL_MAX);
  double expected[] = {0, 0, 0, 1, 2, 3, 4, 5, 8, 8, 8, 9, 10, 11, 12, 13};
  ASSERT_EQ_ARRAY(expected, out);
}

TEST(CPPA, test_erosion_random_val)
{
  auto            in = generate_iota<double>(4, 5);
  image2d<double> out(4, 5);

  double tab[] = {984.654, 68.78, 654.0,   18.7, 147893, 8334, 7887, 478986, 0, 0,
                  1,       0,     sqrt(2), 1.4,  1.5,    1.4,  5,    4,      3, 2};
  for (int i = 0; i < 20; i++)
    in(i, 0) = tab[i];

  /* 984.654 68.78 654.0 18.7
   * 147893 8334 7887 478986
   * 0 0 1 0
   * sqrt(2) 1.4 1.5 1.4
   * 5 4 3 2
   */

  /* 18.7 18.7 18.7 18.7 (k = 3)
   * 7887 7887 7887 7887
   * 0 0 0 0
   * 1.4 1.4 1.4 1.4
   * 2 2 2 2
   */

  dilate1d(in, out, 3, min<double>, (double)DBL_MAX);
  double expected[] = {18.7, 18.7, 18.7, 18.7, 7887, 7887, 7887, 7887, 0, 0, 0, 0, 1.4, 1.4, 1.4, 1.4, 2, 2, 2, 2};

  ASSERT_EQ_ARRAY(expected, out);
}
