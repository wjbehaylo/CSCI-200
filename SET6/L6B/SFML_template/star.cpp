//this is the implimentation of the member functions and constructors of star

#include "star.h"
#include <SFML/Graphics.hpp> //this is for our color returning function

//implimentation of default constructor
star::star(){
    x = 0;
    y = 0;
    brightness = 0;
}

//implimentation of parametrized constructor
star::star(const float X_INPUT, const float Y_INPUT, const float BRIGHTNESS_INPUT){
    x = X_INPUT;
    y = Y_INPUT;
    brightness = BRIGHTNESS_INPUT;
}

//implimentation for setters and getters

void star::set_x(const float X_INPUT){
    x = X_INPUT;
}

float star::get_x() const{
    return x;
}

void star::set_y(const float Y_INPUT){
    y = Y_INPUT;
}

float star::get_y() const{
    return y;
}

void star::set_brightness(const float BRIGHTNESS_INPUT){
    brightness = BRIGHTNESS_INPUT;
}

float star::get_brightness() const{
    return brightness;
}

float star::getTransformedX(const int WIDTH){
    float new_x = (x+1) * WIDTH /2;
    return new_x;
}
float star::getTransformedY(const int HEIGHT){
    float new_y = (-y + 1) * HEIGHT /2;
    return new_y;
}

Color star::getGrayscaleColor(const float BRIGHTEST_STAR) const{

    //this is where our brightness is inverted for the gray calculation
    float inverted_brightness = BRIGHTEST_STAR-brightness;
    int shade_of_gray = (int) (255 * inverted_brightness)/ BRIGHTEST_STAR;
    Color gray(shade_of_gray, shade_of_gray, shade_of_gray);
    return gray;  
}