#include "../../../include/language/vietnam/number_to_text_vietnamese.h"
#include <cfenv>

ConvertVietnamese::ConvertVietnamese(int check_number, std::string string_num) : check_number{check_number}, num{string_num}
{

}

std::string tenss[] = {"", "muoi", "hai muoi", "ba muoi", "bon muoi", "nam muoi",
 "sau muoi", "bay muoi", "tam muoi", "chin muoi"};

std::string less_than_20s[] = {"", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin", "muoi",
 "muoi mot", "muoi hai", "muoi ba", "muoi bon", "muoi lam", "muoi sau", "muoi bay", "muoi tam", "muoi chin"};

std::string thousandss[] = { "", "nghin", "trieu", "ti", "nghin ti", "trieu ti", "ti ti"}; 

std::string operator% (std::string &a, int b)
{
    return a.substr(a.length() - log10(b));
}

std::string operator/ (std::string &a, int b)
{
    return a.substr(0, a.length() - log10(b));
}

std::string ConvertVietnamese::helper(int num)
{
    if(num == 0) return "";
    else if (num < 20)
        return less_than_20s[num] + " ";
    else if (num < 100)
        return tenss[num / 10] + " " + helper(num % 10);
    else
        return less_than_20s[num / 100]+ " tram " + helper(num % 100);
}

std::string ConvertVietnamese::convert_number_to_text(const std::string &s)
{
    long long  num;
    int i = 0;
    std::string res= "";
    // num.assign(s);

    if (this->check_number == NUMBER_EMPTY) 
        return "String Empty";
    else if (this->check_number == NOT_NUMBER) 
        return "Wrong Input";
    else if (this->check_number == NUMBER_POSITIVE) {
        try{ 
            // num = std::stoull(s);
    
            // if (num == 0) return "zero";
        
            while(num > 0){
                if(num % 1000 != 0)
                    res= helper(num % 1000) + thousandss[i] + " " + res;
                num /= 1000;
                i++;
            }
        } catch(const std::out_of_range& e){ 
            std::cout << "Out of Range error."<< std::endl;
        }
    }    
    else if (this->check_number = NUMBER_NEGATIVE){
        try{
            // num = std::stoll(s);
            // num = std::abs(num);
            
            while(num > 0){
                if(num % 1000 != 0)
                    res = helper(num % 1000) + thousandss[i] + " " + res;
                num /= 1000;
                i++;
            }
            res.insert(0, "am ");

        } catch(const std::out_of_range& e){ 
            std::cout << "Out of Range error."<< std::endl;
        }
    }
     
    return res.substr(0, res.find_last_not_of(' ') + 1);
}