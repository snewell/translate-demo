#include <translate/translate.hpp>

#include <algorithm>
#include <cctype>
#include <iostream>
#include <optional>
#include <string>

int main()
{
    auto read = []() -> std::optional<std::string> {
        std::string input;
        std::getline(std::cin, input);
        if(std::cin)
        {
            return input;
        }
        return std::nullopt;
    };

    auto mutate = [](std::optional<std::string> &value) {
        if(value)
        {
            std::transform(std::begin(*value), std::end(*value),
                           std::begin(*value),
                           [](auto v) {
                               return std::toupper(v);
                           });
        }
    };

    auto write = [](std::string const &value) {
        std::cout << value << '\n';
    };

    translate::translate(read, mutate, write);
    return 0;
}
