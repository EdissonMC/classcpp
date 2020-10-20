
#include <iostream>
#include "vector.h"

/*
  This file let you make some test over vector implementation.
 
*/



int main () {

    std::cout<<"\n--Testing vector based in array-- \n\n";

  //  CREATING A VERCTOR  
      Vector<int> myVector;

      myVector.add(5);
        myVector.add(15);
            myVector.add(25);
  
  //  SHOWING THE ELEMENTS IN THE VECTOR
      for(int i=0; i < myVector.size(); i++){
        std::cout<< myVector[i] <<"\n";
      }


    
    return 0;
}