#ifndef number_to_text_vietnamese
#define number_to_text_vietnamese

#include <algorithm>
#include <string>

#include "../../language/number_to_text.h"
#include "math.h"

class ConvertVietnamese : public Convert {

private:
    int check_number;
    std::string num;

public:
    ConvertVietnamese(int check_number, std::string string_num);
    std::string convert_number_to_text(const std::string &s) override;
    std::string helper(int num);
    void convert_to_word(int n, std::string s);

    friend std::string operator% (std::string &a, int b);
    friend std::string operator/ (std::string &a, int b);

};

#endif