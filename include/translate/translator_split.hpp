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

    private:
        std::optional<std::string> read() const
        {
            std::string input;
            std::getline(std::cin, input);
            if(std::cin)
            {
                return input;
            }
            return std::nullopt;
        }

        void mutate(std::optional<std::string> & value) const
        {
            if(value)
            {
                std::transform(std::begin(*value), std::end(*value),
                               std::begin(*value),
                               [](auto v) { return std::toupper(v); });
            }
        }

        void write(std::string const & value) const
        {
            std::cout << value << '\n';
        }
    };
} // namespace translate

#endif
