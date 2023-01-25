//implimentation of member functions of Triangle class

#include "Triangle.h"
#include <SFML/Graphics.hpp>
using namespace sf;

#include <cmath> //for length calculations
#include <iostream>
using namespace std;


Triangle::Triangle(){
    triangle_color = Color::White;
    num_vertices = 3;
    xyCoords = new Vector2f[3]; // makes xyCoords pointer point to a new set of 3 2d vectors
}

Triangle::~Triangle(){
    delete[] xyCoords;
    xyCoords = nullptr;
}

void Triangle::setColor(const Color color){
    triangle_color = color;
}

void Triangle::draw(RenderTarget& window){
    ConvexShape triangle;
    triangle.setFillColor(triangle_color);
    triangle.setPointCount(num_vertices);
    for (int i = 0; i<num_vertices; i++){
        triangle.setPoint(i, xyCoords[i]); //sets the points of the shape to be the values in the xyCoords array
    }
    window.draw(triangle);
}

//since  set Coordinates is still pure virtual, no need to impliment it yet
// virtual bool Triangle::setCoordinates(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3) = 0;



