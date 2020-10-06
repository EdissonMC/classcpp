#ifndef mycctype_Included
#define mycctype_Included

#include <string>
#include <set>

/*

    This program simuates the <cctype> interface using set of characters.

*/


class mycctype {

    private:
    std::set<char> setFromString(std::string str);
    const std::set<char> LOWER_SET;
    const std::set<char> DIGIT_SET;
    const std::set<char> UPPER_SET;
    const std::set<char> PUNCT_SET;
    const std::set<char> SPACE_SET;
    const std::set<char> XDIGIT_SET;
    const std::set<char> ALPHA_SET;
    const std::set<char> ALNUM_SET;
    const std::set<char> PRINT_SET;



    public :
    mycctype();
    bool isalnum(char ch);
    bool isdigit(char ch);
    bool isalpha(char ch);
    bool islower(char ch);
    bool isprint(char ch);
    bool ispunct(char ch);
    bool isspace(char ch);
    bool isupper(char ch);
    bool isxdigit(char ch);


};


#endif
