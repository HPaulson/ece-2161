#include "circle.h"
#include <cmath>
#include <iostream>
#define PI (4*atan(1))
using namespace std;

// Returns the distance between two points given the two points (x1,y1) and (x2,y2)
double Circle::distance() {
	double distance = sqrt(pow((x2-x1),2)+pow((y2-y1), 2));
	return distance;
}

// Returns the radius of a circle given it's center (x1,y1) and any point in the circle (x2,y2)
double Circle::radius() {
    return distance();
}

// Returns the circumference of a circle given its radius
double Circle::circumference() {
	return 2*PI*radius();
}

// Returns the area of a circle given its radius
double Circle::area() {
	return PI*pow(radius(),2);
}

// Populates the circle's coordinate pairs
void Circle::populate_classobj(double x1, double x2, double y1, double y2) {
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
}

