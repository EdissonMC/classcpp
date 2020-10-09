
/*
    
    File: editorbuffer.h
    _____________________
    This file defines the interface for the EditorBuffer class

*/

#ifndef _buffer_h
#define _buffer_h


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
            In the array-based implementation of the buffer, the characters 
            in the buffer are stored in a dynamic array. In addition to the array, 
            the struucture keeps track of the capacity of the buffer, 
            the length of the buffer , and the cursor position.  
            The cursor position is the index of the character that follows 
            where the cursor would appear on the screen. 
        
        */

        /*  Constants */
            static const int INITIAL_CAPACITY = 10;
        
        
        /*  Instance variables  */
            char *array;    /* Dynamic array of characters     */
            int capacity;   /* Allocated size of that array    */
            int length;     /* Number of character in buffer   */
            int cursor;     /* Index of character after cursor */


        /*  Make it illegal to copy editor buffers */
            EditorBuffer(const EditorBuffer & value) {}
            const EditorBuffer & operator=(const EditorBuffer & rhs) { return *this; }


        /*  Private method prototyp */
            void expandCapacity();


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
        int getCursor() const;


};


#endif
