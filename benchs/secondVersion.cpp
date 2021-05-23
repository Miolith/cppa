#include "../src/secondVersion.hpp"
#include "benchUtility.hpp"
#include <benchmark/benchmark.h>
#include <bits/stdint-intn.h>
#include <bits/stdint-uintn.h>
#include <cppa/image.hpp>



static void BM_SecondVersion_int8(benchmark::State& state)
{
  int          n = state.range(0);
  image2d<int8_t> in(n, n);
  image2d<int8_t> out(n, n);
  myiota(in);
  for (auto _ : state)
    dilate1d(in, out, 3, true);
  state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(n * n));
}
static void BM_SecondVersion_int16(benchmark::State& state)
{
  int          n = state.range(0);
  image2d<int16_t> in(n, n);
  image2d<int16_t> out(n, n);
  myiota(in);
  for (auto _ : state)
    dilate1d(in, out, 3, true);
  state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(n * n));
}

static void BM_SecondVersion_int32(benchmark::State& state)
{
  int          n = state.range(0);
  image2d<int32_t> in(n, n);
  image2d<int32_t> out(n, n);
  myiota(in);
  for (auto _ : state)
    dilate1d(in, out, 3, true);
  state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(n * n));
}

static void BM_SecondVersion_int64(benchmark::State& state)
{
  int          n = state.range(0);
  image2d<int64_t> in(n, n);
  image2d<int64_t> out(n, n);
  myiota(in);
  for (auto _ : state)
    dilate1d(in, out, 3, true);
  state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(n * n));
}

static void BM_SecondVersion_uint8(benchmark::State& state)
{
  int          n = state.range(0);
  image2d<uint8_t> in(n, n);
  image2d<uint8_t> out(n, n);
  myiota(in);
  for (auto _ : state)
    dilate1d(in, out, 3, true);
  state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(n * n));
}


static void BM_SecondVersion_uint16(benchmark::State& state)
{
  int          n = state.range(0);
  image2d<uint16_t> in(n, n);
  image2d<uint16_t> out(n, n);
  myiota(in);
  for (auto _ : state)
    dilate1d(in, out, 3, true);
  state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(n * n));
}


static void BM_SecondVersion_uint32(benchmark::State& state)
{
  int          n = state.range(0);
  image2d<uint32_t> in(n, n);
  image2d<uint32_t> out(n, n);
  myiota(in);
  for (auto _ : state)
    dilate1d(in, out, 3, true);
  state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(n * n));
}
static void BM_SecondVersion_uint64(benchmark::State& state)
{
  int          n = state.range(0);
  image2d<uint64_t> in(n, n);
  image2d<uint64_t> out(n, n);
  myiota(in);
  for (auto _ : state)
    dilate1d(in, out, 3, true);
  state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(n * n));
}
static void BM_SecondVersion_float32(benchmark::State& state)
{
  int          n = state.range(0);
  image2d<float> in(n, n);
  image2d<float> out(n, n);
  myiota(in);
  for (auto _ : state)
    dilate1d(in, out, 3, true);
  state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(n * n));
}
static void BM_SecondVersion_float64(benchmark::State& state)
{
  int          n = state.range(0);
  image2d<double> in(n, n);
  image2d<double> out(n, n);
  myiota(in);
  for (auto _ : state)
    dilate1d(in, out, 3, true);
  state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(n * n));
}

BENCHMARK(BM_SecondVersion_int8)->Arg(1 << 10)->Arg(1 << 11);
BENCHMARK(BM_SecondVersion_uint8)->Arg(1 << 10)->Arg(1 << 11);

BENCHMARK(BM_SecondVersion_int16)->Arg(1 << 10)->Arg(1 << 11);
BENCHMARK(BM_SecondVersion_uint16)->Arg(1 << 10)->Arg(1 << 11);

BENCHMARK(BM_SecondVersion_int32)->Arg(1 << 10)->Arg(1 << 11);
BENCHMARK(BM_SecondVersion_uint32)->Arg(1 << 10)->Arg(1 << 11);

BENCHMARK(BM_SecondVersion_int64)->Arg(1 << 10)->Arg(1 << 11);
BENCHMARK(BM_SecondVersion_uint64)->Arg(1 << 10)->Arg(1 << 11);

BENCHMARK(BM_SecondVersion_float32)->Arg(1 << 10)->Arg(1 << 11);
BENCHMARK(BM_SecondVersion_float64)->Arg(1 << 10)->Arg(1 << 11);

// Write your benchmarks below following the same model as above
// You can check the documentation for more details
// https://github.com/google/benchmark/blob/master/README.md

BENCHMARK_MAIN();
