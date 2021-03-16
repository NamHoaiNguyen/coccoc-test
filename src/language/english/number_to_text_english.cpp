#include "../../../include/language/english/number_to_text_english.h"

ConvertEnglish::ConvertEnglish(int check_number) : check_number(check_number)
{

}

std::string tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

std::string less_than_20[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

std::string thousands[] = { "", "thousand", "million", "billion", "trillion", "quadrillion", "quintillion", "sextillion",
"septillion", "octillion", "nonillion", "decillion", "undecillion", "duodecillion", "tredecillion", "quindecillion", 
"sexdecillion", "septen-decillion", "octodecillion", "novemdecillion", "vigintillion"}; 


std::string operator% (std::string &a, int b)
{
    if (a.length() <= log10(b)) return a;
    else return a.substr(a.length() - log10(b));
}

std::string operator/ (std::string &a, int b)
{
    std::cout << "Do dai string " << a.length() - log10(b) << std::endl;;
    if (a.length() <= log10(b)) return std::to_string(0);
    else return a.substr(0, a.length() - log10(b));
}

// const std::string& ConvertEnglish::operator[] (std::string &a) const
// {
//     return less_than_20[std::stoll(a)];
// }


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
            return false;
        }
    }
    return true;
}

std::string ConvertEnglish::helper(std::string test)
{
    int num;
    std::string check_last_number_position;
    num = std::stoll(test);
    if(num == (0)) return "";
    else if (num < (20))
        return less_than_20[num] + " ";
    else if (num < (100)) {
        std::string check_last_number_position = helper((std::to_string(num % (10))));
        if (check_last_number_position == "")
            return tens[num / 10];
        else 
            return tens[num / 10] + "-" + helper((std::to_string(num % (10))));
    }
    else
        return less_than_20[num / 100]+ " hundred " + helper((std::to_string(num % 100)));
}

std::string ConvertEnglish::convert_number_to_text(const std::string &s)
{
    // long long num;
    std::string num;
    // int64_t num;
    int i = 0;
    std::string res= "";
    num.assign(s);

    if (this->check_number == NUMBER_EMPTY) 
        return "String Empty";
    else if (this->check_number == NOT_NUMBER) 
        return "Wrong Input";
    else if (this->check_number == NUMBER_POSITIVE) {
        // try{ 
            // num = std::stoll(s);
            // if (num == 0) return "zero";
        
            while(num > std::to_string(0)){
                if(num % 1000 != std::to_string(0))
                    res= helper(num % 1000) + thousands[i] + " " + res;
                std::cout << "Sao lai loi o day " << num << std::endl;

                num = num / 1000;
                std::cout << "check lock " << std::endl;
                i++;
                                std::cout << "check lock lan 2" << std::endl;

            }
        // } catch(const std::out_of_range& e){ 
            // std::cout << "Out of Range error."<< std::endl;
        // }
    }    
    else if (this->check_number = NUMBER_NEGATIVE){
        // try{
            // num = std::stoll(s);
            // num = std::abs(num);
            
            while(num > std::to_string(0)){
                if((num % 1000) != std::to_string(0))
                    res = helper(num % 1000) + thousands[i] + " " + res;
                std::cout << num << std::endl;

                num = num / 1000;
                i++;
            }
            res.insert(0, "minus ");

        // } catch(const std::out_of_range& e){ 
            // std::cout << "Out of Range error."<< std::endl;
        // }
    }
     
    return res.substr(0, res.find_last_not_of(' ') + 1);
}