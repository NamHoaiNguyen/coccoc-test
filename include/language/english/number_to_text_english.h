#ifndef number_to_text_english
#define number_to_text_english

#include <algorithm>
#include <string>

#include "../../language/number_to_text.h"
#include "math.h"

class ConvertEnglish : public Convert {

private:
    int check_number;

public:
    ConvertEnglish(int check_number);
    std::string convert_number_to_text(const std::string &s) override;
    std::string helper(std::string num) override;
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