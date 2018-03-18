#if USE_SPLIT
#include <translate/translator_split.hpp>
#else
#include <translate/translator.hpp>
#endif

int main()
{
    translate::Translator t;
    t.translate();
    return 0;
}
