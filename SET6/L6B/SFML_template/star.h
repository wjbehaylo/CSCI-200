// This is the header file for my star class

#ifndef STAR_H
#define STAR_H

#include <SFML/Graphics.hpp> //this is for our color returning function
using namespace sf;

class star{
    private:
        //these three values will store respectively the x,y, and brightness of the star
        float x;
        float y;
        float brightness;
    public:

        /**
        * @brief this is the default constructor that sets x, y, and brightness to 0
        */
        star();

        /**
        * @brief this is the parametrized constructor that sets x, y, and brightness to the values of its parameters
        * @param X_INPUT this is the x input that x will be initialized to
        * @param Y_INPUT this is the y input that y will be initialized to
        * @param BRIGHTNESS_INPUT this is the brightness input that brightness will be initialized to
        */
        star(const float X_INPUT, const float Y_INPUT, const float BRIGHTNESS_INPUT);

        /**
        * @brief this is the setter function for x
        * @param X_INPUT this is the value x will be set to
        */

        void set_x(const float X_INPUT);

        /**
        * @brief this is the getter function for x
        * @return the return value is the current value of x
        */
        float get_x() const;

        /**
        * @brief this is the setter function for y
        * @param Y_INPUT this is the value y will be set to
        */
        void set_y(const float Y_INPUT);

        /**
        * @brief this is the getter function for y
        * @return the return value is the current value of y
        */
        float get_y() const;

        /**
        * @brief this is the setter function for brightness
        * @param BRIGHTNESS_INPUT this is the value brightness will be set to
        */
        void set_brightness(const float BRIGHTNESS_INPUT);

        /**
        * @brief this is the getter function for brightness
        * @return the return value is the current value of brightness
        */
        float get_brightness() const;

        /**
        * @brief this transforms the initial x coordinate into one which matches the size of the window
        * @param WIDTH this is the width of the window
        * @return returns a float representing what the transformed x value is
        */
        float getTransformedX(const int WIDTH);

        /**
        * @brief this transforms the initial y coordinate into one which matches the height of the window
        * @param HEIGHT this is the height of the window
        * @return returns a float representing what the transformed y value is
        */
        float getTransformedY(const int HEIGHT);

        /**
        * @brief this function gets the shade of gray that the current star would be
        * @param BRIGHTEST_STAR this is the value of brightness in the brightest star in the set
        * @return returns an SFML color object representing the star's shade of gray
        */
        Color getGrayscaleColor(const float BRIGHTEST_STAR) const; 

};      

#endif