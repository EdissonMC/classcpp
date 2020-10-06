
#include <iostream>
#include <string>
#include <set>
#include <iterator> 
#include "mycctype.h"



mycctype::mycctype ():   
    DIGIT_SET(setFromString("0123456789")), 
    LOWER_SET(setFromString("abcdefghijklmnopqrstuvwxyz")),
    UPPER_SET(setFromString("ABCDEFGHIJKLMNOPQRSTUVWXYZ")),
    PUNCT_SET(setFromString("!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}")),
    SPACE_SET(setFromString("\t\v\f\n\r")),
    XDIGIT_SET(setFromString("0123456789ABCDEFabcdef")),
    ALPHA_SET(setFromString("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")),
    ALNUM_SET(setFromString("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")),
    PRINT_SET(setFromString("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}\t\v\f\n\r"))

{
    
    std::cout << "prueba cctype" <<std::endl;

    std::set <char > :: iterator itr; 
    std::cout << "\nThe set s1 is : "; 

    for (itr = PRINT_SET.begin(); itr != PRINT_SET.end(); ++itr) 
    { 
        std::cout << '\t' << *itr; 
    } 
    std::cout << std::endl; 
  
}



std::set<char>  mycctype::setFromString(std::string str) {

    std::set<char> set;
    for (int i =0 ; i < str.length(); i++) {
        set.insert(str[i]);
    }
    return set;
}


bool mycctype::isalnum(char ch) {
    return ALNUM_SET.count(ch);
}


bool mycctype::isalpha(char ch) {
    return ALPHA_SET.count(ch);
}

bool mycctype::isdigit(char ch) {
    return DIGIT_SET.count(ch);
}



bool mycctype::islower(char ch) {
    return LOWER_SET.count(ch);
}


bool mycctype::isprint(char ch) {
    return PRINT_SET.count(ch);
}


bool mycctype::ispunct(char ch) {
    return PUNCT_SET.count(ch);
}


bool mycctype::isspace(char ch) {
    return PUNCT_SET.count(ch);
}

bool mycctype::isupper(char ch) {
    return UPPER_SET.count(ch);
}

bool mycctype::isxdigit(char ch) {
    return XDIGIT_SET.count(ch);
}


