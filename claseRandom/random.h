/*
    File: random.h

    This interface exports functions for generating pseudorandom numbers

*/


#ifndef _random_h
#define _random_h


int randomInteger(int low, int high);

double randomReal(double low, double high);

bool randomChance(double p);

void setRandomSeed(int seed);

#endif