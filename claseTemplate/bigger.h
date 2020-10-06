 #ifndef bigger_Included
 #define bigger_Included

 template <typename T>
 class bigger{
  
    public :
        bigger(T first , T second );
        bool equal ();
    private:
        T _first;
        T _second; 
 };
 
template<typename T> 
bigger<T>::bigger(T first , T second )
{
    _first  = first;
    _second = second;
} 

template<typename T> 
bool bigger< T>::equal () {
    return _first > _second;
}
 
#endif // bigger_class
 