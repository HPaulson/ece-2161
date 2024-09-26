#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>
#include <iostream>
#define PI (4*atan(1))
using namespace std;

template<typename T>

class Circle {
private:
	T x1, y1, x2, y2;
protected:
	double distance();
public:
	Circle(T x1 = 0, T y1 = 0, T x2 = 0, T y2 = 0);
	double radius();
	double circumference();
	double area();
	void populate_classobj(T, T, T, T);
};

template<typename T>
Circle<T>::Circle(T x1, T y1, T x2, T y2) {
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
}
template<typename T>
// Returns the distance between two points given the two points (x1,y1) and (x2,y2)
double Circle<T>::distance() {
	double distance = sqrt(pow((x2-x1),2)+pow((y2-y1), 2));
	return distance;
}

template<typename T>
// Returns the radius of a circle given it's center (x1,y1) and any point in the circle (x2,y2)
double Circle<T>::radius() {
    return distance();
}

template<typename T>
// Returns the circumference of a circle given its radius
double Circle<T>::circumference() {
	return 2*PI*radius();
}

template<typename T>
// Returns the area of a circle given its radius
double Circle<T>::area() {
	return PI*pow(radius(),2);
}

template<typename T>
// Populates the circle's coordinate pairs
void Circle<T>::populate_classobj(T x1, T y1, T x2, T y2) {
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

#endif
