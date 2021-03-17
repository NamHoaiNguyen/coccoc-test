#ifndef number_to_text_english
#define number_to_text_english

#include <algorithm>
#include <memory>
#include <string>

#include "../language/language.h"
#include "math.h"

#define NUMBER_EMPTY    0
#define NUMBER_POSITIVE 1
#define NUMBER_NEGATIVE 2
#define NOT_NUMBER      3   

class Convert  {

private:
    int check_number;
    std::shared_ptr<Language>lang;

public:
    Convert(int check_number, std::shared_ptr<Language>language);
    std::string convert_number_to_text(std::string s);
    std::string helper(std::string num) ;

    friend std::string operator% (std::string &a, int b);
    friend std::string operator/ (std::string &a, int b);
    friend bool operator> (std::string &a, std::string &b);
    friend bool operator< (std::string &a, std::string &b);
    friend bool operator== (std::string &a, int b);
    friend bool operator!= (std::string &c1, std::string &c2);
};

#endif 