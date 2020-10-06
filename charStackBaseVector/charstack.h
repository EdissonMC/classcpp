/*
   
    File: charstack.h
    __________________
    This interface defines the charStack class, which implements the
    stack abastraction for characters.

    This version of the CharStack class uses a Vector<char> as its
    underlying representation. Characters are always added and 
    removerd from the end, which gives rise to the last-in/fist-out
    bechavior that is characteristic of stacks

*/

#ifndef _charstack_h
#define _charstack_h
#include <vector>

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
        
        std::vector<char> elements; /* Data structure to hold the stack elemements */
};





#endif
