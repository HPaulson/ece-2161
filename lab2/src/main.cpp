// Hunter Paulson
// ECE 2161 - Lab 2
// CLI to calculate circumference, area, and radius of a circle given its center and a point using classes

#include <iostream>
#include "Classes/circle.h"
#include "Classes/menu.h"
using namespace std;

int main() {
    Circle mycircle;
    Menu menu;

    // Menu loop. It will print the menu, and continue doing so after each selected option until the program is exited.
    do{
        menu.get_cords(mycircle); // Prompt for entering cords. Populates mycircle (pass by ref) with the entered values.
        menu.menu(); // Shows menu options & proceeds accordingly
        switch (menu.choice) {
            case 1: {
                cout << "Radius: " << mycircle.radius() << endl;
                break;
            }
            case 2: {
            	cout << "Circumference: " << mycircle.circumference() << endl;
                break;
            }
            case 3: {
            	cout << "Area: " << mycircle.area() << endl;
                break;
                break;
            }
            case 4: {
            	// This was not in the instructions but it made sense to add. Allows user to re-enter cords and use the tool for a new circle.
            	menu.set_enter_cords();
                break;
            }
            case 5: {
                menu.set_exit();
                break;
            }
            default: {
            	if (cin.fail()) {
            		// As with last lab, I'm not totally sure what the "correct" way to handle non-double input is (Correct as in, the user is able to try again).
            		cout << "Invalid choice. Exiting." << endl;
            		menu.set_exit();
            	}
            	else cout << "Invalid choice. Try again." << endl;
                break;
            }
        }

    } while(!menu.exit);

    return 0;
}
