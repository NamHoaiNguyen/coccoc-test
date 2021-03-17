#ifndef language_factory
#define language_factory

#include "../language/language.h"
#include "../language/english/english.h"
#include "../language/vietnam/vietnamese.h"

class LanguageFactory
{
public:
    static Language* createConnection(eConnectionType connectionType);
};

#endif 