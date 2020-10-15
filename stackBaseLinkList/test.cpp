#include <iostream>
#include "stack.h"





int main() {
    std::cout<<"Testing my stack implementation";
    stack<int> myStack;


    
    std::cout<<"- STARTED size ARRAY - is :" <<myStack.size() <<"\n";
     

    std::cout <<"adding data to the stack, using numbers\n\n";
    for(int i=0 ; i<15; i++){
        std::cout <<i<<"\n";
        myStack.push(i);
    }



     std::cout<<"- Now the size ARRAY - is :" <<myStack.size() <<"\n";
    int original_size = myStack.size();

    std::cout <<" showing the numbers using peek() in the stack\n\n";
    int dato=0;
    for(int i=0 ; i< original_size; i++) {
        dato = myStack.peek();
        std::cout <<"index"<< i <<" : " <<dato <<"\n";
    }


     std::cout<<"- Now the size ARRAY - is :" <<myStack.size() <<"\n";
    std::cout <<"showing the numbers using pop() in the stack\n\n";
    dato=0;
    for(int i=0 ; i< original_size ; i++) {
        dato = myStack.pop();
       std::cout <<" index " << i <<" : " << dato <<"\n";
    }

    

    std::cout<<"- Now the size ARRAY - is :" <<myStack.size() <<"\n";

    return 0;
}