#include "../../../include/language/english/english.h"

English::English()
{
    ten_eng = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    less_than_20_eng = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven",
                         "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    
    thousands_eng = { "", "thousand", "million", "billion", "trillion", "quadrillion", "quintillion", "sextillion",
                        "septillion", "octillion", "nonillion", "decillion", "undecillion", "duodecillion", 
                        "tredecillion", "quindecillion", "sexdecillion", "septen-decillion", "octodecillion",
                        "novemdecillion", "vigintillion"};                                     
}

std::string English::get_tens(int num)
{
    return ten_eng[num];
}

std::string English::get_less_than_20(int num)
{
    return less_than_20_eng[num];
};

std::string English::get_thousands(int num)
{
    return thousands_eng[num];
}

std::string English::get_hundred()
{
    return " hundred ";
}

std::string English::get_negative()
{
    return "minus ";
}

std::string English::get_hyphen()
{
    return "-";
}