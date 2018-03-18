#ifndef TRANSLATE_TRANSLATE_HPP
#define TRANSLATE_TRANSLATE_HPP 1

namespace translate
{
    template <typename R, typename M, typename W>
    void translate(R &&r, M &&m, W &&w)
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
}

#endif
