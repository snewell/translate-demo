#ifndef TRANSLATE_TRANSLATOR_SPLIT_HPP
#define TRANSLATE_TRANSLATOR_SPLIT_HPP 1

#include <algorithm>
#include <cctype>
#include <iostream>
#include <optional>
#include <string>

namespace translate
{
    class Translator
    {
    public:
        std::optional<std::string> read()
        {
            std::string input;
            std::getline(std::cin, input);
            if(std::cin)
            {
                return input;
            }
            return std::nullopt;
        }

        void mutate(std::optional<std::string> & value)
        {
            if(value)
            {
                std::transform(std::begin(*value), std::end(*value),
                               std::begin(*value),
                               [](auto v) { return std::toupper(v); });
            }
        }

        void write(std::string const & value)
        {
            std::cout << value << '\n';
        }

        void translate()
        {
            auto input = read();
            while(input)
            {
                mutate(input);
                if(input)
                {
                    write(*input);
                }
                input = read();
            }
        }
    };
} // namespace translate

#endif
