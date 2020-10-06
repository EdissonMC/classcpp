/*
    File point.cpp
    ______________
    This file implements the point.h interface
*/

#include <iostream>
#include <sstream>
#include <string>
#include "point.h"




/*
    Implementation notes: Constructors
    __________________________________
    The constructors initialize the instance variables x and y. 
    In the second form of the constructor, the parameter names are xc and yc 
    to avoid the problem of shadowing the instance variables

*/


Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int xc, int yc) {
    x = xc;
    y = yc;
}





/*
    Implementation notes: Getters
    _____________________________
    The getters return the value of the corresponding instance variable.
    No setters are provide to ensure that point objects are immutable
*/

int Point::getX() {
    return x;
}


int Point::getY() {
    return y;
}


/*
    Implementation notes: toString
    ______________________________
    The implementation of toString uses the integerToString function
    
*/

std::string Point::toString() {

    std::string Xstring = "";
    std::string Ystring = "";

    std::stringstream converter;
    
    converter << x;
    converter >> Xstring;

    converter.clear();
    converter << y;
    converter >> Ystring;

    return "(" +   Xstring + "," + Ystring + ")" ;

}


std::ostream& operator<<(std::ostream& os, Point pt)  {
    os << pt.toString();
    return os;
}