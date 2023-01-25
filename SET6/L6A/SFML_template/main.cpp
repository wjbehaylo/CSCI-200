/* CSCI 200: LAB 6 A:  L6A SFML: Bob Ross
 *
 * Author: Walter Behaylo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     //  I looked up the RGB values for gold, for the monocle, also looked up how to add a delay to code
 * Install sfml, and use it to draw and animate a shape. I will be drawing and animating a square eye
 */

#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
using namespace std;
#include <SFML/System/Clock.hpp>

int main() {
    // create a window
    RenderWindow window( VideoMode(640, 640), "SFML Test" );
    
    /////////////////////////////////////
    // BEGIN ANY FILE LOADING

    // perform any file processing once before draw loop begins

    //  END  ANY FILE LOADING
    /////////////////////////////////////

    // create an event object once to store future events
    Event event;

    //the first shape is the white, square, left eyeball
    RectangleShape eyeball1;
    eyeball1.setSize( Vector2f(200,200));
    //not sure if this sets the position of the middle or one of the corners...
    eyeball1.setPosition( 40, 80);
    eyeball1.setFillColor( Color::White);

    RectangleShape eyeball2;
    eyeball2.setSize(Vector2f(200,200));
    eyeball2.setPosition(400,80);
    eyeball2.setFillColor( Color::White);

    RectangleShape iris1;
    iris1.setSize(Vector2f(80,80));
    iris1.setPosition(100,140);
    iris1.setFillColor( Color::Black);
    iris1.setOutlineColor(Color:: Blue);
    iris1.setOutlineThickness(20);

    RectangleShape iris2;
    iris2.setSize(Vector2f(80,80));
    iris2.setPosition(460,140);
    iris2.setFillColor(Color::Black);
    iris2.setOutlineColor(Color:: Blue);
    iris2.setOutlineThickness(20);


    //there will also be glasses over the eyes,
 CircleShape monocle1;
    monocle1.setPosition(Vector2f(0,30));
    monocle1.setRadius(150);
    monocle1.setOutlineColor(Color(212,170,60));
    monocle1.setFillColor(Color:: Black);
    monocle1.setOutlineThickness(5);

    CircleShape monocle2;
    monocle2.setPosition(Vector2f(350,30)); //this should make it centered on the eye
    monocle2.setRadius(150);
    monocle2.setOutlineColor(Color(212,170,60));
    monocle2.setFillColor(Color:: Black);
    monocle2.setOutlineThickness(5);

    RectangleShape bridge;
    bridge.setPosition(300,150);
    bridge.setSize(Vector2f(50,8));
    bridge.setFillColor(Color(212,170,60));


    int iris2x(460), iris2y(140), iris1x(100), iris1y(140);
    bool direction = true; // true means the eyes are moving right, false means they are moving left
    // while the window is open

    Clock programClock;
    Time lastTime = programClock.getElapsedTime();
    while( window.isOpen() ) {
        Time currTime = programClock.getElapsedTime();
        if ((currTime-lastTime).asMilliseconds()< 25) continue; // if not enough time has passed, we restart the loop redefining currTime
        lastTime = currTime;
        // clear any existing contents 
        window.clear();
        /////////////////////////////////////
        // BEGIN DRAWING HERE

    if(direction == true){ //if we are moving right, we add one pixel to the x component of each
        if( iris1x < 140){ //the point after which the iris would be leaving the eye
            iris1x++;
            iris2x++;
        }
        else direction = !direction; //otherwise we reverse the direction
    }

    else { // if we are moving left, 
        if(iris1x>60){ // 40 is the left edge of the eye which we can't move past
            iris1x--;
            iris2x--;
        }
        else direction = !direction; //reverse direction
    }

    //now that we have updated the pupils' positions values, we must redraw them


        // place any draw commands here to display in the window

    window.draw(monocle1);
    window.draw( eyeball1 );
    iris1.setPosition(iris1x,iris1y);
    window.draw(iris1);

    window.draw(monocle2);
    window.draw(eyeball2);
    iris2.setPosition(iris2x,iris2y);
    window.draw(iris2);

    window.draw(bridge);
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