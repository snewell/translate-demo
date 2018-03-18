#include <translate/translate.hpp>
#include <translate/uppercaser.hpp>

namespace translate
{
    template <>
    auto make_reader<translate::StringReader>(translate::StringReader &&r)
    {
        return [r]() {
            return r.read();
        };
    }

    template <>
    auto make_mutator<translate::Uppercaser>(translate::Uppercaser &&u)
    {
        return [u](std::optional<std::string> &value) {
            u.mutate(value);
        };
    }

    template <>
    auto make_writer<translate::StdioWriter>(translate::StdioWriter &&w)
    {
        return [w](std::string const &value) {
            w.write(value);
        };
    }
}

int main()
{
    translate::translate(
        translate::make_reader(translate::StringReader{}),
        translate::make_mutator(translate::Uppercaser{}),
        translate::make_writer(translate::StdioWriter{}));
    return 0;
}
