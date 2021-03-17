#ifndef language_factory
#define language_factory

#include <memory>

#include "../language/language.h"
#include "../language/english/english.h"
#include "../language/vietnam/vietnamese.h"

class LanguageFactory
{
public:
    static std::shared_ptr<Language> createConnection(eConnectionType connectionType);
};

#endif 