#include <iostream>
#include "charstack.h"



int main() {
    std::cout << "STARTING charstack TEST...";
    CharStack myCharStack ;
    
    myCharStack.push('a');
    myCharStack.push('b');
    myCharStack.push('c');

    std::cout <<"the size of charstack : " <<  myCharStack.size() << "\n"; 


    std::cout << "\nshowing the last element in the myCharStack with peek: " <<  myCharStack.peek() << "\n"; 
    std::cout << "check that after call peek function, the last element was no delete \n\n";

    for ( ; !myCharStack.isEmpty(); ) {

        char tmp = myCharStack.pop();
        std::cout << tmp << "\n";
    
    }


    /* CREATING OTHE charStack VARIABLE TO TEST THE COPYCOSTRUCTOR */
    
    CharStack otherCharStack(myCharStack) ;

    return 0;
}