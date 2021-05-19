#include <algorithm>
#include <cppa/image.hpp>
#include <fstream>
#include <iterator>
#include <numeric>
#include <cassert>

/**
 * \brief First version template
 * Dilation by a centered horizontal structuring element of length 2*k + 1.
 *
 * \param in<T> Input image 2D
 * \param out<T> Computed image 2D
 * \param k Radius  of the sliding windows
 * \param sup Supremo operator
 */
template <class T, class BinaryOperation>
void dilate1d(image2d<T> in, image2d<T> out, int k, BinaryOperation sup, T zero)
{
  assert(k >= 0 && "Negative radius k");
  auto      n     = in.width();
  const int alpha = 2 * k + 1;

  if (n == 0 || zero < 0)
    return;

  for (int x = 0; x < in.height(); x++)
  {

    // Temporary images to store results
    T* h = new T[n];
    T* g = new T[n];

    // Forward pass
    {
      int chunk_start = 0;
      int rem         = n;

      for (; rem > 0; chunk_start += alpha, rem -= alpha)
      {
        int chunk_size = std::min(rem, alpha);
        std::partial_sum(&in(chunk_start, x), &in(chunk_start + chunk_size, x), g + chunk_start,
                         sup);
      }
    }

    // Backward pass
    {
      int chunk_start = 0;
      int rem         = n;

      for (; rem > 0; chunk_start += alpha, rem -= alpha)
      {
        int chunk_size = std::min(alpha, rem);
        std::partial_sum(std::make_reverse_iterator(&in(chunk_start + chunk_size, x)),
                         std::make_reverse_iterator(&in(chunk_start, x)),
                         std::make_reverse_iterator(h + chunk_start + chunk_size),
                         sup);
      }
    }

    // Compute local maximum out[x] = Max f(y) y ∈ [x-k:x+k]
    {
      for (int i = 0; i < n; i++)
      {
        if (i - k >= 0 && i + k < n)
          out(i, x) = sup(h[i - k], g[i + k]);
        else if (i - k < 0 && i + k < n)
          out(i, x) = sup(g[i + k], g[i]);
        else if (i - k >= 0 && i + k >= n) 
          out(i, x) = sup(h[i - k], h[i]);
        else
          out(i, x) = sup(h[i], g[i]);
      }
    }

    delete[] g;
    delete[] h;
  }
}
