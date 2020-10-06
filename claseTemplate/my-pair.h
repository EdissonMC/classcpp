
/*
    Version basida para definir una abstaccion usando una class template
*/
#ifndef MyPair_Included // Include guard prevents multiple inclusions
#define MyPair_Included


template <typename FirstType, typename SecondType> class MyPair {

public:
    FirstType getFirst();
    void setFirst(FirstType newValue);

    SecondType getSecond();
    void setSecond(SecondType newValue);

private:
    FirstType first;
    SecondType second;
}; 
#endif

