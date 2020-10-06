#ifndef Stack1_Included
#define Stack1_Included

#include <deque>

template <typename T> class MyStack {
public:
    void push(T value);
    T pop();
    size_t size();
    bool empty();
 
    typename deque<T>::iterator begin(); // Now correct
    typename deque<T>::iterator end();   // Now correct

private:
    deque<T> elems;
};


template <typename T> 
void MyStack<T>::push(T value)
{ 
    elems.push_front(value);
}

template <typename T>  
T MyStack<T>::pop() 
{ 
    T result = elems.front(); 
    elems.pop_front();
    return result;
}

template <typename T> 
size_t  MyStack<T>::size()
{ 
    return elems.size();
}

template <typename T> 
bool MyStack<T>::empty() { 
    return elems.empty();
}

template <typename T>  typename deque<T>::iterator MyStack<T>::begin() 
{
    return elems.begin(); 
}


template <typename T> 
typename deque<T>::iterator MyStack<T>::end() 
{
    return elems.end(); 
}

#endif