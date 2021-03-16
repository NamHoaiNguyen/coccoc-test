#include "../include/language_factory.h"
 
#include <iostream>

Language* LanguageFactory::createConnection(eConnectionType connectionType)
{
    Language *language = nullptr;
 
    switch (connectionType)
    {
    case ENGLISH:
    {
        language = new English();
        // English *e = dynamic_cast<English*>(language);
        // English e;
        // std::cout << "deo hieu "<< std::endl;
        // std::cout << language->get_tens_eng(6) << std::endl;
        break;
    }
    default:
        language = new English(); // default is language
        break;
    }
 
    return language;
}