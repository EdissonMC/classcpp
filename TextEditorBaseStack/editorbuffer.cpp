
/*
    
    File : buffer.cpp (array version)
    _________________________________
    This file implements the buffer.h interface using an array representation

*/


#include <iostream>
#include "charstack.h"
#include "editorbuffer.h"
#include <string>


/*

    Implementation notes: Constructor and destructor
    ________________________________________________
    In this implementation, all dynamic allocation is managed by the CharStack class,
    wich means there is no work for EditorBuffer to do.

*/

    EditorBuffer::EditorBuffer() { }


    EditorBuffer::~EditorBuffer(){ }







/*
    Implementation notes: moveCursor methods
    ________________________________________
    The four moveCursor methods simply the value of cursor
*/
    void EditorBuffer::moveCursorForward() {
       if(!after.isEmpty()) {
           before.push(after.pop());
       }
    }


    void EditorBuffer::moveCursorBackward() {
        
        if(!before.isEmpty()) {
           after.push(before.pop());
        }
    }


    void EditorBuffer::moveCursorToStart() {
        
        while(!before.isEmpty()) {
            after.push(before.pop());
        }
          
    }

    void EditorBuffer::moveCursorToEnd() {
        
        while(!after.isEmpty()) {
            before.push(after.pop());
        }
    }





/*
    Implementation notes:  character insertion and deletion
    _______________________________________________________
    Each of the functions that inserts or deletes characters
    can do so with a single push or pop operation

*/
    
    void EditorBuffer::insertCharacter(char ch) {
    
        before.push(ch);

    }


    void EditorBuffer::deleteCharacter() {

        if(!after.isEmpty()) {
            after.pop();
        }
    }


/*
    Simple getter methods : getText,  getCursor
*/    

    std::string EditorBuffer::getText() const {
        
        
        CharStack beforeCopy = before;
        CharStack afterCopy = after;

        std::string str = "";
        
        while (!beforeCopy.isEmpty()) {
            str = beforeCopy.pop() + str;
        }

        while (!afterCopy.isEmpty()) {
            str += afterCopy.pop() ;
        }

        return str;
    }



    int EditorBuffer::getCursor ()  {
        
        return before.size();
    }



    
