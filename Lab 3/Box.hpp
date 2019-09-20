/*
 * Box.hpp
 *
 *  Created on: Sep 18, 2019
 *      Author: stsha
 */

class Box  {
       double length;//declares variables
       double breadth;
       double height;
  public:
       Box();//declares on arg constructor
       Box (double l, double b, double c);//declares 3 arg constructor
        double getVolume();
        Box operator+(Box b); //declares operator override.
        bool operator==(Box b); //declares operator override.



};


