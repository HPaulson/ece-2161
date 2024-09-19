#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
	double x1, y1, x2, y2;
protected:
	double distance();
public:
	double radius();
	double circumference();
	double area();
	void populate_classobj(double, double, double, double);
};

#endif
