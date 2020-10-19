/*
    Queue  Vs 1 Linked-list
    Implementation by CS106BX Stanford Book

    File: queue.h
    ____________
    This interface exports a template version of the Queue class.
    This implementation queue uses a linked list to store the elements
    of the queue.  
    To ensure that adding  a new element to the tail of the queue is fast,
    the data structure maintains a pointer to the last cell in the queue
    as well as the first. 
    If the queue is empty, both the head pointer and the tail pointer are set to NULL.

    The following diagram illustrates the structure of a queue 
    containing two elements, A and B.

         +---------+        +--------+        +---------+
    head |    o----+------->|    A   |  +--==>|    B    |
         +---------+        +--------+  |  |  +---------+
    tail |    o----+----+   |    o---+--+  |  |   NULL  |
         +---------+    |   +--------+     |  +---------+
                        |                  |
                        +------------------+
                    
*/

#ifndef _queue_h
#define _queue_h


#include <iostream>

template <typename ValueType>
class Queue
{
    private:
        /*  Type for linked list cell */
        struct Cell
        {
           ValueType data;   /* The data value         */
           Cell *link;       /* Link to the next cell  */
        };
        
        /* Instance variables */
            Cell *head;      /* Pointer to the cell at the head */
            Cell *tail;      /* Pointer to the cell at the tail */
            int count;       /* Number of elements in the queue */


        /* Private method prototypes */
            void deepCopy(const Queue<ValueType> &src);
            

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

    C++ requires that the implementation for a template class be available
    to that compiler whenever that type is used. 
    The effect of this restriction is that header files must include the implementation
    Clients should not need to look at any of the code beyond this point

*/



/*
    > CONSTRUCTOR
    Implementation notes: Queue 
    _______________________________________
    The constructor creates an empty linked list and set the count to 0.
*/
    template <typename ValueType>
    Queue<ValueType>::Queue(/* args */)
    {

        head =  tail = NULL;
        count =0;
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
        clear();
    }




/*
    Implementation notes: copy constructor and assignment operator
    _____________________________________________________________
    These methods follow the standard template, leaving the work to deepCopy
    
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
            clear();
            deepCopy(src);
        }
        return *this;

    }

/*
    Implementation notes : deepCopy
    _____________________________

    Copies the data from the src parameter into the current object.
    This implementation simply walks down the linked list in the 
    source object and enqueues each value in the destination.

*/

    template <typename ValueType>
    void Queue<ValueType>::deepCopy(const Queue<ValueType> &src) {

       head = NULL;
       tail = NULL;

       count =0;

       for(Cell *cp= src.head;  cp!=NULL; cp = cp->link) {
           enqueue(cp->data);
       }

    }




/*
    Implementation notes: enqueue
    _____________________________
    This method allocates a new list cell and chains it
    in at the tail of the queue.
    If the queue is currently empty, the new cell must also
    become the head pointer in the queue.
*/

    template <typename ValueType>
    void Queue<ValueType>::enqueue(ValueType value) {
        
        std::cout <<"\n>ENQUEUE("<< value <<") ------->\n";

        //  ALLOCATE A NEW CELL
            Cell *cp= new Cell;
            cp->data = value;
            cp->link = NULL;

        //  CHECK IF head IS NULL, THEN APPOINT TO NEW cp , IF NOT THEN CHAINs A NEW cp
            if (head == NULL) {
                head = cp;
            }else{
                tail->link=cp;
            }

        tail = cp;
        count++;

    }




/*
    Implementation notes: dequeue, peek
    ___________________________________
    These methods must check for an empty queue and report an error 
    if there is no first element.
    The dequeue method must also check for the case in which the queue becomes empty 
    and set both the head and tail pointers to NULL
*/
    template <typename ValueType>
    ValueType Queue<ValueType>::dequeue() {
        std::cout <<"\n\n>DEQUEUE() ------->\n";

        if(isEmpty()) {
            std::cout <<"Attempting to dequeue and empty queue\n";
        }
        
        Cell *cp = head;
        ValueType  result = cp->data;
        head = cp->link;

        if(head == NULL) tail = NULL;

        delete cp;
        count--;

        return result;

    }


    template <typename ValueType>
    ValueType Queue<ValueType>::peek() const{

        if(isEmpty()) {
            std::cout <<"Attempting to peek at an empty queue\n";
        }

        return head->data;
     
    }





/*
    Implementation notes: size , isEmpty, clear
    __________________________
    These methods use the count variable and therefore run in constant time.
*/
    template <typename ValueType>
    int Queue<ValueType>::size() const{
        return count;
    }


    template <typename ValueType>
    bool Queue<ValueType>::isEmpty() const {
        return count == 0;
    }



    template <typename ValueType>
    void Queue<ValueType>::clear()  {
        while (count > 0) {
            dequeue();
        }
    }








template <typename ValueType>
void Queue<ValueType>::mostrarLaQueue() {

    std::cout <<"\n\n<------ MOSTRANDO LA QUEUE ------->\n";


    int indice=0;
    for(Cell *cp= head;  cp!=NULL; cp = cp->link) {
           
           std::cout <<"Indice: "<< indice <<" Data: " <<cp->data << "\n";
           indice++;
    }


    std::cout <<"\n<------ END MOSTRANDO LA QUEUE ------->\n\n";
}


#endif