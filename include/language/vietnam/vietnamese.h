#ifndef include_vietnam_vietnamese
#define include_vietnam_vietnamese

#include <string>
#include <vector>
#include "../language.h"

class Vietnamese : public Language {
public:
    Vietnamese();

    std::vector<std::string> ten_vie;
    std::vector<std::string> less_than_20_vie;
    std::vector<std::string> thousands_vie;

    virtual std::string get_tens (int num) override;
    virtual std::string get_less_than_20(int num) override;
    virtual std::string get_thousands(int num) override;
    virtual std::string get_hundred() override;
    virtual std::string get_negative() override;
    virtual std::string get_hyphen() override;
};

#endif