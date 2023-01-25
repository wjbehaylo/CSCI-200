/* CSCI 200: Lab 2 B: L2B - Coordinate Converter
 *
 * Author: Walter Behaylo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // None

 *  Use functions to go from cartesian (x,y) to polar (r,theta) coordinates
 */

 #include <iostream>
 #include <cmath>
 #include "coordinate_conversion.h"
 using namespace std;

 int main(){
    int choice; // for which they want to do
    cout<<endl<< "Would you like to go from:"<<endl<<"  1: (r, angle) -> (x, y)"<< endl<< "  2: (x, y) -> (r, angle)?"<<endl;
    choice = get_user_input(2);
    
    if (choice == 1){
        double radius, angle;
        cout<< "Enter the radius and angle (in radians)"<<endl;
        cout<< " Radius: ";
        radius = check_input(" Radius: ");
        cout<< " Angle: ";
        angle = check_input(" Angle: ");
        double xCoord, yCoord;
        polar_to_cartesian(radius, angle, xCoord, yCoord);
        cout<< "The cartesian conversion is:"<<endl<<"("<<xCoord<<", "<< yCoord<<")"<< endl;
    }
    else if (choice == 2){
        double xCoord, yCoord;
        cout<< "Enter the x and y coordinates"<<endl;
        cout<< " X Coordinate: ";
        xCoord = check_input(" X Coordinate: ");
        cout<< " Y Coordinate: ";
        yCoord = check_input(" Y Coordinate: ");
        double angle,radius;
        cartesian_to_polar(xCoord,yCoord,radius,angle);
        cout<< "The polar conversion is:"<<endl<<"("<<radius<<", "<< angle<< ") (with the angle being in radians)"<<endl;
    }
    return 0;
 }