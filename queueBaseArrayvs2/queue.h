/*
    File: queue.h
    ____________
    This interface exports a template version of the Queue class.

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

            ValueType * array;
            int capacity;
            int size_elements;
            int tail;
            int head;


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


template <typename ValueType>
Queue<ValueType>::Queue(/* args */)
{
    std::cout <<"Constructor queue\n";
    capacity = 5;
    array = new ValueType[capacity];
    size_elements = 0;
    head =0;
    tail=0;
}


template <typename ValueType>
Queue<ValueType>::Queue(const Queue<ValueType> & src)
{
    std::cout <<"---ESTOY EN COPY- CONSTRUCTOR--- \n\n";
     std::cout <<"---El tamano de la queue a copiar es: ---" << src.size_elements <<" \n\n";

    deepCopy(src);

}


template <typename ValueType>
Queue<ValueType>::~Queue()
{
    delete []array;
}


template <typename ValueType>
void Queue<ValueType>::enqueue(ValueType value) {
    std::cout <<"\n<-Enqueue (" << value<<  ")-->"<< "\n";
     std::cout <<"head : " << head <<"  tail :" <<tail <<"  capacity : " << capacity<<"\n";

    if(size_elements == capacity-1) {
        expandCapacity();
    }

    
    if(tail == capacity) {
        tail=0;
    }

    array[tail++] = value;
    size_elements++;
    

    //ESTO ES UNA PRUEBA
    // int tamano= size_elements; 
    // for(int i = 0; i < tamano ; i++) {
    //     std::cout <<"Dato: " <<array[i]<<"\n";
        
    // }

     std::cout <<"<--END enqueue DATA --> \n\n";
}

template <typename ValueType>
ValueType Queue<ValueType>::dequeue() {
     std::cout <<"\n<-Dequeue() -->\n";
    // std::cout <<"\n--Estoy en Deque()--\n";
    std::cout <<"head : " << head <<"  tail :" <<tail <<"  capacity : " << capacity<<"\n";

    if(head == capacity) {
        head = 0;
    }
    size_elements--;

    // std::cout <<"------END Dequeue()  ------- \n\n";

    array[head]=0;
    std::cout <<"<--END Dequeue() --> \n\n";
    return array[head++]; 

}


template <typename ValueType>
ValueType Queue<ValueType>::peek() const{


    return array[ head]; 

 }


template <typename ValueType>
int Queue<ValueType>::size() const{
    return size_elements;
}

template <typename ValueType>
bool Queue<ValueType>::isEmpty() const{
     return size_elements == 0;
}


template <typename ValueType>
void Queue<ValueType>::expandCapacity() {
    
     std::cout <<"\n<-ExpandCapacity() -->\n";
    
    ValueType *oldArray = array;
   
    array = new ValueType[capacity*2];

    int tailOld =tail;
    int headOld =head;
    
    
    for(int i = 0 ; i < size_elements ; i++){
        
        // std::cout <<"Dato: " <<array[i-1]<<"\n";
        if(headOld%(capacity) == 0) {
                headOld=0;
        }
        
        array[i] = oldArray[headOld++];
    }
    
    tail =size_elements;
    head=0;    
   
     capacity = capacity *2;
    delete[] oldArray;
      std::cout <<"<--END ExpandCapacity() --> \n\n";

 }


template <typename ValueType>
void Queue<ValueType>::deepCopy(const Queue<ValueType> &src) {

     std::cout <<"---ESTOY EN deepCOPY --- \n\n";
     std::cout <<"---El tamano de la queue a copiar es: ---" << src.size_elements <<" \n\n";

    ValueType *oldArry = src.array;

    capacity = src.size_elements + INITIAL_CAPACITY;
    size_elements = src.size_elements;

    array = new ValueType[capacity];

    // int tamano = size_elements; 

    for(int i = 0 ; i < size_elements ; i++){
        // std::cout <<"Dato: " <<array[i-1]<<"\n";
         array[i] = oldArry[i];
    }

}


template <typename ValueType>
void Queue<ValueType>::mostrarLaQueue() {

    std::cout <<"\n\n<------ MOSTRANDO LA QUEUE ------->\n";

     int result;
    int tamano_original = size_elements;
    for(int i=0 ; i < capacity ; i++) {

        // result = myqueue.peek();
        std::cout <<"\n-Index: "<< i <<" Dato : " << array[i];
    }

    std::cout <<"\n\n<------ END MOSTRANDO LA QUEUE ------->\n\n\n";
}


#endif