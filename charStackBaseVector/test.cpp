#include <iostream>
#include "charstack.h"



int main() {
    std::cout << "STARTING charstack TEST...";
    CharStack myCharStack ;
    
    myCharStack.push('a');
    myCharStack.push('b');
    myCharStack.push('c');

    std::cout <<"the size of charstack : " <<  myCharStack.size() << "\n"; 

    
    for ( ; !myCharStack.isEmpty(); ) {

        char tmp = myCharStack.pop();
        std::cout << tmp << "\n";
    
    }

    return 0;
}