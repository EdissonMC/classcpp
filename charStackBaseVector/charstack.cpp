/*

    File: charstack.cpp
    ___________________
    This file implements the CharStack class using a Vector<char>
    as the unerlying representation. 
    The Vector class already implements most of the essential operations
    for the CharStack class, which can simply forward the request on to the underlying structure.
    The methods are short enough to require no detailed documentation

*/

#include "charstack.h"
#include <vector>
#include <iostream>

CharStack::CharStack() {

}

CharStack::~CharStack() {

}

int CharStack::size() {
    return elements.size();
}


bool CharStack::isEmpty() {

    return elements.empty();
}

void CharStack::clear() {
    elements.clear();
}


void CharStack::push(char ch) {
   // std::cout <<"\nadding a value..\n";
    elements.push_back(ch);
}



char CharStack::pop() {
    
    if(isEmpty()) {
        std::cout << "Error Attempting to pop an empty stack";
    }

    char result = elements.back();
   // auto index  = elements.end() ;
    elements.pop_back();

    return result;
}




char CharStack::peek() {
    if(isEmpty()) {
        std::cout << "Error Attempting to pop an empty stack";
    }
    char result = elements.back();
    return result;

}