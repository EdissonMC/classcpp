
/*
    
    File : buffer.cpp (array version)
    _________________________________
    This file implements the buffer.h interface using an array representation

*/


#include <iostream>
#include "editorbuffer.h"
#include <string>

/*

    Implementation notes: Constructor and destructor
    ________________________________________________
    The consturctor initializes the private fields.  The destructor
    frees the heap-allocated memory,  which is the dynamic array.

*/

    EditorBuffer::EditorBuffer() {

        std::cout <<"\n--Testing editorbuffer--\n";
        capacity = 10  ;//INITIAL_CAPACITY;
        array  =  new char[capacity];
        
        if (array == nullptr)
            std::cout << "Error: memory could not be allocated";
        
    

        length = 0;
        cursor = 0;


        //   array[0]='A';
        // array[1]='B';
        // array[2]='C';

        // char *pointerTest0 =  &array[0];  //140732674991944
        // char *pointerTest1 =  &array[1];  //140732674991936
        // char *pointerTest2 =  &array[2];  //140732674991928

        // std::cout << "array address  " << &array ;

        // std::cout << "\npointer0 test address  " << &pointerTest0 <<"\n";
        // std::cout << "\npointer1 test address  " << &pointerTest1 <<"\n";
        // std::cout << "\npointer2 test address  " << &pointerTest2 <<"\n";


        //  delete[] array;


    }


    EditorBuffer::~EditorBuffer(){
        
        std::cout <<"\n\n--Go out of the scope EditorBuffer--\n\n";

        // std::cout << "array address" << array ;
        // if (array == nullptr)
        //     std::cout << "Error: memory could not be allocated";
        
    


        // char *otherarray  =  new char[capacity];
        // delete[] otherarray;
    }







/*
    Implementation notes: moveCursor methods
    ________________________________________
    The four moveCursor methods simply the value of cursor
*/

    void EditorBuffer::moveCursorForward() {
        if(cursor < length) cursor++;
    }


    void EditorBuffer::moveCursorBackward() {
        if(cursor > 0) cursor--;
    }


    void EditorBuffer::moveCursorToStart() {
        cursor = 0;
    }

    void EditorBuffer::moveCursorToEnd() {
        cursor = length;
    }





/*
    Implementation notes:  character insertion and deletion
    _______________________________________________________
    Each of the functions that inserts or deletes characters must shift
    all subsequent characters in the array, either to make room for new 
    insertions or to close up space left by deletions

*/

    void EditorBuffer::insertCharacter(char ch) {
        
            if(length == capacity) expandCapacity();

        //  Moves all the characters after current cursor postion
            for(int i= length ; i> cursor; i--) {
                array[i] = array[i-1];
            }

        //  Set a new character in the position cursor
            array[cursor] = ch;

        //  Update length and cursor values    
            length++;
            cursor++;

    }


    void EditorBuffer::deleteCharacter() {

        if(cursor < length) {
            
            // This for loop set all the characters after of current curson position,
            // one position inmediatly before of the his own current position 
            for (int i = cursor+1;  i<length; i++) {
                array[i-1] = array[i];
            }

            length--;
        }
    }


/*
    Simple getter methods : getText,  getCursor
*/    

std::string EditorBuffer::getText() const {
    return std::string(array, length);
}

int EditorBuffer::getCursor () const {
    return cursor;
}

/*
    Implementation notes:  expandCapacity
    _____________________________________
    This private method doubles the size of the array  whenever the old one runs out of space.
    To do so,  expandCapacity allocates  a new array, copies the old characters to the new array, 
    and then frees the old array.

*/


void EditorBuffer::expandCapacity() {

    //  Create a pointer for store the old array reference pointer
        char *oldArray = array;
    
    //  Double the capacity number
        capacity *=2;

    //  Allocate memory with the double of capacity for the array variable
        array = new char[capacity];

    //  Make a deep copy of the data of the old array inside the new allocated memory
        for(int i =0;  i< length; i++) {
            array[i] = oldArray[i];
        }

    delete[] oldArray;
}