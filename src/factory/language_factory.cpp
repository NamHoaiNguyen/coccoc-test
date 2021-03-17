#include "../../include/factory/language_factory.h"
 
#include <iostream>

Language* LanguageFactory::createConnection(eConnectionType connectionType)
{
    Language *language = nullptr;
 
    switch (connectionType)
    {
    case ENGLISH:
    {
        language = new English();
        break;
    }
    case VIETNAMESE:
    {
        language = new Vietnamese();
        break;
    }
    default:
        language = new English(); // default is language
        break;
    }
 
    return language;
}