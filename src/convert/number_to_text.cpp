#include "../../include/convert/number_to_text.h"

Convert::Convert(int check_number, std::shared_ptr<Language>language) : check_number{check_number}, lang{language}
{

}


std::string operator% (std::string &a, int b)
{
    if (a.length() <= log10(b)) return a;
    else return a.substr(a.length() - log10(b));
}

std::string operator/ (std::string &a, int b)
{
    if (a.length() <= log10(b)) return std::to_string(0);
    else return a.substr(0, a.length() - log10(b));
}


bool operator>(std::string &a, std::string &b)
{
    for (int i = 0; i < a.length(); i++) {
        if ((a[i] - '0') < (b[i] - '0')) {
            return false;
        }
    }
    return true;
}

bool operator<(std::string &a, std::string &b)
{
    for (int i = 0; i < a.length(); i++) {
        if ((a[i] - '0') > (b[i] - '0')) {
            return false;
        }
    }
    return true;
}

bool operator!=(std::string &a, std::string &b) 
{
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            return true;
        }
    }
    return false;
}

bool operator==(std::string &a, int b) 
{
    for (int i = 0; i < a.length(); i++) {
        if ((a[i] - '0') != b) {
            return false;
        }
    }
    return true;
}

std::string Convert::helper(std::string test)
{
    int num;
    std::string check_last_number_position;

    num = std::stoll(test);

    if(num == 0) return "";
    else if (num < (20))
    /*tenmillion*/
        return lang->get_less_than_20(num) + " ";
    else if (num < (100)) {
        std::string check_last_number_position = helper((std::to_string(num % (10))));
    
        if (check_last_number_position == "")
            return lang->get_tens(num / 10) + " ";
        else 
            return lang->get_tens(num / 10) + lang->get_hyphen() + helper((std::to_string(num % (10))));
    }
    else
        if (helper((std::to_string(num % 100))) == "")
            return lang->get_less_than_20(num / 100) + lang->get_hundred();
        else 
            return lang->get_less_than_20(num / 100) + lang->get_hundred() + helper((std::to_string(num % 100)));
}

std::string Convert::convert_number_to_text(std::string num)
{
    int i = 0;
    std::string res= "";

    if(num == 0) return lang->get_zero();

    if (this->check_number == NUMBER_EMPTY) 
        return "String Empty";
    else if (this->check_number == NOT_NUMBER) 
        return "Wrong Input. Please type number!!!";

    /*Positive number*/
    else if (this->check_number == NUMBER_POSITIVE) {
        while(num > std::to_string(0)){
            if(num % 1000 != Language::triple_zero) {
                res = helper(num % 1000) + lang->get_thousands(i) + " " + res;
            }
            num = num / 1000;

            int count = 0;
            
            for (auto &e : num) {
                if (e == '0') count ++;
            }
            if (num.length() == count) break;
            
            i++;
        }
    }    
    /*Negative number*/
    else if (this->check_number = NUMBER_NEGATIVE){
        /*Remove '-' character*/
        num.erase(std::remove_if(num.begin(), num.end(), [](auto x){return x == '-';}));

        if (num == 0) return "Wrong Fomat(Not Having -0)!!!";

        while(num > std::to_string(0)){
            if((num % 1000) != Language::triple_zero) {
                res = helper(num % 1000) + lang->get_thousands(i) + " " + res;
            }
            num = num / 1000;
            int count = 0;
            
            for (auto &e : num) {
                if (e == '0') count ++;
            }
            if (num.length() == count) break;
            
            i++;
        }
        res.insert(0, lang->get_negative());  
    }
     
    return res.substr(0, res.find_last_not_of(' ') + 1);
}