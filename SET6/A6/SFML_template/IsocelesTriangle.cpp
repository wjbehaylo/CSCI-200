#include "IsocelesTriangle.h"
#include "Triangle.h"
#include <SFML/Graphics.hpp>
using namespace sf;

#include <cmath> //for length calculations
#include <iostream>
using namespace std;

//implimentation of isoceles triangle set coordinates function

bool IsocelesTriangle::setCoordinates(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3) {
    double side12, side13, side23;
    //side 12 is gonna be the length between points 1 and 2, calculated with pythagorean theorum. Same with the other sides
    side12 = round(pow( pow((x2-x1),2) + pow((y2-y1),2),  .5));
    side13 = round(pow( pow((x3-x1),2) + pow((y3-y1),2),  .5));
    side23 = round(pow( pow((x3-x2),2) + pow((y3-y2),2),  .5));

    //checking that the sides form a triangle
    if (side12 ==0 || side13 ==0 || side23 ==0 || side12+side13 <= side23  ||side12+side23<=side13 || side13+side23<= side12) return false; //this false is if we don't have a triangle

    //checking that the sides form an isoceles triangle
    if (side12 == side13 || side12 == side23 || side13 == side23){
        Triangle::xyCoords = new Vector2f[3]; //make xyCoords point to a new 3 element array of Vector2f s
        Triangle::xyCoords[0] = Vector2f(x1,y1); // make each element of xyCoords correspond to one of them
        Triangle::xyCoords[1] = Vector2f(x2,y2);
        Triangle::xyCoords[2] = Vector2f(x3,y3);
        return true; //true, because it is an isoceles triangle
    }
    return false; //this false is only reached if we have a triangle, but then determine it isn't isoceles

}