
#include <iostream>
#include "queue.h"




int main () {

    std::cout<<"\n---Testing queue based in array-- \n\n";

    Queue<int> myqueue;

    myqueue.enqueue(10);
    myqueue.enqueue(12);
    myqueue.enqueue(14);

    
    myqueue.mostrarLaQueue();

    myqueue.dequeue();
    
     myqueue.mostrarLaQueue();

    myqueue.enqueue(16);
    myqueue.enqueue(18);
    
    myqueue.mostrarLaQueue();

    myqueue.dequeue();

    myqueue.mostrarLaQueue();
    
    myqueue.enqueue(20);

      myqueue.mostrarLaQueue();

    myqueue.dequeue(); 
      myqueue.dequeue(); 
        myqueue.dequeue(); 
           myqueue.dequeue(); 
    myqueue.mostrarLaQueue();


    myqueue.enqueue(1); 
    myqueue.mostrarLaQueue(); 
    
    myqueue.enqueue(2); 
    myqueue.enqueue(3); 

    myqueue.mostrarLaQueue(); 

    myqueue.enqueue(4);
    myqueue.mostrarLaQueue(); 

    myqueue.enqueue(5);
    myqueue.mostrarLaQueue(); 

    myqueue.enqueue(6);
    myqueue.enqueue(7);
    
       myqueue.mostrarLaQueue(); 

    myqueue.enqueue(8);
    myqueue.enqueue(9);

     myqueue.enqueue(10);

    myqueue.enqueue(11);

      myqueue.mostrarLaQueue(); 

    myqueue.dequeue();
    myqueue.dequeue();
    myqueue.dequeue();

    myqueue.mostrarLaQueue(); 

    myqueue.enqueue(8);    
    myqueue.enqueue(12);
    myqueue.enqueue(13);
    myqueue.enqueue(14);
     myqueue.enqueue(15);
      myqueue.enqueue(16);
       myqueue.enqueue(17);
        myqueue.enqueue(18);
         myqueue.enqueue(19);
          myqueue.enqueue(20);
           myqueue.enqueue(21);
            myqueue.enqueue(22);

    myqueue.mostrarLaQueue(); 

    // myqueue.enqueue(22);
    // myqueue.enqueue(24);
    // myqueue.enqueue(26);
    // myqueue.enqueue(28);
    // myqueue.enqueue(30);
    // myqueue.enqueue(32);
    // myqueue.enqueue(34);
    // myqueue.enqueue(36);
    // myqueue.enqueue(38);
    // myqueue.enqueue(40);
    // myqueue.enqueue(42);

   
    std::cout<<"El tamano actual es : " << myqueue.size() <<"\n";

    // int result;
    // int tamano_original =myqueue.size();
    // for(int i=tamano_original ; i > 0 ; i--){
    //     result = myqueue.peek();
    //     std::cout <<"\n-Index: "<< i <<" Dato : " << result ;
    // }
    
    //   Queue<int> newQueue = myqueue;

    // std::cout <<"\nPROBANDO newQueue\n\n";

   

    //  std::cout<<"\n\nEl tamano de newQueue es : " << newQueue.size() <<"\n";

    // int result2;
    // int tamano_original_newQueue =newQueue.size();
    // for(int i= tamano_original_newQueue ; i > 0 ; i--){
    //     result2 = newQueue.dequeue();
    //     std::cout <<"\n-Index: "<< i <<" Dato : " << result2 ;
    // }
    

    
    return 0;
}