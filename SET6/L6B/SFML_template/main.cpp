/* CSCI 200: LAB 6 B:  L6B SFML: Starcraft
 *
 * Author: Walter Behaylo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     //  No resources used besides assignment instructions. Not that it matters, but by delaying the draw time I realized that the stars,
       //  in order, are going clockwise around the origin. 
    Use sfml to read in a chart of star coordinates, normalize them, and print out an image with all of the stars in it
 */


#include <SFML/Graphics.hpp>
using namespace sf;
#include <fstream> 
#include "star.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // create a window
    RenderWindow window( VideoMode(640, 640), "SFML Test" );

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING
    ifstream FileIn("data/stars.txt");
    const int WIDTH(640),HEIGHT(640);

    star new_star;
    vector<star> star_vect;
    float x, y, trash1, brightness, trash2, trash3, max_brightness;

    while (!FileIn.eof()){
        FileIn>>x>>y>>trash1>>brightness>>trash2>>trash3;
        if(brightness < 0 || brightness > 8) continue; //here we make sure stars are in that range, otherwise they aren't included
        new_star.set_x(x);
        new_star.set_y(y);
        new_star.set_brightness(brightness);
        star_vect.push_back(new_star);
    }
    max_brightness = star_vect.at(0).get_brightness();
    for(int i = 0; i<star_vect.size(); i++){ //here we are calculating the maximum brightness for later use
        if (star_vect.at(i).get_brightness() > max_brightness) max_brightness = star_vect.at(i).get_brightness();
    }
    
    //now the star_vect contains the star's x and y coordinates for our set of stars
    FileIn.close();
    //  END  ANY FILE LOADING
    /////////////////////////////////////

    // create an event object once to store future events
    Event event;

    float temp_x, temp_y; //these variables will contain the values of the star currently being drawn
    Color gray_shade;
    // while the window is open
    while( window.isOpen() ) {
        
        // clear any existing contents
        window.clear();

        /////////////////////////////////////
        // BEGIN DRAWING HERE
        CircleShape starShape;
        starShape.setRadius(2);
        
        for(int i = 0; i < star_vect.size(); i++){ //we need to draw each star
            temp_x = star_vect.at(i).getTransformedX(WIDTH); //when drawing the stars, we use the transformed values
            temp_y = star_vect.at(i).getTransformedY(HEIGHT);
            starShape.setPosition(Vector2f(temp_x, temp_y));

            //now that the position has been set, the color will be too
            gray_shade = star_vect.at(i).getGrayscaleColor(max_brightness);
            starShape.setFillColor(gray_shade); //this sets the color of the star, depending on what the value of gray_shade is for it

            //now the star can be drawn
            window.draw(starShape);
            
            
        }
        
        //  END  DRAWING HERE
        /////////////////////////////////////

        window.display(); // this should be on its own outside of the for loop
        // display the current contents of the window
        

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