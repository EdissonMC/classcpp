/*
    File: stack.h
    _____________
    This interface exports a template version of the stack
    This version of the stack.h interface uses a linked list to store
    the elements of the stack. 
    The top item is always at the front of the linked list and 
    is therefore always accessible without searching.
    The private data also keeps track of the number of elements so that
    the size method runs in constant time.

*/

#ifndef _stack_h
#define _stack_h

#include <iostream>

/*
    Class : Stack<ValueType>
    ________________________
    This class implements a stack of the specified value type.
*/
template <typename ValueType>
class stack
{

    public:
        /*
            Constructor: Stack
            Usage: Stack<ValueType>  stack;
            ______________________________
            Initializes a new empty stack
        */
            stack(/* args */);
            stack(const stack<ValueType> & src);
            stack<ValueType>&  operator=(const stack<ValueType> & src); 



        /*
            Destructor: ~Stack
            Usage: (Usually implicit)
            _________________________
            Frees any heap storage associated with this stack
        */
            ~stack();


        /*
            Method: size
            Usage: int n = stack.size();
            ___________________________
            Returns the number of values in this stack
        */
            int size() const;



        /*
            Method: isEmpty
            Usage: if (stack.isEmpty())
            __________________________
            Returns true if this stacks contains no elements
        */
            bool isEmpty() const;
        

        /*
            Method: clear
            Usage: stack.clear();
            ____________________
            Removes all elements from this stack
        */
            void clear();

        /*
            Method: push
            Usage: stack.push(value);
            _________________________
            Pushes the specified value onto this stack
        */
            void push(ValueType value);



        /*
            Method: pop
            Usage: ValueType top = stack.pop();
            __________________________________
            Removes the top element from this stack and returns it.
            This method signals an error if called on an empty stack
        */
            ValueType pop();



        /*
            Method: peek
            Usage:  ValueType top = stack.peek();
            ____________________________________
            Returns the value of top element from this stack, without removing it. 
            This method signals an error if called on an empty stack.
        */           
            ValueType peek();


    private:
        
        /*  data  */    
            struct Cell {
                ValueType data;      /* The data value        */
                Cell *link;          /* Link to the next cell */
            };


        /*  Instance variables */
            Cell *list;            /* Initial pointer in the list */
            int size_elements;     /* Number of elements          */

            
        /*  Private method prototypes */
            void deepCopy (const stack<ValueType> & src);



};


/* ---------------------------  IMPLEMENTATION --------------------------------- */


/*
    Implementation section 
    ______________________
    C++ requires that the implementation for a template class be available
    to that compiler whenever that type is used. 
    The effect of this restriction is that header files must include the implementation.
    Clients should not need to look at any ot the code beyond this point
*/


/*
    Implementation notes: Stack CONSTRUCTOR
    _______________________________________
    The constructor mus create an empty linked list and initialize the size_element counter
*/
    template <typename ValueType>
    stack<ValueType>::stack() 
    { 
        std::cout <<"\n -CRANDO UN OBJETO TIPO stack - \n";
        size_elements = 0; 
        list = NULL;
    }








/*
    Implementation notes: COPY CONSTRUCTOR and ASSIGNMENT OPERATOR 
    ______________________________________________________________
    These methods follow the standard template, leaving the work to deepCopy.
*/
    template <typename ValueType>
    stack<ValueType>::stack(const stack<ValueType> & src) 
    { 
        deepCopy(src);
    }

    template <typename ValueType>
    stack<ValueType>&  stack<ValueType>::operator=(const stack<ValueType> & src) 
    { 
         std::cout <<"\n ESTOY EN operator=  ";
         if(this != &src) {
             clear();
             deepCopy(src);
         }

        return *this;
    }






/*
    Implementation notes: ~stack
    ____________________________
    The destructor frees any heap memory that is allocated by the 
    implementation . Because clear frees each element it processes,
    this implementation of the destructor simply calls that method.

*/
    template <typename ValueType>
    stack<ValueType>::~stack() { 
        clear();
    }

/*
    Implementation notes :size, isEmpty
    ___________________________________
    These methods use the count variable and therefore run in constant time.
*/

    template <typename ValueType>
    int stack<ValueType>::size() const{
        return size_elements;
    }

    template <typename ValueType>
    bool stack<ValueType>::isEmpty() const {
        return size_elements == 0;
    }

/*
    Implementation notes: clear
    __________________________
    This method pops the stack until it is empty, thereby freeing each cell.
*/
    template <typename ValueType>
    void stack<ValueType>::clear()  {
        while(size_elements >0 ) {
            pop();
        }
    }





/*
    Implementation notes : PUSH
    ___________________________
    This method chains a new element onto the front ot the list
    where it becomes the top of the stack.
*/
    template <typename ValueType>
    void stack<ValueType>::push(ValueType value) {
        
        //  CREATE A NEW CELL
            Cell *newCell = new Cell;

            std::cout <<"\n\nposicion en memoria de newCell : " << &newCell ;
            std::cout <<"\n\nvalor de newCell : " << newCell <<"\n";

        //  ASSIGNS A NEW VALUE A CELL
            newCell->data = value;
            newCell->link = list;
            
        //  POINT list TO THE newCeLL
        list = newCell; 

        std::cout<< "valor de list: " << list;


        size_elements++;

    }





/*
    Implementation notes: pop, peek
    ______________________________
    These functions must check for an empty stack 
    and report and error if there is no top element
*/
    template <typename ValueType>
    ValueType stack<ValueType>::pop() {
        
        if(isEmpty) {
            error ("pop: attempting to pop an empty stack")
        }
        Cell *cp= list;

        ValueType result = list->data;

        list = list->link;

        // delete tmp;

        size_elements--;
        return  result;

    }


    template <typename ValueType>
    ValueType stack<ValueType>::peek() {
          
        if(isEmpty) {
            error ("pop: attempting to pop an empty stack")
        }

       
        return  list->data;
    }









/*
    Implementation notes: deepCopy
    ______________________________
    The deepCopy method creates a copy of the cells in the linked list.
    The variable tail keep track of the last cell in the chain.

*/
    template <typename ValueType>
    void stack<ValueType>::deepCopy (const stack<ValueType> & src){

        
        size_elements = src.size_elements;

        Cell *tail = NULL;

        for(Cell *cp = src.list;  cp!=NULL; cp = cp->link ) {

            Cell *ncp = new Cell;

            ncp->data= cp->data;

            if(tail ==NULL) {
                list= ncp;
            }else{
                tail->link = ncp;
            }

            tail= ncp;
        }

        if(tail != NULL) tail->link = NULL;

        
    }









#endif
