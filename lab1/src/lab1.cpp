// Hunter Paulson
// ECE 2161 - Lab 1
// CLI to calculate circumference, area, and radius of a circle given its center and a point

#include <iostream>
#include <cmath>
#define PI (4*atan(1))
using namespace std;

// Function prototypes
int menu();
double area(double);
double circumference(double);
double radius(double, double, double, double);
double distance(double, double, double, double);
double get_cord(string);

// Handles menu loop
int main() {
    int exit = 0; // We will exit the menu loop if this is set to 1.
    int enterCords = 1; // If circle cords need to be entered. We use this in a conditional in the menu loop so they can enter a new circle later if desired.
    double x1,y1,x2,y2;

    // Menu loop. It will print the menu, and continue doing so after each selected option until the program is exited.
    do{
        if (enterCords) {
        	// There is no circle cords yet, so we ask the user to enter them

        	cout << "Enter a circle's center coordinate:" << endl << "> ";
        	x1 = get_cord("x: ");
        	y1 = get_cord("y: ");

        	cout << "Enter another point in the circle:" << endl << "> ";
        	x2 = get_cord("x: ");
        	y2 = get_cord("y: ");

        	enterCords = 0;

        }

        double rad = radius(x1,y1,x2,y2); // No need to re-call radius function for every option, so we call it once here.
        int choice = menu(); // Display menu & get choice

        switch (choice) {
            case 1: {
                cout << "Radius: " << rad << endl;
                break;
            }
            case 2: {
            	cout << "Circumference: " << circumference(rad) << endl;
                break;
            }
            case 3: {
            	cout << "Area: " << area(rad) << endl;
                break;
                break;
            }
            case 4: {
            	// This was not in the instructions but it made sense to add. Allows user to re-enter cords and use the tool for a new circle.
            	enterCords = 1;
                break;
            }
            case 5: {
                exit = 1;
                break;
            }
            case -1:{
            	// This case will occur if the user enters a non-double input as a menu option. For invalid doubles we will allow try again (the default case),
            	// but I wasn't sure how to accomplish this for non-double invalid inputs. So just exits.
            	exit = 1;
                cout << "Invalid choice. Exiting.";
                break;
            }
            default: {
                cout << "Invalid choice. Try again.";
                break;
            }
        }
    } while(!exit);

    return 0;
}

int menu() {
    cout << "(1) Compute the radius of the circle" << endl;
    cout << "(2) Compute the circumference of the circle" << endl;
    cout << "(3) Compute the area of the circle" << endl;
    cout << "(4) Enter new coordinates" << endl;
    cout << "(5) Exit program" << endl;

    int resp;
    cout << "> ";
    if (!(cin >> resp)) {
        // We will exit on non-double inputs (Menu option, and coordinate inpt). Unsure how to handle cin error correctly to allow retry in this case.
    	return -1;
    }
    return resp;
}

// Returns the area of a circle given its radius
double area(double radius) {
	return PI*pow(radius,2);
}

// Returns the circumference of a circle given its radius
double circumference(double radius) {
	return 2*PI*radius;

}

// Returns the radius of a circle given it's center (x1,y1) and any point in the circle (x2,y2)
double radius(double x1, double y1, double x2, double y2) {
    return distance(x1, y1, x2, y1);
}

// Returns the distance between two points given the two points (x1,y1) and (x2,y2)
double distance(double x1, double y1, double x2, double y2) {
    double distance = sqrt(pow((x2-x1),2)+pow((y2-y1), 2));
    return distance;
}

// Accepts user input for coordinate
double get_cord(string cord) {
    double resp;
    cout << "	" << cord;
    cin >> resp;
    return resp;

}
