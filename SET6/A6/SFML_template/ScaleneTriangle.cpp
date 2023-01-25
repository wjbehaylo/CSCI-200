#include "ScaleneTriangle.h"

//implimentation of scale triangle setCoordinates function

bool ScaleneTriangle::setCoordinates(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3){
    double side12, side13, side23;
    //side 12 is gonna be the length between points 1 and 2, calculated with pythagoras
    side12 = round(pow( pow((x2-x1),2) + pow((y2-y1),2),  .5));
    side13 = round(pow( pow((x3-x1),2) + pow((y3-y1),2),  .5));
    side23 = round(pow( pow((x3-x2),2) + pow((y3-y2),2),  .5));

    //checking that the sides form a triangle
    if (side12 ==0 || side13 ==0 || side23 ==0 || side12+side13 <= side23 ||side12+side23<=side13 || side13+side23<= side12) return false;

    //if we got here then we have a scalene triangle, so we just have to set the coordinates of the triangle points
    Triangle::xyCoords = new Vector2f[3];
    Triangle::xyCoords[0] = Vector2f(x1,y1);
    Triangle::xyCoords[1] = Vector2f(x2,y2);
    Triangle::xyCoords[2] = Vector2f(x3,y3);
    return true;

}