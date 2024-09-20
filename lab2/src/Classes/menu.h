#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "circle.h"
using namespace std;

class Menu {
private:
	int enter_cords = 1; // If circle cords need to be entered. We use this in a conditional in the menu loop so they can enter a new circle later if desired.
	int choice; // The choice number selected by a user
	int exit = 0; // We will exit the menu loop if this is set to 1.

	double get_cord_input(string);
public:
	void get_cords(Circle &circle);
	void menu();
	void set_exit();
	void set_enter_cords();
	int get_exit();
	int get_choice();
};

#endif
