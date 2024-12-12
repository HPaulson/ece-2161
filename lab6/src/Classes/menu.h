#ifndef MENU_H
#define MENU_H

#include <iostream>
using namespace std;

class Menu {
private:
	int choice; // The choice number selected by a user
	int exit = 0; // We will exit the menu loop if this is set to 1.
public:
	void menu(string[], int);
	void set_exit();
	int get_exit();
	int get_choice();
};

// Displays menu and records choice in menu.choice
void Menu::menu(string choices[], int length) {
	for (int i = 1; i <= length; i++){
		cout << "(" << i << ")" << " " << choices[i-1] << endl;
	}

    cout << "> ";
    if (!(cin >> choice)) {
    	set_exit();
    }
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
