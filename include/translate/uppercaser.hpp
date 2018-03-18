#ifndef TRANSLATE_UPPERCASER_HPP
#define TRANSLATE_UPPERCASER_HPP 1

#include <algorithm>
#include <cctype>
#include <iostream>
#include <optional>
#include <string>

namespace translate
{
    class StringReader
    {
    public:
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
    };

    class Uppercaser
    {
    public:
        void mutate(std::optional<std::string> & value) const
        {
            if(value)
            {
                std::transform(std::begin(*value), std::end(*value),
                               std::begin(*value),
                               [](auto v) { return std::toupper(v); });
            }
        }
    };

    class StdioWriter
    {
    public:
        void write(std::string const & value) const
        {
            std::cout << value << '\n';
        }
    };
} // namespace translate

#endif
