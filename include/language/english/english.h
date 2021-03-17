#ifndef include_english_english
#define include_english_english

#include <string>
#include <vector>

#include "../language.h"

class English : public Language {
public:
    English();

    std::vector<std::string> ten_eng;
    std::vector<std::string> less_than_20_eng;
    std::vector<std::string> thousands_eng;

    virtual std::string get_tens(int num) override;
    virtual std::string get_less_than_20(int num) override;
    virtual std::string get_thousands(int num) override;
    virtual std::string get_hundred() override;
    virtual std::string get_negative() override;
    virtual std::string get_hyphen() override;
    virtual std::string get_zero() override;
};

#endif