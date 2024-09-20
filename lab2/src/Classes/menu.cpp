#include "menu.h"
#include <iostream>
using namespace std;

// Displays menu and records choice in menu.choice
void Menu::menu() {
    cout << "(1) Compute the radius of the circle" << endl;
    cout << "(2) Compute the circumference of the circle" << endl;
    cout << "(3) Compute the area of the circle" << endl;
    cout << "(4) Enter new coordinates" << endl;
    cout << "(5) Exit program" << endl;

    cout << "> ";
    if (!(cin >> choice)) {
        // We will exit on non-double inputs (Menu option, and coordinate inpt). Unsure how to handle cin error correctly to allow retry in this case.
    	set_exit();
    }
}

// Gets both pairs of coordinates
void Menu::get_cords(Circle &circle) {
    if (enter_cords) {
    	double x1,y1,x2,y2;

    	// There is no circle cords yet, so we ask the user to enter them
    	cout << "Enter a circle's center coordinate:" << endl << "> ";
    	x1 = get_cord_input("x: ");
    	y1 = get_cord_input("y: ");

    	cout << "Enter another point in the circle:" << endl << "> ";
    	x2 = get_cord_input("x: ");
    	y2 = get_cord_input("y: ");

    	enter_cords = 0;
    	circle.populate_classobj(x1,x2,y1,y2);
    }
}
// Small helper to accept user input for a given coordinate
double Menu::get_cord_input(string cord) {
    double resp;
    cout << "	" << cord;
    cin >> resp;
    return resp;
}

void Menu::set_exit() {
	exit = 1;
}

int Menu::get_exit() {
	return exit;
}

int Menu::get_choice() {
	return choice;
}

void Menu::set_enter_cords() {
	enter_cords = 1;
}
