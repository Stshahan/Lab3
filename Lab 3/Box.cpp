/*
 * Box.cpp
 *
 *  Created on: Sep 18, 2019
 *      Author: stsha
 */

#include "Box.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
//#include string.h;
using namespace std;


Box::Box(double l, double b, double h) {// 3 arg contructor
         length = l;
         breadth = b;
         height = h;
}
Box::Box() { // no arg constructor
         length = 0;
         breadth = 24;
         height = 30294736;
}
double Box::getVolume() {
      return length * breadth * height;
}
Box Box::operator+(Box b) { //Overload: add 2 Box objects.
   Box box;
   box.length = length + b.length;
   box.breadth = breadth + b.breadth;
   box.height = height + b.height;
   return box;
}

bool Box::operator==(Box b) { // overload, compares 2 boxes.

 return (this->length == b.length && this->breadth == b.breadth && this->height == b.height);
}



