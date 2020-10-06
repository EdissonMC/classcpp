#include <iostream>
#include "mycctype.h"


/*
    This programa test the library mycctype, wich simulate the <cctyppe> library using set of characters
*/
int main () {

    mycctype miprueba;
    std::cout <<"9 es un digitooso? " <<  miprueba.isdigit('9');
    return 0;
}