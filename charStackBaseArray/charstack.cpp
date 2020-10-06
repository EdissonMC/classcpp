/*

    File: charstack.cpp
    ___________________
    In this version of CharStack, the characters are stored in a dynamic array
    that doubles in size whenever the stack runs out of space.

    The Vector class already implements most of the essential operations
    for the CharStack class, which can simply forward the request on to the underlying structure.
    The methods are short enough to require no detailed documentation

    
*/
#include <iostream>

#include "charstack.h"


/*
    Implementation notes: constructor and destructor
    ________________________________________________
    The constructor must allocate the array storage for the stack elements
    and initialize the fields of the object.
    The destructor frees any heap memory allocated by the class, 
    which is just the array of elements

*/
CharStack::CharStack() {
    capacity = INITIAL_CAPACITY;
    array = new char[capacity];
    count = 0;
}


/*
    Implementation notes: ~CharStack
    ________________________________
    The destructor frees any heap memory allocated by the class, 
    which is just the dynamic array of elements.

*/
CharStack::~CharStack() {
    delete[] array;
}




/*
    Implementation notes: size, isEmpty, clear
    __________________________________________
    These methods are each a single line and need no detailed documentation
*/
int CharStack::size() {
    return count;
}


bool CharStack::isEmpty() {

    return count == 0;
}

void CharStack::clear() {
    count = 0;
}




/*
    Implementation notes: push
    __________________________
    This function must firts check to see whether there is enough room for
    the character and expand the array storage if necessary.
*/

void CharStack::push(char ch) {
   if (count == capacity) expandCapacity();  // call expandCapacity for make more room for new characters

   array[count++] = ch;
}





/*
    
    Implementation notes: pop, peek
    _______________________________
    These functions must check for an empty stack and report an error 
    if there is no top element.

*/
char CharStack::pop() {
    
    if(isEmpty()) {
        std::cout << "Error Attempting to pop an empty stack";
    }

    return array[--count];  // note here the count variable get a new value
}




char CharStack::peek() {
    if(isEmpty()) {
        std::cout << "Error Attempting to pop an empty stack";
    }
  
    return array[count-1]; // note here count its no modified , only used

}


/*
    Implementation notes: expandCapacity
    ____________________________________
    This private method doubles the capacity of the elements array whenever
    it runs out of space. To do so, it must the pointer to the old array,
    allocate a new array with twice the capacity, copy the characters from the old array
    to the new one, and finally free the old storage.

*/

void CharStack::expandCapacity() {

    char *oldArray = array;
    capacity *=2;
    array =  new char[capacity];  // Allocate double of the old capacity in the heap memory


    // Refill the new array in the new allocated space
    for (int i = 0; i< count; i++) {
        array[i] = oldArray[i];
    }

    delete[] oldArray;  // Deleted the old memory allocated for the Array
}