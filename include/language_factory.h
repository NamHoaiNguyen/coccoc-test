#ifndef language_factory
#define language_factory

#include "language.h"
#include "language/english/english.h"

class LanguageFactory
{
public:
    static Language* createConnection(eConnectionType connectionType);
};

#endif 