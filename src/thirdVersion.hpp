#include "cppa/image.hpp"
#include "firstVersion.hpp"
#include <bits/stdint-uintn.h>
#include <cassert>
#include <cfloat>
#include <cppa/mystdjit.hpp>

void dilate1d(image2d_any in, image2d_any out, int k, bool decreasing)
{
  pixel_format_t dtype = in.dtype();
  assert(dtype == out.dtype());


  JitRuntime rt;

  CodeHolder code;

  code.init(rt.environment());

  x86::Assembler x(&code);

  StdJit s(rt, code, x);


  if (decreasing)
  {
    switch (dtype)
    {
    case UINT8:
      dilate1d((image2d<uint8_t>&)in, (image2d<uint8_t>&)out, k, s.min_uint8(), (uint8_t)UINT8_MAX);
      break;
    case UINT16:
      dilate1d((image2d<uint16_t>&)in, (image2d<uint16_t>&)out, k, s.min_uint16(), (uint16_t)UINT16_MAX);
      break;
    case UINT32:
      dilate1d((image2d<uint32_t>&)in, (image2d<uint32_t>&)out, k, s.min_uint32(), (uint32_t)UINT32_MAX);
      break;
    case UINT64:
      dilate1d((image2d<uint64_t>&)in, (image2d<uint64_t>&)out, k, s.min_uint64(), (uint64_t)UINT64_MAX);
      break;
    case INT8:
      dilate1d((image2d<int8_t>&)in, (image2d<int8_t>&)out, k, s.min_int8(), (int8_t)INT8_MAX);
      break;
    case INT16:
      dilate1d((image2d<int16_t>&)in, (image2d<int16_t>&)out, k, s.min_int16(), (int16_t)INT16_MAX);
      break;
    case INT32:
      dilate1d((image2d<int32_t>&)in, (image2d<int32_t>&)out, k, s.min_int32(), (int32_t)INT32_MAX);
      break;
    case INT64:
      dilate1d((image2d<int64_t>&)in, (image2d<int64_t>&)out, k, s.min_int64(), (int64_t)INT64_MAX);
      break;
    case FLOAT32:
      dilate1d((image2d<float>&)in, (image2d<float>&)out, k, s.min_float32(), (float)FLT_MAX);
      break;
    case FLOAT64:
      dilate1d((image2d<double>&)in, (image2d<double>&)out, k, s.min_float64(), (double)DBL_MAX);
      break;
    }
  }
  else
  {
    switch (dtype)
    {
    case UINT8:
      dilate1d((image2d<uint8_t>&)in, (image2d<uint8_t>&)out, k, s.max_uint8(), (uint8_t)0);
      break;
    case UINT16:
      dilate1d((image2d<uint16_t>&)in, (image2d<uint16_t>&)out, k, s.max_uint16(), (uint16_t)0);
      break;
    case UINT32:
      dilate1d((image2d<uint32_t>&)in, (image2d<uint32_t>&)out, k, s.max_uint32(), (uint32_t)0);
      break;
    case UINT64:
      dilate1d((image2d<uint64_t>&)in, (image2d<uint64_t>&)out, k, s.max_uint64(), (uint64_t)0);
      break;
    case INT8:
      dilate1d((image2d<int8_t>&)in, (image2d<int8_t>&)out, k, s.max_int8(), (int8_t)0);
      break;
    case INT16:
      dilate1d((image2d<int16_t>&)in, (image2d<int16_t>&)out, k, s.max_int16(), (int16_t)0);
      break;
    case INT32:
      dilate1d((image2d<int32_t>&)in, (image2d<int32_t>&)out, k, s.max_int32(), (int32_t)0);
      break;
    case INT64:
      dilate1d((image2d<int64_t>&)in, (image2d<int64_t>&)out, k, s.max_int64(), (int64_t)0);
      break;
    case FLOAT32:
      dilate1d((image2d<float>&)in, (image2d<float>&)out, k, s.max_float32(), (float)0);
      break;
    case FLOAT64:
      dilate1d((image2d<double>&)in, (image2d<double>&)out, k, s.max_float64(), (double)0);
      break;
    }
  }
}
