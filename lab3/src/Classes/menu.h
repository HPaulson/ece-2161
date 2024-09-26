#ifndef MENU_H
#define MENU_H


#include <iostream>
using namespace std;

class Menu {
private:
	int choice; // The choice number selected by a user
	int exit = 0; // We will exit the menu loop if this is set to 1.
	double get_cord_input(string);
public:
	template<typename T>
	void get_cords(Circle<T> &circle);
	void menu();
	void set_exit();
	int get_exit();
	int get_choice();
};

// Displays menu and records choice in menu.choice
void Menu::menu() {
    cout << "(1) Compute the radii of the two circles" << endl;
    cout << "(2) Compute the circumference of the two circles" << endl;
    cout << "(3) Compute the area of the two circles" << endl;
    cout << "(4) Enter new coordinates for circle 1" << endl;
    cout << "(5) Enter new coordinates for circle 2" << endl;
    cout << "(6) Exit program" << endl;

    cout << "> ";
    if (!(cin >> choice)) {
        // We will exit on non-double inputs (Menu option, and coordinate inpt). Unsure how to handle cin error correctly to allow retry in this case.
    	set_exit();
    }
}

// Gets both pairs of coordinates
template<typename T>
void Menu::get_cords(Circle<T> &circle) {
    	T x1,y1,x2,y2;

    	// There is no circle cords yet, so we ask the user to enter them
    	cout << "Enter the circle's center coordinate:" << endl << "> ";
    	x1 = get_cord_input("x: ");
    	y1 = get_cord_input("y: ");

    	cout << "Enter another point in the circle:" << endl << "> ";
    	x2 = get_cord_input("x: ");
    	y2 = get_cord_input("y: ");

    	circle.populate_classobj(x1,y1,x2,y2);
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

#endif
