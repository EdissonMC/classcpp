#ifndef  _point_h
#define  _point_h

#include <string>
#include <iostream>

class Point {

    public:

        /*
            Contructor : Point
            Usage: Point origin;
                Point pt(xc, yc);
            ________________________
            Creates a Point Object. The default contructor sets the coordinates to 0;
            The second form sets the coordinates to xc and yc.
        */
        Point();
        Point(int xc, int yc);


        /*
            Methods : getX,  getY
            Usage: int x = pt.getX();
                   int y = pt.getY();
            _________________________
            These methods returns the x and y coordinates of the point
        */
        int getX();
        int getY();


        /*
            Method : toString()
            Usage : string str = pt.toString();
            ___________________________________
            Returns a string representation of the Point in the form '(x,y)'
        */
        std::string toString();


         /*
            Method : operator<< 
            Usage : stream  << pt ;
            ___________________________________
            Returns a string representation of the Point in the form '(x,y)' over ostream
        */

        friend std::ostream& operator<<(std::ostream& os, Point pt) ;
        
    private:
        int x;    /* The x-coordinate */
        int y;    /* The y-coordinate */

};




#endif