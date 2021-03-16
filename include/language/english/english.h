#ifndef include_english_english
#define include_english_english

#include <string>
#include <vector>
#include "../../language.h"

class English : public Language {
public:
    // static std::string tens_eng[];

    // static std::string less_than_20_eng[];

    // static std::string thousands_eng[];

    English();

    std::vector<std::string> ten_eng;
    std::vector<std::string> less_than_20_eng;
    std::vector<std::string> thousands_eng;

    virtual std::string get_tens_eng (int num) override;
    virtual std::string get_less_than_20_eng(int num) override;
    virtual std::string get_thousands_eng(int num) override;
};

#endif