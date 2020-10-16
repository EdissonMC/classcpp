#include <iostream>
#include "stack.h"





int main() {
    std::cout<<"Testing my stack implementation\n";
    stack<int> myStack;

    std::cout <<"\n\n ADDING # 9 :";
    myStack.push(9);

    std::cout <<"\n\nADDING # 17:";
    myStack.push(17);
 
    std::cout <<"\n\nADDING # 32:";
    myStack.push(32);


    

    std::cout <<"\n SHOWING newStack: after copy myStack into newStack using operator= \n\n";
    // Way 1
    // In this case we pass the oldStack  through (=) operator to newStack,
    // but when this happen to the initialize this convert in the way of the
    // newStack(myStack).
    stack<int> newStack = myStack;
    

    // Way2
    // stack<int> newStack = myStack;
    // newStack = myStack;

    int dato=0;
    int original_size =newStack.size();
    std::cout <<"tamano : " << original_size <<"\n";
    for(int i=0 ; i< original_size ; i++) {
        dato = newStack.pop();
       std::cout <<" index " << i <<" : " << dato <<"\n";
    }



    // std::cout <<"ADDING: data to the stack, using numbers\n\n";
    // for(int i=0 ; i<5; i++){
    //     std::cout <<i<<"\n";
    //     myStack.push(i);
    // }



    // std::cout<<"- Now the size ARRAY - is :" <<myStack.size() <<"\n";
    
    // int original_size = myStack.size();

    // std::cout <<"SHOWING peek(): the numbers using peek() in the stack\n\n";
    // int dato=0;
    // for(int i=0 ; i< original_size; i++) {
    //     dato = myStack.peek();
    //     std::cout <<"index"<< i <<" : " <<dato <<"\n";
    // }


    // std::cout<<"- Now the size ARRAY - is :" <<myStack.size() <<"\n";


    // std::cout <<"SHOWING pop(): the numbers using pop() in the stack\n\n";
    // dato=0;
    // for(int i=0 ; i< original_size ; i++) {
    //     dato = myStack.pop();
    //    std::cout <<" index " << i <<" : " << dato <<"\n";
    // }

    

    


    // std::cout <<"SHOWING newStack: after copy myStack into newStack using operator= \n\n";
    // stack<int> newStack ;
    // newStack = myStack;

    // dato=0;
    // for(int i=0 ; i< original_size ; i++) {
    //     dato = newStack.pop();
    //    std::cout <<" index " << i <<" : " << dato <<"\n";
    // }



    // std::cout<<"- Now the size ARRAY - is :" <<myStack.size() <<"\n";

    return 0;
}