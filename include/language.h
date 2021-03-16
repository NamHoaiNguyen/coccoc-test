#ifndef include_language
#define include_language

#include <string>
#include <vector>
#include <iostream>

enum eConnectionType
{
    ENGLISH = 0,
    VIETNAMESE,
};

class Language
{
public:
    Language();
    virtual std::string get_tens_eng(int num);
    virtual std::string get_less_than_20_eng(int num);
    virtual std::string get_thousands_eng(int num);
};

#endif 

