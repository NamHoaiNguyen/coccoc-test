#ifndef number_to_text
#define number_to_text

#include <algorithm>
#include <climits>
#include <iostream>
#include <string>

#define NUMBER_EMPTY    0
#define NUMBER_POSITIVE 1
#define NUMBER_NEGATIVE 2
#define NOT_NUMBER      3   

class Convert {
private:
    std::string lang;

public:
    Convert();
    virtual std::string convert_number_to_text(const std::string &s) = 0;
    virtual std::string helper(std::string num) = 0;

protected:
    std::string triple_zero = {"000"};

};

#endif