#include "../src/secondVersion.hpp"
#include "testUtility.hpp"
#include <algorithm>
#include <bits/stdint-uintn.h>
#include <cppa/image.hpp>
#include <cppa/mystd.hpp>
#include <fstream>
#include <gtest/gtest.h>

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

  dilate1d(in, out, 1, false);
  ASSERT_EQ(out(0, 0), 1);
  ASSERT_EQ(out(1, 0), 2);
  ASSERT_EQ(out(2, 0), 2);
  ASSERT_EQ(out(0, 1), 4);
  ASSERT_EQ(out(1, 1), 5);
  ASSERT_EQ(out(2, 1), 5);
  ASSERT_EQ(out(0, 2), 7);
  ASSERT_EQ(out(1, 2), 8);
  ASSERT_EQ(out(2, 2), 8);
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

  dilate1d(in, out, 1, true);
  ASSERT_EQ(out(0, 0), 0);
  ASSERT_EQ(out(1, 0), 0);
  ASSERT_EQ(out(2, 0), 1);
  ASSERT_EQ(out(0, 1), 3);
  ASSERT_EQ(out(1, 1), 3);
  ASSERT_EQ(out(2, 1), 4);
  ASSERT_EQ(out(0, 2), 6);
  ASSERT_EQ(out(1, 2), 6);
  ASSERT_EQ(out(2, 2), 7);
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

  dilate1d(in, out, 4, false);
  ASSERT_EQ(out(0, 0), 2);
  ASSERT_EQ(out(1, 0), 2);
  ASSERT_EQ(out(2, 0), 2);
  ASSERT_EQ(out(0, 1), 5);
  ASSERT_EQ(out(1, 1), 5);
  ASSERT_EQ(out(2, 1), 5);
  ASSERT_EQ(out(0, 2), 8);
  ASSERT_EQ(out(1, 2), 8);
  ASSERT_EQ(out(2, 2), 8);
}
