#include <iostream>
#include "counter.h"


/*
    IMPLEMENTANDO UNA CLASE USANDO initializer list Y PASANDO UN 
    PARAMETRO COMO INICIALIZADOR YA QUE NO SABEMOS CUAL VLOR ASIGNARA 
    
    EN LA CLASE COUNTER SE DEBE USAR ESTE TIPO DE INICIALIZADOR 
    POR QUE LA VARIABLE maximum SE HA MARCADO COMO const ASI QUE
    NO LA PODEMOS INICIALIZAR EN EL CONSTRUCTOR Y TAMPOCO CONOCEMOS 
    EL VALOR CON EL QUE SERA INICIALIZADA.
*/
Counter::Counter(int maxValue) : value(0), maximum(maxValue) 
{   

    std::cout << "eEmitiendo desde counter valor, inicial = " << maximum;
        // Empty constructor
}

