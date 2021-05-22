#include "../src/secondVersion.hpp"
#include <benchmark/benchmark.h>
#include <cppa/image.hpp>


void myiota(image2d<int> out)
{
  int w = out.width();
  int h = out.height();

  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x)
      out(x, y) = w * y + x;
}


static void BM_FirstVersion_int32(benchmark::State& state)
{
  int          n = state.range(0);
  image2d<int> in(n, n);
  image2d<int> out(n, n);
  myiota(in);
  for (auto _ : state)
  {
    dilate1d(in, out, 3, true);
  }
  state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(n * n));
}
BENCHMARK(BM_FirstVersion_int32)->Arg(8)->Arg(64)->Arg(512)->Arg(1 << 10)->Arg(1 << 11);

// Write your benchmarks below following the same model as above
// You can check the documentation for more details
// https://github.com/google/benchmark/blob/master/README.md

BENCHMARK_MAIN();
