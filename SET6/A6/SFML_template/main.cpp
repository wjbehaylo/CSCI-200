/* CSCI 200: Assessment 6: A6 Triangle Land
 *
 * Author: Walter Behaylo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // none.
 * use inheritance and SFML to design and draw triangles
 */


#include <SFML/Graphics.hpp>
using namespace sf;

#include "Triangle.h" //file with abstract triangle
#include "ScaleneTriangle.h" //file with Scalene Triangle class
#include "IsocelesTriangle.h" //file with Isoceles Triangle class
#include "EquilateralTriangle.h" //file with Equilateral triangle class
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    // create a window
    RenderWindow window( VideoMode(640, 640), "SFML Test" );

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING
    ifstream FileIn;
    FileIn.open("data/triangles.dat");
    
    //now that the triangle datafile is open, we will make an array of triangles
    char TriangleType;
    double x1, y1, x2, y2, x3, y3;
    int r, g, b;
    // my list will be a vector, because I know that it is mutable and we can add to the back of it like we'll need to
    vector<Triangle*> triangle_list; 

    //TROUBLESHOOTING: Scalene seems to work fine, my invalid scalene matched the other invalid scalenes

    while(!FileIn.eof()){ //while we are not at the end of the file, we will read in the triangles
        FileIn>>TriangleType>>x1>>y1>>x2>>y2>>x3>>y3>>r>>g>>b;
        if(!FileIn) break; //if fileIn failed, break
        switch(TriangleType){
            case 'S': {//if we are supposedly working with a scalene triangle
                ScaleneTriangle* scalene = new ScaleneTriangle; //we will make a pointer to a new scalene triangle
                //now that we have our scalene triangle, we will check if the entered coordinates are those of a scalene triangle
                if(scalene->setCoordinates(x1,y1,x2,y2,x3,y3)){ //if we are working with a scalene triangle, 
                    scalene->setColor(Color(r,g,b));
                    triangle_list.push_back(scalene);
                    break;
                }
                //if the triangle isn't a real triangle of the specified type, we don't add it to the list
                cout<<"triangle is invalid - \""<<TriangleType<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<" "<<r<<" "<<g<<" "<<b<<"\""<<endl;
                break; }
            case 'I': {//if we are supposedly working with an isoceles triangle
                IsocelesTriangle* isoceles = new IsocelesTriangle;
                if(isoceles->setCoordinates(x1,y1,x2,y2,x3,y3)){//if we are working with an isoceles triangle
                    isoceles->setColor(Color(r,g,b));
                    triangle_list.push_back(isoceles);
                    break;
                }
                //if the triangle isn't a real triangle or isn't an isoceles
                cout<<"triangle is invalid - \""<<TriangleType<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<" "<<r<<" "<<g<<" "<<b<<"\""<<endl;
                break; }
            case 'E':{ //if we are supposedly working with an equilateral triangle
                EquilateralTriangle* equilateral = new EquilateralTriangle;
                if(equilateral->setCoordinates(x1,y1,x2,y2,x3,y3)){ //if we are working with an equilateral triangle
                    equilateral->setColor(Color(r,g,b));
                    triangle_list.push_back(equilateral);
                    break;
                }
                //if the triangle isn't a real triangle or isn't equilateral
                cout<<"triangle is invalid - \""<<TriangleType<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<" "<<r<<" "<<g<<" "<<b<<"\""<<endl;
                break;} 
        }
    }
    //at this point we should have our vector filled up with all the valid triangles, and all the invalid triangles have been printed out





    //  END  ANY FILE LOADING
    /////////////////////////////////////

    // create an event object once to store future events
    Event event;

    // while the window is open
    while( window.isOpen() ) {
        // clear any existing contents
        window.clear();

        /////////////////////////////////////
        // BEGIN DRAWING HERE

        for(int i = 0; i<triangle_list.size(); i++){ //we are going to go through each triangle in the list of them
            triangle_list.at(i)->draw(window);
        }

        //  END  DRAWING HERE
        /////////////////////////////////////


        // display the current contents of the window
        window.display();

        /////////////////////////////////////
        // BEGIN EVENT HANDLING HERE
        // check if any events happened since the last time checked
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }
            // check addition event types to handle additional events
        }
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////
    }

    return 0;
}