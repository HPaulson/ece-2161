// Hunter Paulson
// ECE 2161 - Lab 3
// CLI to calculate circumference, area, and radius of a circle given its center and a point using templates

#include <iostream>
#include "Classes/circle.h"
#include "Classes/menu.h"
using namespace std;

int main() {
	// Create two circle objects with respective types & default values
    Circle<int> circle1(1, 3);
    Circle<double> circle2(-1.5, -6.65, -.5, 10);
    Menu menu;

    // Menu loop. It will print the menu, and continue doing so after each selected option until the program is exited.
    do{
        menu.menu(); // Shows menu options & proceeds accordingly
        switch (menu.get_choice()) {
            case 1: {
                cout << "Radii:" <<endl << "	Circle 1: " << circle1.radius() << endl << "	Circle 2: " << circle2.radius() << endl;
                break;
            }
            case 2: {
                cout << "Circumference:" <<endl << "	Circle 1: " << circle1.circumference() << endl << "	Circle 2: " << circle2.circumference() << endl;
                break;
            }
            case 3: {
                cout << "Area:" <<endl << "	Circle 1: " << circle1.area() << endl << "	Circle 2: " << circle2.area() << endl;
                break;
                break;
            }
            case 4: {
            	menu.get_cords(circle1); // Get new cords for circle 1, pass by ref.
                break;
            }
            case 5: {
            	menu.get_cords(circle2); // Get new cords for circle 2, pass by ref.
                break;
            }
            case 6: {
                menu.set_exit();
                break;
            }
            default: {
            	if (cin.fail()) {
            		// I'm not totally sure what the "correct" way to handle non-double input is (Correct as in, the user is able to try again).
            		cout << "Invalid choice. Exiting." << endl;
            		menu.set_exit();
            	}
            	else cout << "Invalid choice. Try again." << endl;
                break;
            }
        }

    } while(!menu.get_exit());

    return 0;
}
