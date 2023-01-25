/* CSCI 200: Lab 2 B: L2B - Coordinate Converter
 *
 * Author: Walter Behaylo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // None
 *
 *  Use functions to go from cartesian (x,y) to polar (r,theta) coordinates
 */
#ifndef coordinate_conversion_h
#define coordinate_conversion_h

 #include <cmath>
 #include <iostream>
 using namespace std;


/**
*@brief converts polar user inputs into cartesian coordinate outputs
*@param radius is the user inputted radius
*@param angle is the angle between the x axis and the line from the origin to the point
*@param xCoord is the calculated value of the point with respect to the x axis
*@param yCoord is the calculated value of the point with respect to the y axis
*@return doesn't return anything since xCoord and yCoord are edited within the function
*/
 void polar_to_cartesian(const double radius, const double angle, double& xCoord, double& yCoord);

/**
*@brief converts cartesian user inputs into polar coordinate outputs
*@param xCoord is the user inputted x coordinate
*@param yCoord is the user inputted y coordinate
*@param radius is the calculated distance from the origin to the point
*@param angle is the angle between the positive x axis and the radius to the point
*@return doesn't return anything, since we are modifying the radius and angle within the function
*/
 void cartesian_to_polar(const double xCoord, const double yCoord, double& radius, double& angle);

/**
*@brief gets the user input between a range of integers, here for choosing polar or cartesian
*@param number_of_choices is the number of options the user can choose from, if their choice is not in the range 1-max it will error
*@return returns the user's choice
*/
 int get_user_input(int number_of_choices);

 /**
*@brief makes sure that the doubles being input are doubles
*@param variable is the thing we are checking the input for
*@return returns the user input once it is correct
*/
 double check_input(string variable);
 
 #endif