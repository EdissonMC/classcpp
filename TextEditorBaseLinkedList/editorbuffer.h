
/*
    
    File: editorbuffer.h
    _____________________
    This file defines the interface for the EditorBuffer class

*/

#ifndef _buffer_h
#define _buffer_h
#include "charstack.h"

/*

    Class: EditorBuffer
    ___________________
    This class represents an editor buffer, which maintains an ordered
    sequence of characters along with an insertion point called the cursor.

*/

class EditorBuffer
{
    private:

        /*
            
            Implementation notes: Buffer data structure
            ___________________________________________
            In the linked-list implementation of the buffer , the characters
            in the buffer are stored in a list of Cell structures, 
            each of which contains a character and a pointer to the next cell in the chain.
            To simplify the code used to maintain the cursor, 
            this implementation adds and extra "dummy" cell at the beginning of the list.
            The character in this cell is not used, but having it in the data structure provides a cell
            for the cursor to point to when the cursor is at the beginning of the buffer.

            The following diagram shows the structure of the list-based buffer
            containing "ABC" with the cursor at the beginning:

                    +-----+         +-----+        +-----+         +-----+        +-----+
            start   |  o--+-----===>|     |     -->|  A  |      -->|  B  |     -->|  C  |   
                    +-----+    /    +-----+    /   +-----+    /    +-----+   /    +-----+
            cursor  |  o--+----     |  o--+---     |  o--+----     |  o--+---     |  /  |
                    +-----+         +-----+        +-----+         +-----+        +-----+
        
        */


       /*
            
            Type : Cell
            ___________
            This structure type is used locally within the implementation
            to store each cell in the linked-list representation.
            Each cell contains one character and a pointer to the next cell in the chain.

       */  
            struct Cell
            {
                char ch;
                Cell *link;
            };

            Cell *start;         /* Pointer to the dummy cell     */
            Cell *cursor;        /* Pointer to cell before cursor */



        /*  Make it illegal to copy editor buffers */
            EditorBuffer(const EditorBuffer & value) {}
            const EditorBuffer & operator=(const EditorBuffer & rhs) { return *this; }



    public:
        /*
            
            Constructor:  EditorBuffer
            Usage: EditorBuffer buffer;
            ___________________________
            Creates an empty editor buffer

        */
        EditorBuffer(/* args */);
        


        /*

            Destructor: ~EditorBuffer
            Usage: (usually implicit)
            _________________________
            Frees any heap storage associated with this buffer

        */
        ~EditorBuffer();
        
        
        /*
            Methods : moveCursorForward,  moveCursorBackward
            Usage:  buffer.moveCursorForward();
                    buffer.moveCursorBackward();
            ___________________________________
            These functions move the cursor forward or backward one character, respectively.
            If the command would shift the cursor beyond either 
            end of the buffer, this method has no effect.

       */
        void moveCursorForward();
        void moveCursorBackward();




        /*
            Methods: moveCursorToStart, moveCursorToEnd
            Usage:  buffer.moveCursorToStart();
                    buffer.moveCursorToEnd();
            _________________________________
            These functions move the cursor to the start or the end of this buffer
        */
        void moveCursorToStart();
        void moveCursorToEnd();

        
        
        /*
            
            Method: insertCharacter
            Usage : buffer.insertCharacter(ch);
            ___________________________________
            Inserts the character ch into this buffer at the cursor position,
            leaving the cursor after the inserted character.

        */
        void insertCharacter(char ch);




        /*

            Method: deleteCharacter
            Usage:  buffer.deleteCharacter();
            ________________________________
            Deletes the character immediately after the cursor, if any.

        */
       void deleteCharacter();



        /*
            Method: getText
            Usage: string str= buffer.getText();
            ___________________________________
            Returns the contents of the buffer as a string
        */
        std::string getText() const;




        /*
            Method: getCursor
            Usage: int cursor = buffer.getCursor();
            ______________________________________
            Return the index of the cursor.
        */  
        int getCursor() ;//const


};


#endif
