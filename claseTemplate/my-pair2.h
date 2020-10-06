/* 
    This method of packaging the .h/.cpp pair puts the entire class definition 
    and * implementation into the .h file. There is no .cpp file for this header.

    Este enfoque permite crear una clase uniendo la describcion de la interfaz
    y la implementacion en un solo archivo, es decir no existe archivo .ccp para este header.

*/
#ifndef MyPair_Included
#define MyPair_Included
 

template <typename FirstType, typename SecondType> 
class MyPair {
public:
    FirstType getFirst();
    void setFirst(FirstType newValue);

    SecondType getSecond();
    void setSecond(SecondType newValue); 

private:
    FirstType first;
    SecondType second;
};


template <typename FirstType, typename SecondType>
FirstType MyPair<FirstType, SecondType>::getFirst() 
{
    return first;
}

template <typename FirstType, typename SecondType>
void MyPair<FirstType, SecondType>::setFirst(FirstType newValue) 
{
    first = newValue; 
}

template <typename FirstType, typename SecondType>
SecondType MyPair<FirstType, SecondType>::getSecond()
 {
    return second;
}

template <typename FirstType, typename SecondType>
void MyPair<FirstType, SecondType>::setSecond(SecondType newValue) 
{
    second = newValue; 
}
#endif