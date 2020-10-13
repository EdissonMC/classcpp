/*
    File: stack.h
    _____________
    This interface exports a template version of the stack

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
        static const int INITIAL_CAPACITY = 10;
        
        /* data */    
        ValueType * array;   /* A dynamic array of the elements */
        int capacity;        /* The allocated size of the array */
        int size_elements ;  /* The number of stack elements    */
        
        /* Private method prototypes */
        void deepCopy (const stack<ValueType> & src);
        void expandCapacity();


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
    Implementation notes: Stack constructor
    _______________________________________
    The constructor must allocate the array storage for the stack elements
    and initialize the fields of the object

*/
    template <typename ValueType>
    stack<ValueType>::stack() 
    { 
        capacity = INITIAL_CAPACITY;
        array = new ValueType[capacity];
        size_elements=0;
    }



/*
    Implementation notes: copy constructor and assignment operator
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
        if(this != &src) {
            delete [] array;
            deepCopy(src);
        }
        return *this;
    }



/*
    Implementation notes: ~stack
    ____________________________
    The destructor frees any heap memory allocated by the class, 
    wich is just the dynamic array of elements.
*/
    template <typename ValueType>
    stack<ValueType>::~stack() { 
        delete [] array;
    }


    template <typename ValueType>
    int stack<ValueType>::size() const{
        return size_elements;
    }

    template <typename ValueType>
    bool stack<ValueType>::isEmpty() const {
        return size_elements == 0;
    }

    
    template <typename ValueType>
    void stack<ValueType>::clear()  {
         size_elements = 0;
    }


/*
    Implementation notes : push
    ___________________________
    This function must first check to see whether there is enough room for the value
    and expand the array storage if necessary.
*/
    template <typename ValueType>
    void stack<ValueType>::push(ValueType value) {
        
        if(isEmpty()){
            expandCapacity();
        }

        array[size_elements] = value;
        size_elements++;
    }


/*
    Implementation notes: pop, peek
    ______________________________

*/
template <typename ValueType>
ValueType stack<ValueType>::pop() {
    
    
    if(isEmpty()) {
        size_elements = 0;
        std::cout << " - error Stack Empty- \n\n";
        return -1;
    }

    size_elements--;
    return array[size_elements];

}





template <typename ValueType>
ValueType stack<ValueType>::peek() {
    
    if(isEmpty()) {
        size_elements = 0;
        std::cout << " - error Stack Empty- \n\n";
        return -1;
    }

    int top = size_elements - 1 ;
    return array[top];

}



/*
    Implementation notes: deepCopy
    ______________________________
    Copies the data from the src parameter into the current object.
    All dynamic memory is reallocated to create a "deep copy"  
    in which the current object and the source object are independent.
    The capacity is set so the stack has some room to expand. 
*/
template <typename ValueType>
void stack<ValueType>::deepCopy (const stack<ValueType> & src){

   capacity = src.size_elements + INITIAL_CAPACITY;

    this->array = new ValueType[capacity];


    for (int i=0; i< src.size_elements ; i++ ) {
        array[i] = src.array[i];
    }


    size_elements=  src.size_elements;
    
}



template <typename ValueType>
void  stack<ValueType>::expandCapacity() {

    //  Create a new array for save the currentArray
        ValueType* oldArray = array;

    //  Duplicate the capacity for get more room for news values
        capacity = capacity*2;

    //  Allocate heap memory for new array.
        array =  new ValueType[capacity];

    //  Copy all the elements
        for (int i=0; i< size_elements ; i++ ) {
            array[i] = oldArray[i];
        }

    //  Deallocate heap memory for the oldArray
        delete [] oldArray;
    
    std::cout<<"- The new  CAPACITY ARRAY  is :" << capacity <<"\n";
}

#endif
