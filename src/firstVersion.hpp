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
  for (int x = 0; x < in.width(); x++)
  {
    auto      n     = in.width() * x + in.width();
    const int alpha = 2 * k + 1;

    if (n == 0)
      return;


    // Temporary images to store results
    image2d<T> g(in.width(), 1);
    image2d<T> h(in.width(), 1);

    // Forward pass
    // Compute g[x] = Max f(y), y ∈ [α * ⌊x / α⌋ : x]
    {
      int chunk_start = x * in.width();
      int rem         = n;

      for (; rem > x * in.width(); chunk_start += alpha, rem -= alpha)
      {
        int chunk_size = std::min(rem, alpha);
        std::partial_sum(&in(chunk_start, zero), &in(chunk_start + chunk_size, zero), &g(chunk_start, zero),
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
      int chunk_start = x * in.width();
      int rem         = n;

      for (; rem > x * in.width(); chunk_start += alpha, rem -= alpha)
      {
        int chunk_size = std::min(alpha, rem);
        std::partial_sum(std::make_reverse_iterator(&in(chunk_start + chunk_size, zero)),
                         std::make_reverse_iterator(&in(chunk_start, zero)),
                         std::make_reverse_iterator(&h(chunk_start + chunk_size, zero)),
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
      for (int i = x * in.width(); i < n; i++)
      {
          //if (i - k >= x * in.width() && i + k < n)
            out(i, zero) = sup(h(i - k, zero), g(i + k, zero));
      }
    }
  }
}
