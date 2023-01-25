/* CSCI 200: Lab 2 B: L2B - Coordinate Converter
 *
 * Author: Walter Behaylo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     //  None
 *
 *  Use functions to go from cartesian (x,y) to polar (r,theta) coordinates
 */

 #include <cmath> //for the sin, cos, tan functions
 #include <iostream>
 using namespace std;



    void polar_to_cartesian(const double radius, const double angle,double& xCoord, double& yCoord){
        xCoord = radius * cos(angle); //equations for x and y coordinates from radius and angle, derived using trig
        yCoord = radius * sin(angle);
    }


    void cartesian_to_polar(const double xCoord, const double yCoord, double& radius, double& angle){
      radius = sqrt(pow(xCoord,2) + pow(yCoord,2)); // equations for radius and angle from x y coordinates, 
      angle = atan(yCoord/xCoord); // the angle is going to be the inverse tangent of y/x, because that uses the two side lengths of the triangle to find the angle that the hypotenuse is to one of them (here x)
    }



    int get_user_input(int number_of_choices){
    int choice;
    while(true){
    cout<< "Enter ";
    for(int i=1; i<(number_of_choices+1); i++){
        if (i== number_of_choices){
            cout<< "or "<< i;
            break;
        }
        cout<< i<< ", ";
    }
    cout<< ": ";
    cin >> choice;
    if (!cin.fail() && choice >=1 && choice <= number_of_choices){
        cin.ignore(10000,'\n'); //disregard any characters after the successful input
        break;
    }
    cin.clear();
    cin.ignore(10000,'\n');
    cerr << "Invalid input."<< endl;
    
}
return choice;
}



double check_input(string variable){ // a function to make sure the double input is good
    double in;
    cin>> in;
    while (cin.fail()){ //if in isn't a double, there is a problem so we keep it going
        cerr<< "invalid input, please go again."<<endl;
        cin.clear();
        cin.ignore(10000,'\n');
        cout<< variable;
        cin>> in;
    }
    cin.ignore(10000,'\n'); //makes sure that any other inputs after the correct one don't come through
    return in;
}