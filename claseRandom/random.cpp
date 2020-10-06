#include <cstdlib>
#include <cmath>
#include <ctime>
#include "random.h"


void initRndomSeed();

/*
    Implementation notes: randomInteger

    The code for randomInteger produces the number in four steps

    1. Generate a random real number d in the rango [0..1)
    2. Scale the number to the range [0 ..  N) where N is the number of values.
    3. Translate the number so that the range starts at the appropiate value.
    4. Convert the result to the next lower integer.

*/

int randomInteger(int low,  int high) {

    initRandomSeed();

    double d = rand() / (double (RAND_MAX) + 1 );
    double s = d * (double(high) -  low +1);

    return int( floor(low + s) );

}



int randomReal(int low,  int high) {

    initRandomSeed();

    // Normalizar
    double d = rand() / (double (RAND_MAX ) + 1 );
    // Escalar
    double s = d * ( high -  low  );

    return low + s;

}

bool randomChance(double p) {

    initRandomSeed();
    return randomReal(0,1) < p;
}


void setRandomSeed(int seed) {

    initRandomSeed();
    srand(seed);

}


void initRandomSeed(){
    static bool initialized = false;
    if(!initialized){
        srand(int (time(NULL)));
        initialized = true;
    }
}