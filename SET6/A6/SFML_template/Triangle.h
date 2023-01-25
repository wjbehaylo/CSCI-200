#ifndef TRIANGLES_H
#define TRIANGLES_H

#include <SFML/Graphics.hpp>
using namespace sf;

#include <cmath> //for length calculations
#include <iostream>
using namespace std;

#include <vector> //for the list of points

//documentation of triangle class

class Triangle {
    public:
    /**
    * @brief default constructor, sets color to white, specifies vertices as 3, allocates list to have three elements
    */
    Triangle();


    /**
    * @brief destructor, deallocates list of vertices if necessary
    */
    ~Triangle();

    /**
    * @brief sets the triangles color
    * @param color the color the triangle's color will be set to
    */
    void setColor(const Color color);

    /**
    * @brief creates a convex shape, sets the points for each coordinate, sets fill color, draws it to the window
    * @param window this is the window object that will be drawn on
    */
    void draw(RenderTarget& window);

    /**
    * @brief this function sets the coordinates of the triangle
    * @param x1 this is the x coordinate of the first point
    * @param y1 this is the y coordinate of the first point
    * @param x2 x coordinate of second point
    * @param y2 y coordinate of second point
    * @param x3 x coordinate of third point
    * @param y3 y coordinate of third point
    * @return returns true if the three sides form the desired type of triangle (one of the derived triangles)
    */
    virtual bool setCoordinates(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3) = 0;

    protected:
    int num_vertices;
    Vector2f* xyCoords;

    private:
    Color triangle_color;
};

#endif