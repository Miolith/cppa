#include <cppa/image.hpp>

#include <gtest/gtest.h>
#include "../src/firstVersion.hpp"


image2d<int> generate_iota(int w, int h) {
    image2d<int> f(w, h);

    for (int y = 0; y < h; ++y)
        for (int x = 0; x < w; ++x)
            f(x, y) = w * y + x;

    return f;
}
void print(image2d<int> in) {
    for (int i = 0; i < in.height(); ++i) {
        for (int j = 0; j < in.width(); ++j) {
            std::cout << in(i, j) << ' ';
        }
        std::cout << std::endl;
    }
}

int max(int a, int b) {
    return a < b ? b : a;
}

TEST(CPPA, test_dummy) {
    auto f = generate_iota(10, 10);
    ASSERT_EQ(f(5, 5), 55);
}

TEST(CPPA, dummy1) {
    auto in = generate_iota(5, 5);
    image2d<int> out(5, 5);
    dilate1d(in, out, 1, max, 0);
    print(in);
    print(out);
}
