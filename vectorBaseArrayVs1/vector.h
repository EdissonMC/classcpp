/*
    Vector  Vs 1
    Implementation by CS106BX Stanford Book

    File: vector.h
    ______________
    This interface exports the Vector template class, which provides an efficient, safe, 
    convenient replacement for the array type in c++.

*/

#ifndef _vector_h
#define _vector_h

/*
    Class: Vector<ValueType>
    _________________________
    This class stores an ordered list of values similar to an array. 
    It supports traditional array selection using square brackets, 
    but also supports inserting and deleting elements.
*/
#include <iostream>

template <typename ValueType>
class Vector
{
  
    public:
        /*
            Constructor : Vector
            Usage : Vector<ValueType> vec;
                    Vector<ValueType> vec(n, value);
            ______________________________
            Initializes a new Vector object. 
            The first form creates an empty vector;
            The second form creates a Vector of size n in which each element is initialized
            to the specified value or the defaul value for the element type.
        */
            Vector(/* args */);
            Vector(int n, ValueType value = ValueType());

        /*
            Destructor: ~Vector 
            Usage: (usually implicit)
            ______________________________
            Frees any heap storage allocated by this vector
        */
            ~Vector();


        /*
            Method: size
            Usage : int n= vec.size();
            ___________________________
            Returns the number of values in the vector
        */
            int size() const;



        /*
            Method : isEmpty
            Usage: if (vec.isEmpty())
            ____________________________
            Returns true if the vector constains no elements
        */
            bool isEmpty() const;



        /*
            Method : clear
            Usage: vec.clear()
            ____________________
            Removes all elements from this vector
        
        */
            void clear();


    

        /*
            Method: get
            Usage: ValueType value = vec.get(index);
            _______________________________________
            Returns the element at the specified index in this vector.
            This method signals an error if the index is not in the array range.
        */
            ValueType get(int index) const;


        

        /*
            Method:set 
            Usage: vec.set(index, value);
            _____________________________
            Replaces the element at the specified index in this vector with a new value.
            The previous value at that index is overwritten. 
            This method signals an error if the index is not in the array range.
        */
            void set(int index, ValueType value);


        /*
            Method: insert
            Usage: vec.insert(0, value);
            ___________________________
            Inserts the element into this vector before the specified index.
            All subsequent elements are shifted one position to the right.
            This method signals an error if the index is outside the range from 0 up to
            and including the length of the vector.
        */
            void insert(int index, ValueType value);


        /*
            Method: remove
            Usage: vec.remove(index)
            _______________________
            Removes the element at the specified index from this vector.
            All subsequent elements are shifted one position to the left.
            This method signals an error if the index is outside the array range.
        */
            void remove(int index);


        /*
            Method: add
            Usage: vec.add(value)
            _____________________
            Adds a new value to the end of this vector
        */
            void add(ValueType value);
        
        /*
            Operator:[]
            Usage: vec[index]
            _________________
            Overloads []  to select elements from this vector.
            This extension enables the use of traditional array notation to get 
            or set individual elements. 
            This method signals an error if the index is outside the array range.
        */
            ValueType & operator[](int index);

        /*
            Copy constructor and assignment operator
            _______________________________________
            These methods implement deep copying for vectors.
        */
            Vector(const Vector<ValueType> & src);
            Vector<ValueType> & operator=(const Vector<ValueType> & src);



        private:
        /*
            Notes on the representation
            ___________________________
            This version of the vector.h interface stores the elements
            in a dynamic array of the specified element type.
            If the space in the array is ever exhausted,
            the implementation doubles the array capacity.
        */


        /*  data */
            static const int INITIAL_CAPACITY = 5;



        /*  Instance variables */
            ValueType *array;    /* A dynamic array of the elements */
            int capacity;        /* The allocated size of the array */
            int count;           /* The number of elements in use   */



        /*  Private method prototypes */
            void deepCopy(const Vector<ValueType> &src);
            void expandCapacity();

};





/* 
    Star Implementation section 
    ______________________
    Clients should not need to look at any of the code beyond this point
*/


/*
    Implementation notes: Vector constructor and destructor
    _______________________________________________________
    The two implementation of the constructor each allocate storage 
    for the dynamic array and the initialize the other fields of the object.
    The destructor frees the heap memory used by the dynamic array.
*/
    template<typename ValueType>
    Vector<ValueType>::Vector() {
        capacity = INITIAL_CAPACITY;
        count = 0;
        array = new ValueType[capacity];
    }

    template<typename ValueType>
    Vector<ValueType>::Vector(int n, ValueType value) {
        
        capacity =  (n > INITIAL_CAPACITY) ? n : INITIAL_CAPACITY ;
        array = new ValueType[capacity];
        count = 0;

        for(int i = 0 ; i < n ; i++) {
            array[i] = value;
        }

    }

    template <typename ValueType>
    Vector<ValueType>::~Vector() {
        delete[] array;
    }



/*
    Implementation notes: size, isEmpty, clear
    _________________________________________
    These methods require only the count field and do not look at the data.
*/
    template <typename ValueType>    
    int Vector<ValueType>::size() const {
        return count;
    }

    template <typename ValueType>    
    bool Vector<ValueType>::isEmpty() const {
        return count;
    }

    template <typename ValueType>    
    void Vector<ValueType>::clear()  {
        count = 0;
    }


/*
    Implementation notes: get, set
    _____________________________
    Theses methods first test that the index is in range
    and then get or set the appropriate index position in the dynamic array.
*/
    template <typename ValueType> 
    ValueType Vector<ValueType>::get(int index) const {
        
        if(index < 0 || index >= count) {
            std::cout<<"index out of range";
        }
        return array[index];
    }

    template <typename ValueType> 
    void Vector<ValueType>::set(int index, ValueType value)  {
        
        if(index < 0 || index >= count) {
            std::cout<<"index out of range";
        }
        array[index] = value;
    }

/*
    Implementation notes: Vector selection
    ______________________________________
    The following code implements traditional array selection 
    using square brackets for the index. 
    To ensure that clients can assign to array elements,
    this method uses and & to return the result by reference.
*/
    template <typename ValueType> 
    ValueType & Vector<ValueType>::operator[](int index) {
        if(index<0 || index>=count) {
            std::cout <<"Vector index out of range";
        }
        return array[index];
    }

/*
    Implementation notes: add, insert, remove
    _________________________________________
    These methods must shift the existing elments in the array to make
    room for a new element or to close up the space left by a deleted one.
*/
   template <typename ValueType> 
   void Vector<ValueType>::add(ValueType value) {
       insert(count, value);
   }

   template <typename ValueType> 
   void Vector<ValueType>::insert(int index, ValueType value) {
        
        if(count==capacity) expandCapacity();

        if(index < 0 || index > count) {
            std::cout<<"Insert: index out of range";
        }

        for(int i= count; i > index; i--) {
            array[i] = array[i-1];
        }

        array[index] = value;
        count++;

   }

    template <typename ValueType>   
    void Vector<ValueType>::remove(int index) {
        
        if(index < 0 || index >= count){
            std::cout<<"Index out of range";
        }

        for(int i = index; i < count-1; i++) {
            array[i] = array[i + 1];
        }

        count--;
    }




/*
    Implementation notes: copy constructor and assignment operator
    _______________________________________________________________
    These methods follow the standard template, leaving the work to deepCopy
*/
    template <typename ValueType>  
    Vector<ValueType>::Vector(const Vector<ValueType>& src) {
        deepCopy(src);
    }

    template <typename ValueType>  
    Vector<ValueType> & Vector <ValueType>::operator=(const Vector<ValueType> & src){
        if(this != &src) {
            delete[] array;
            deepCopy(src);
        }
        return *this;
    }



/*
    Implementation notes: deepCopy
    ______________________________
    Copies the data from the src parameter into the current object.
    All dynamic memory is reallocated to create a "deep copy" 
    in which the current object and the source object are independent.
    The capacity is set so the vector has some room to expand.
*/
    template <typename ValueType> 
    void Vector<ValueType>::deepCopy(const Vector<ValueType>& src) {
        
        capacity = src.count + INITIAL_CAPACITY;
        this->array = new ValueType[capacity];

        for(int i = 0; i< src.count; i++) {
            array[i] = src.array[i];
        }

        count = src.count;
    }



/*
    Implementation notes: expandCapacity
    ____________________________________
    This method doubles the array capacity whenever it runs out of space
*/
    template <typename ValueType> 
    void Vector<ValueType>::expandCapacity() {
        ValueType *oldArray = array;
        capacity *=2;

        array =  new ValueType[capacity];

        for(int i = 0; i< count; i++) {
            array[i] = oldArray[i];
        }

        delete[] oldArray;
    }



#endif