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
        /* data */

    public:
        Queue(/* args */);
        ~Queue();
};


template <typename ValueType>
Queue<ValueType>::Queue(/* args */)
{
    std::cout <<"Testing queue";
}


template <typename ValueType>
Queue<ValueType>::~Queue()
{
}


#endif