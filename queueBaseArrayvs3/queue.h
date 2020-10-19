/*
    Queue  Vs 3
    Implementation by CS106BX Stanford Book

    File: queue.h
    ____________
    This interface exports a template version of the Queue class.
    The array-based queue stores the elements 
    in successive index positions in an array, just as a stack does.
    What makes the queue structure more complex  is the need to avoid shifting elements 
    as the queue expands and contracts. 
    In the array model, this goal is achieved by keeping track of both the head and tail indices.
    The tail index increases by one each time an elment is enqueued, and the head index increases by
    one each time an element is dequeued. 
    Eas index therefore marches toward the end of the allocated array and will eventually reach the end.
    Rather than allocate new memory, this implementation lets each index wrap around back to the
    beginning as if the ends of the array of elements were joined to form a circle. 
    This representation is called a ring buffer. 


*/

#ifndef _queue_h
#define _queue_h


#include <iostream>

template <typename ValueType>
class Queue
{
    private:
        /*  data */
            static const int INITIAL_CAPACITY = 5;

            ValueType * array;   /* A dynamic array of the elements */
            int capacity;        /* The allocated size of the array */
            int head;            /* The index of the head element   */
            int tail;            /* The index of the tail element   */


        /* Private method prototypes */
            void deepCopy(const Queue<ValueType> &src);
            void expandCapacity();

    public:
        /*
            Constructor : Queue
            Usage : Queue<ValueType> queue;
            ______________________________
            Initializes a new empty queue
        */
        Queue(/* args */);


        /*
            Destructor: ~Queue 
            Usage: Queue<ValueType> queue;
            ______________________________
            Initializes a new empty queue.
        */
        ~Queue();


        /*
            Method: size
            Usage : int n= queue.size();
            ___________________________
            Returns the number of values in the queue
        */
            int size() const;

        /*
            Method : isEmpty
            Usage: if (queue.isEmpty())
            ____________________________
            Returns true if the queue constains no elements
        */
            bool isEmpty() const;

        /*
            Method : clear
            Usage: queue.clear()
            ____________________
            Removes all elements from this game
        
        */
            void clear();


       /*
            Method: enqueue
            Usage: queue.enqueue(value)
            ___________________________
            Adds value to the end of the queue
       */
            void enqueue(ValueType value);




        /*
            Method : dequeue
            Usage: ValueType first = queue.dequeue();
            _________________________________________
            Removes and returns the first item in the queue.
            This method signals an error if called on an empty queue.
        
        */
            ValueType dequeue();


        /*
            Method: peek
            Usage : ValueType first = queue.peek();
            ________________________________________
            Returns the first value in the queue , without removing it.
            This method signals an error if called on an empty queue.
        */
            ValueType peek()const;


        /*
            Copy constructor and assignment operator
            _______________________________________
            These methods implement deep copying for queues.
        
        */
            Queue(const Queue<ValueType> & src);
            Queue<ValueType> &operator=(const Queue<ValueType> &src);



        void mostrarLaQueue(); 



};

/* 
    _____________________________________________________________________________
    Implementation section
    ______________________
    Clients should not need to look at any of the code beyond this point
*/



/*
    > CONSTRUCTOR
    Implementation notes: Queue 
    _______________________________________
    The constructor allocates the array storage and initializes the fields
*/
    template <typename ValueType>
    Queue<ValueType>::Queue(/* args */)
    {
        capacity = INITIAL_CAPACITY;
        array = new ValueType[capacity];
        head = 0;
        tail = 0;
    }



/*  
    > DESTRUCTOR
    Implementation notes:~Queue  
    __________________________
    The destructor frees any memory that is allocated by the implementation.

*/
    template <typename ValueType>
    Queue<ValueType>::~Queue()
    {
        delete []array;
    }




/*
    Implementation notes: Deep copying support
    __________________________________________
    These methods implement deep copying for queues
*/
    template <typename ValueType>
    Queue<ValueType>::Queue(const Queue<ValueType> & src)
    {
        deepCopy(src);
    }



    template <typename ValueType>
    Queue<ValueType> & Queue<ValueType>::operator=(const Queue<ValueType> & src)
    {
        if(this!= &src) {
            delete[] array;
            deepCopy(src);
        }
        return *this;

    }


    template <typename ValueType>
    void Queue<ValueType>::deepCopy(const Queue<ValueType> &src) {

        int count = src.size();
        capacity =  count + INITIAL_CAPACITY;
        array = new ValueType[capacity];


        for (int i= 0; i < count; i++) {
            array[i] = src.array[(src.head + i) % src.capacity];
        }

        head = 0;
        tail = count;
    }




/*
    Implementation notes: enqueue
    _____________________________
    This method must first check to see whether there is enough room for 
    the element and expand the array storgae if necessary. 
    Because it is otherwise imposible to differentiate the case when a queue is empty
    from when it is completetly full, this implementation expands the 
    queue when the size is one less tha the capacity.
*/

template <typename ValueType>
void Queue<ValueType>::enqueue(ValueType value) {
    
     std::cout <<"\n\n>ENQUEUE("<< value <<") ------->\n";
    if(size() == capacity-1)  expandCapacity();
    
    array[tail] = value;
    tail = (tail + 1) % capacity;  // Modular arithmetic

    std::cout <<"<--END enqueue DATA --> \n\n";
}




/*
    Implementation notes: dequeue, peek
    ___________________________________
    These methods must check for an empty queue and report an error
    if there is no first element.
*/
    template <typename ValueType>
    ValueType Queue<ValueType>::dequeue() {
    
        std::cout <<"\n\n>DEQUEUE() ------->\n";

        if(isEmpty()){
            std::cout <<"Attempting to dequeue an empty queue";
        }

        ValueType result = array[head];
        array[head]=0;
        head =  (head + 1) % capacity;  // Update the head
        return result;
        
    }


    template <typename ValueType>
    ValueType Queue<ValueType>::peek() const{


        if(isEmpty()){
            std::cout <<"Attempting to dequeue an empty queue";
        }

        ValueType result = array[head];
        return result;
    }





/*
    Implementation notes: size
    __________________________
    The size is calculated from head and tail using modular arithmetic
*/
    template <typename ValueType>
    int Queue<ValueType>::size() const{
        return (tail + capacity - head) % capacity;
    }


/*
    Implementation notes: isEmpty
    ______________________________
    The queue is empty whenever the head and tail pointers are equal.
    This interpretation means that the queue must always leave on unused space.
*/
    template <typename ValueType>
    bool Queue<ValueType>::isEmpty() const {
        return head == tail;
    }


/*
    Implementation notes: clear
    ___________________________
    The clear method need not take account of where in the ring buffer 
    any existing data is stored and can simply reset the head and tail indicees.
*/
    template <typename ValueType>
    void Queue<ValueType>::clear()  {
         head == tail = 0;
    }



/*
    Implementation notes: expandCapaity
    ___________________________________
    This private method double the capacity of the dynamic array whenever 
    it runs out of space. For simplicity, this implementation also shifts
    all the elements back to the beginning of the array.
*/
template <typename ValueType>
void Queue<ValueType>::expandCapacity() {
    
    
    int count = size();
    ValueType *oldArray = array;
   
    array = new ValueType[capacity * 2];

    
    for(int i = 0 ; i < count ; i++){    
        array[i] = oldArray[(head + i )% capacity];
    }
    
    capacity *= 2;
    head = 0;
    tail = count;
    delete[] oldArray;

 }




template <typename ValueType>
void Queue<ValueType>::mostrarLaQueue() {

    std::cout <<"\n\n<------ MOSTRANDO LA QUEUE ------->\n";

     int result;
    int tamano_original = size();
    for(int i=0 ; i < capacity ; i++) {

        // result = myqueue.peek();
        std::cout <<"\n-Index: "<< i <<" Dato : " << array[i];
    }

    std::cout <<"\n\n<------ END MOSTRANDO LA QUEUE ------->\n\n\n";
}


#endif