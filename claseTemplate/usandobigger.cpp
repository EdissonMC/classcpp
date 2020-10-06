#include <iostream>
#include "bigger.h"


int main() {

    bigger<int> myBigger(4,2);
    bool result = myBigger.equal();
    std::cout <<"Resultado 4==2 ? :" << result;

    return 0;
}