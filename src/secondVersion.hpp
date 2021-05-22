#include "cppa/image.hpp"
#include "firstVersion.hpp"
#include <bits/stdint-uintn.h>
#include <cassert>
#include <cfloat>
#include <cppa/mystd.hpp>

void dilate1d(image2d_any in, image2d_any out, int k, bool decreasing)
{
  pixel_format_t dtype = in.dtype();
  assert(dtype == out.dtype());

  if (decreasing)
  {
    switch (dtype)
    {
    case UINT8:
      dilate1d((image2d<uint8_t>&)in, (image2d<uint8_t>&)out, k, min<uint8_t>, (uint8_t)UINT8_MAX);
      break;
    case UINT16:
      dilate1d((image2d<uint16_t>&)in, (image2d<uint16_t>&)out, k, min<uint16_t>, (uint16_t)UINT16_MAX);
      break;
    case UINT32:
      dilate1d((image2d<uint32_t>&)in, (image2d<uint32_t>&)out, k, min<uint32_t>, (uint32_t)UINT32_MAX);
      break;
    case UINT64:
      dilate1d((image2d<uint64_t>&)in, (image2d<uint64_t>&)out, k, min<uint64_t>, (uint64_t)UINT64_MAX);
      break;
    case INT8:
      dilate1d((image2d<int8_t>&)in, (image2d<int8_t>&)out, k, min<int8_t>, (int8_t)INT8_MAX);
      break;
    case INT16:
      dilate1d((image2d<int16_t>&)in, (image2d<int16_t>&)out, k, min<int16_t>, (int16_t)INT16_MAX);
      break;
    case INT32:
      dilate1d((image2d<int32_t>&)in, (image2d<int32_t>&)out, k, min<int32_t>, (int32_t)INT32_MAX);
      break;
    case INT64:
      dilate1d((image2d<int64_t>&)in, (image2d<int64_t>&)out, k, min<int64_t>, (int64_t)INT64_MAX);
      break;
    case FLOAT32:
      dilate1d((image2d<float>&)in, (image2d<float>&)out, k, min<float>, (float)FLT_MAX);
      break;
    case FLOAT64:
      dilate1d((image2d<double>&)in, (image2d<double>&)out, k, min<double>, (double)DBL_MAX);
      break;
    }
  }
  else
  {
    switch (dtype)
    {
    case UINT8:
      dilate1d((image2d<uint8_t>&)in, (image2d<uint8_t>&)out, k, max<uint8_t>, (uint8_t)0);
      break;
    case UINT16:
      dilate1d((image2d<uint16_t>&)in, (image2d<uint16_t>&)out, k, max<uint16_t>, (uint16_t)0);
      break;
    case UINT32:
      dilate1d((image2d<uint32_t>&)in, (image2d<uint32_t>&)out, k, max<uint32_t>, (uint32_t)0);
      break;
    case UINT64:
      dilate1d((image2d<uint64_t>&)in, (image2d<uint64_t>&)out, k, max<uint64_t>, (uint64_t)0);
      break;
    case INT8:
      dilate1d((image2d<int8_t>&)in, (image2d<int8_t>&)out, k, max<int8_t>, (int8_t)0);
      break;
    case INT16:
      dilate1d((image2d<int16_t>&)in, (image2d<int16_t>&)out, k, max<int16_t>, (int16_t)0);
      break;
    case INT32:
      dilate1d((image2d<int32_t>&)in, (image2d<int32_t>&)out, k, max<int32_t>, (int32_t)0);
      break;
    case INT64:
      dilate1d((image2d<int64_t>&)in, (image2d<int64_t>&)out, k, max<int64_t>, (int64_t)0);
      break;
    case FLOAT32:
      dilate1d((image2d<float>&)in, (image2d<float>&)out, k, max<float>, (float)0);
      break;
    case FLOAT64:
      dilate1d((image2d<double>&)in, (image2d<double>&)out, k, max<double>, (double)0);
      break;
    }
  }
}
