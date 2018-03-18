#ifndef TRANSLATE_TRANSLATOR_HPP
#define TRANSLATE_TRANSLATOR_HPP 1

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

namespace translate
{
    class Translator
    {
    public:
        void translate()
        {
            std::string input;
            std::getline(std::cin, input);
            while(std::cin)
            {
                std::transform(std::begin(input), std::end(input),
                               std::begin(input),
                               [](auto v) { return std::toupper(v); });
                std::cout << input << '\n';
                std::getline(std::cin, input);
            }
        }
    };
} // namespace translate

#endif
