#include <cppa/image.hpp>

/**
 * \brief First version template
 * Dilation by a centered horizontal structuring element of length 2*k + 1.
 *
 * \param in Input image 2D
 * \param out Computed image 2D
 * \param k Radius  of the sliding windows
 * \param sup Supremum operator
 */
template<class T, class BinaryOperation>
void dilate1d(image2d<T> in, image2d<T> out, int k, BinaryOperation sup, T zero)
{
    auto n = in.width() * in.height();

    if (n == 0)
        return;

    const int alpha = 2 * k + 1;

    // Temporary images to store results
    auto g = new image2d<T>;
    auto h = new image2d<T>;

    // Forward pass
    // Compute g[x] = Max f(y), y ∈ [α * ⌊x / α⌋ : x]
    {
        int chunk_start = 0;
        int rem = n;

        for (; rem > 0; chunk_start += alpha, rem -= alpha)
        {
            int chunk_size = std::min(rem, alpha);
            std::partial_sum(
                    (in)(chunk_start, zero),
                    (in)(chunk_start, chunk_size),
                    (g)(chunk_start, zero),
                    /* /!\ They may use the pointer arithmetic
                     * for those parameters in the implementation
                     * from the subjet.
                     */
                    sup);
        }
    }
    // Backward pass
    // Compute h[x] = Max f(y) y ∈ [x : α * (⌊x/α⌋+1))
    {
        int chunk_start = 0;
        int rem = n;

        for (; rem > 0; chunk_start += alpha, rem -= alpha)
        {
            int chunk_size = std::min(alpha, rem);
            std::partial_sum(
                    std::make_reverse_iterator((in)(chunk_start, chunk_size)),
                    std::make_reverse_iterator((in)(chunk_start, zero)),
                    std::make_reverse_iterator((h)(chunk_start, chunk_size)),
                    /* /!\ They may use the pointer arithmetic
                     * for those parameters in the implementation
                     * from the subjet.
                     */
                    sup);
        }
    }
    // Compute local maximum out[x] = Max f(y) y ∈ [x-k:x+k]
    // out[x] = Max   (Max f[x-k:b),  Max f[b:x+k]) with b = α.⌈(x-k)/α⌉ = α.⌊(x+k)/α⌋
    //        = Max( h[x-k], g[x+k] )
    {
        for (int i = 0; i < n; i++)
        {
            out.m_buffer[i] = sup((h)(i-k, zero), (g)(i+k, zero));
        }
    }
}
