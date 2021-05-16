#include <cppa/image.hpp>
#include <algorithm>
#include <fstream>
#include <gtest/gtest.h>
#include "../src/firstVersion.hpp"


image2d<int> generate_iota(int w, int h) {
    image2d<int> f(w, h);

    for (int y = 0; y < h; ++y)
        for (int x = 0; x < w; ++x)
            f(x, y) = w * y + x;

    return f;
}

void print(image2d<int> in, std::string file) {
    std::ofstream s(file);

    for (int i = 0; i < in.height(); ++i) {
        for (int j = 0; j < in.width(); ++j) {
            s << in(j, i) << ' ';
        }
        s << std::endl;
    }
    s.close();
}

int max(int a, int b) {
    return a < b ? b : a;
}

TEST(CPPA, test_lol) {
    auto f = generate_iota(10, 10);
    ASSERT_EQ(f(5, 5), 55);
}

TEST(CPPA, test_simple_dilate) {
    auto in = generate_iota(3, 3);
    image2d<int> out(3, 3);

    /*  0  1  2  = out before
     *  3  4  5
     *  6  7  8
     */
    /*  1  2  2  = out after (k = 1)
     *  4  5  5
     *  7  8  8
     */
    
    print(in, "input");
    dilate1d(in, out, 1, max, 0);
    print(out, "output"); 
    ASSERT_EQ(out(0, 0), 1);
    ASSERT_EQ(out(1, 0), 2);
    ASSERT_EQ(out(2, 0), 2);
    ASSERT_EQ(out(0, 1), 3);
    ASSERT_EQ(out(1, 1), 5);
    ASSERT_EQ(out(2, 1), 5);
    ASSERT_EQ(out(0, 2), 7);
    ASSERT_EQ(out(1, 2), 8);
    ASSERT_EQ(out(2, 2), 8);
}
