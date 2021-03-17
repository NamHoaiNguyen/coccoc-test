#include "../../include/factory/language_factory.h"
 
#include <iostream>


std::shared_ptr<Language>LanguageFactory::createConnection(eConnectionType connectionType)
{
    std::shared_ptr<Language> language;
    switch (connectionType)
    {
    case ENGLISH:
    {
        language = std::make_shared<English>();
        break;
    }
    case VIETNAMESE:
    {
        language = std::make_shared<Vietnamese>();
        break;
    }
    default:
        language = std::make_shared<English>(); // default is english
        break;
    }
 
    return language;
}