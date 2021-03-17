#ifndef number_to_text_english
#define number_to_text_english

#include <algorithm>
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
    Language *lang;
    // Language *Language;

public:
    Convert(int check_number, Language *language);
    std::string convert_number_to_text(const std::string &s);
    std::string helper(std::string num) ;
    void convert_to_word(int n, std::string s);

    friend std::string operator% (std::string &a, int b);
    friend std::string operator/ (std::string &a, int b);
    friend bool operator> (std::string &a, std::string &b);
    friend bool operator< (std::string &a, std::string &b);
    friend bool operator== (std::string &a, std::string &b);
    friend bool operator!= (std::string &c1, std::string &c2);

    // const std::string& operator[] (std::string &index) const;

};

#endif 