#include "../include/convert/number_to_text.h"
#include "../include/factory/language_factory.h"
#include "../include/language/language.h"

int check_number(const std::string &s) 
{
    std::string::const_iterator it;
    if (s.empty())  return NUMBER_EMPTY;

    if (std::find_if(s.begin(), s.end(), [](auto elem){return ((!std::isdigit(elem)));}) == s.end()) {
        return NUMBER_POSITIVE;
    } 

    it = s.begin();
    if (s[0] == '-') it++;
    for (; it != s.end(); it++) {
        if (!std::isdigit(*it)) {
            return NOT_NUMBER;
        }
    }

    return NUMBER_NEGATIVE;
}

int main()
{
    std::string number;
    std::string option;
    static std::string language;
    Language *Language;
    
    while (true) {
        std::cout << "Input Number (type exit if want to stop)" << std::endl;
        std::cin >> number;

        if (number.compare("exit") == 0) {
            std::cout << "Exit" << std::endl;
            break;
        }

        while(true) {
            std::cout << "Use Default Language(English) ? (yes or no)" << std::endl;
            std::cin >> option;
        
            /*Lowercase*/
            std::transform(option.begin(), option.end(), option.begin(), [](char c){return std::tolower(c) ;});
        
            if (option.compare("yes") == 0) {
                Language = LanguageFactory::createConnection(ENGLISH);
                Convert conv(check_number(number), Language);

                std::cout << conv.convert_number_to_text(number) << std::endl;
                break;
            }else if (option.compare("no") == 0) {
                while (true) {
                    std::cout << "Choosing language (vietnam)" << std::endl;
                    std::cin  >> language; 
                
                /*Lowercase*/
                    std::transform(language.begin(), language.end(), language.begin(), [](char c){return std::tolower(c) ;});
                    if (language.compare("vietnam") == 0) {
                        Language = LanguageFactory::createConnection(VIETNAMESE);
                        Convert conv(check_number(number), Language);
                        std::cout << conv.convert_number_to_text(number) << std::endl;
                        break;
                    }
                    else {
                        std::cout << "Please choose the language!!!" << std::endl;
                    }
                }
            } else {
                std::cout << "Choose yes or no" << std::endl;
            }
        }
    }

    return 0;
}