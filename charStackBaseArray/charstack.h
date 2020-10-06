/*
   
    File: charstack.h
    __________________
    This interface defines the charStack class, which implements the
    stack abastraction for characters.
    In this version of CharStack, the characters are stored in a dynamic array
    that doubles in size whenever the stack runs out of space.

*/


#ifndef _charstack_h
#define _charstack_h





/*

    Class: charStack
    ________________
    This class models a stack of characters.  The fundamental operations
    are the same as those for the Stack<char> class

*/

class CharStack
{

    public:


        /*
            Constructor : CharStack
            Usage: CharStack cstk;
            ______________________
            Initializes a new empty stack that can contain characters
        */
        CharStack(/* args */);





        /*
            Destructor : ~CharStack
            Usage: (Usually implicit)
            ________________________
            Free any heap storage associated with this charater stack
        */
        ~CharStack();



        /*
            Method: Size
            Usage : int nElems = cstk.size();
            _________________________________
            Returns the number of characters in this stack
        */
        int size();


        /*
            Method: isEmpty
            Usage : if(cstk.isEmpty());
            _____________________
            Returns true if this stack contains no characters

        */
        bool isEmpty();


        /*

            Method: clear
            Usage : cstk.clear();
            _____________________
            Removes all characters from this stack.

         */
         void clear();


        /*

            Method: push
            Usage: cstk.push(value);
            ________________________
            Pushes the character ch  onto this stack
        */
        void push(char value);


        /*
            Method: pop
            Usage: char top = cstk.pop()
            __________________________________
            Removes the top character from this stack and returns it.

        */
       char pop();



       /*
       
            Method peek
            Usage: ValueType top = stack.peek();
            ____________________________________
            Returns the value of top character from this stack, 
            whithout remove it. 
            Raises an error if called on an empty stack.
       
       */
        char peek() ;



    private:
        
        /* Private constants */
            static const int INITIAL_CAPACITY = 10;

        /* Instance variables */
            char *array;          /* Dynamic array of characters   */
            int  capacity;         /* Allocated size of that array  */
            int  count;            /* Current count of chars pushed */

        
        /* Private function prototype */
            void expandCapacity();


};  





#endif
