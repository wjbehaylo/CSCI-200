#ifndef SCALENETRIANGLE_H
#define SCALENETRIANGLE_H

//header for scalene triangle class

#include "Triangle.h"
#include <SFML/Graphics.hpp>
using namespace sf;

#include <cmath> //for length calculations
#include <iostream>
using namespace std;

class ScaleneTriangle: public Triangle{
    public:

        /**
        * @brief overload of setCoordinates function from Triangle abstract class, if the points create non-zero, triangular sides, return true and make them the values in xyCoords, otherwise return false
        * @param x1 this is the x coordinate of the first point
        * @param y1 this is the y coordinate of the first point
        * @param x2 x coordinate of second point
        * @param y2 y coordinate of second point
        * @param x3 x coordinate of third point
        * @param y3 y coordinate of third point
        * @return returns true if the three sides form the desired type of triangle (one of the derived triangles)
        */
        bool setCoordinates(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3) override;


};







#endif