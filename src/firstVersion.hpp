#include <algorithm>
#include <cppa/image.hpp>
#include <iterator>
#include <numeric>

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
    auto      n     = in.width();
    const int alpha = 2 * k + 1;

    if (n == 0)
      return;
  
    for (int x = 0; x < in.height(); x++)
  {


    // Temporary images to store results
    auto h = new T[n];
    auto g = new T[n];

    std::fill_n(h, n, zero);

    // Forward pass
    // Compute g[x] = Max f(y), y ∈ [α * ⌊x / α⌋ : x]
    {
      int chunk_start = 0;
      int rem         = n;

      for (; rem > 0; chunk_start += alpha, rem -= alpha)
      {
        int chunk_size = std::min(rem, alpha);
        std::partial_sum(&in(chunk_start, x), &in(chunk_start + chunk_size, x), g + chunk_start,
                         /* /!\ They may use the pointer arithmetic
                          * for those parameters in the implementation
                          * from the subject.
                          */
                         sup);
      }
    }
    // Backward pass
    // Compute h[x] = Max f(y) y ∈ [x : α * (⌊x/α⌋+1))
    {
      int chunk_start = 0;
      int rem         = n;

      for (; rem > 0; chunk_start += alpha, rem -= alpha)
      {
        int chunk_size = std::min(alpha, rem);
        std::partial_sum(std::make_reverse_iterator(&in(chunk_start + chunk_size, x)),
                         std::make_reverse_iterator(&in(chunk_start, x)),
                         std::make_reverse_iterator(h + chunk_start + chunk_size),
                         /* /!\ They may use the pointer arithmetic
                          * for those parameters in the implementation
                          * from the subject.
                          */
                         sup);
      }
    }
    // Compute local maximum out[x] = Max f(y) y ∈ [x-k:x+k]
    // out[x] = Max   (Max f[x-k:b],  Max f[b:x+k]) with b = α.⌈(x-k)/α⌉ = α.⌊(x+k)/α⌋
    //        = Max( h[x-k], g[x+k] )
    {
      for (int i = 0; i < n; i++)
      {
          if (i - k >= 0 && i + k < n)
            out(i, x) = sup(h[i - k], g[i + k]);
          else if (i - k < 0)
              out(i, x) = g[i + k];
          else
              out(i, x) = h[i - k];
      }
    }

    delete[] g;
    delete[] h;
  }
}
