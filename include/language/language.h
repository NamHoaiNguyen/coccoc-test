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

    virtual std::string get_tens(int num);
    virtual std::string get_less_than_20(int num);
    virtual std::string get_thousands(int num);
    virtual std::string get_hundred();
};

#endif 

