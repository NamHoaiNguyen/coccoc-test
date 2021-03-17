#include "../../../include/language/vietnam/vietnamese.h"

Vietnamese::Vietnamese()
{
    ten_vie = {"", "muoi", "hai muoi", "ba muoi", "bon muoi", "nam muoi",
                 "sau muoi", "bay muoi", "tam muoi", "chin muoi"};

    less_than_20_vie = {"", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin", "muoi",
                         "muoi mot", "muoi hai", "muoi ba", "muoi bon", "muoi lam", "muoi sau",
                         "muoi bay", "muoi tam", "muoi chin"};

    thousands_vie = { "", "nghin", "trieu", "ti", "tram ti", "nghin ti", "trieu ti", "ti ti",
                    "tram ti ti", "nghin ti ti", "trieu ti ti", "ti ti ti", "tram ti ti ti",
                    "nghin ti ti ti", "trieu ti ti ti", "ti ti ti ti", "tram ti ti ti ti",
                    "nghin ti ti ti ti", "trieu ti ti ti ti", "ti ti ti ti ti",
                    "tram ti ti ti ti ti"};                                     
}

std::string Vietnamese::get_tens(int num)
{
    return ten_vie[num];
}

std::string Vietnamese::get_less_than_20(int num)
{
    return less_than_20_vie[num];
};

std::string Vietnamese::get_thousands(int num)
{
    return thousands_vie[num];
}

std::string Vietnamese::get_hundred()
{
    return " tram ";
}

std::string Vietnamese::get_negative()
{
    return "am ";
}

std::string Vietnamese::get_hyphen()
{
    return " ";
}

std::string Vietnamese::get_zero()
{
    return "khong";
}