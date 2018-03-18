#ifndef TRANSLATE_TRANSLATE_HPP
#define TRANSLATE_TRANSLATE_HPP 1

#include <utility>

namespace translate
{
    template <typename R, typename M, typename W>
    void translate(R && r, M && m, W && w)
    {
        auto input = r();
        while(input)
        {
            m(input);
            if(input)
            {
                w(*input);
            }
            input = r();
        }
    }

    template <typename R>
    auto make_reader(R && r)
    {
        return [r_ = std::forward<R>(r)]() { return r_(); };
    }

    template <typename M>
    auto make_mutator(M && m)
    {
        return [m_ = std::forward<M>(m)]() { return m_(); };
    }

    template <typename W>
    auto make_writer(W && w)
    {
        return [w_ = std::forward<W>(w)]() { return w_(); };
    }
} // namespace translate

#endif
