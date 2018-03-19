#ifndef TRANSLATE_TRANSLATOR_INTERFACES_HPP
#define TRANSLATE_TRANSLATOR_INTERFACES_HPP 1

#include <algorithm>
#include <cctype>
#include <iostream>
#include <optional>
#include <string>

namespace translate
{
    template <typename T>
    class Reader
    {
    public:
        virtual std::optional<T> read() const = 0;
    };

    template <typename T>
    class Mutator
    {
    public:
        virtual void mutate(std::optional<T> & value) const = 0;
    };

    template <typename T>
    class Writer
    {
    public:
        virtual void write(T const & value) const = 0;
    };

    class Translator : public Reader<std::string>,
                       public Mutator<std::string>,
                       public Writer<std::string>
    {
    public:
        std::optional<std::string> read() const override
        {
            std::string input;
            std::getline(std::cin, input);
            if(std::cin)
            {
                return input;
            }
            return std::nullopt;
        }

        void mutate(std::optional<std::string> & value) const override
        {
            if(value)
            {
                std::transform(std::begin(*value), std::end(*value),
                               std::begin(*value),
                               [](auto v) { return std::toupper(v); });
            }
        }

        void write(std::string const & value) const override
        {
            std::cout << value << '\n';
        }
    };

    template <typename T>
    void translate(Reader<T> & reader, Mutator<T> & mutator, Writer<T> & writer)
    {
        auto input = reader.read();
        while(input)
        {
            mutator.mutate(input);
            if(input)
            {
                writer.write(*input);
            }
            input = reader.read();
        }
    }
} // namespace translate

#endif
