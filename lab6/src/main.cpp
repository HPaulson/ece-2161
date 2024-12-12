// Hunter Paulson
// ECE 2161 - Lab 6
// This program allows for creating sorted and unsorted lists, queues, and stacks of integers using a DLL and simple tui.
// Everything works as expected.

#include <iostream>
#include <string>
#include "Classes/menu.h"
#include "Classes/intDLList.h"

using namespace std;
/*
This file has a repeated pattern for each menu and nested menu we will display to the user.

For each menu we declare an instance of the Menu class, which will handle choice selection and
printing the menu choices. We call the menu method of that class with an array of string choices,
which will get number 1-n. We also path the length of this array into the method. This will print
the choices with their respective number option, and prompt the user to choose an option. This is
a synchronous process, so after calling the method we can use the get_choice method to switch on
the user's numeric choice. We then handle their choice according to the option they selected,
like creating a new list or adding an item to a queue.

We wrap memu selection in a do{}while() so that after each choice they can continue to make
additional choices until they select an option that calls the set_exit method on the main menu.
*/
int main() {
	Menu mainMenu;
	do {
		string mainMenuChoices[5] = {"Create simple (unsorted) list", "Create sorted list", "Create queue (FIFO)", "Create Stack (LIFO)", "Exit program."};
		mainMenu.menu(mainMenuChoices, 5);

		switch (mainMenu.get_choice()) {
			case 1: {
				intDLList UnsortedList;
				Menu optionOneMenu;

				do {
					string optionOneMenuChoices[7] = {"Enter integer for insertion at head of list", "Enter integer for insertion at tail of list", "Display and delete integer from head of list", "Display and delete integer from tail of list", "Search for integer in list, and delete that node", "Display contents of list from head to tail, in order", "Exit program"};
					optionOneMenu.menu(optionOneMenuChoices, 7);
					switch (optionOneMenu.get_choice()) {
					case 1: {
						int el;
						cout << "> ";
						cin >> el;

						UnsortedList.addToHead(el);
						cout << endl << "Added " << el << " to head." << endl;
						break;
					}
					case 2: {
						int el;
						cout << "> ";
						cin >> el;

						UnsortedList.addToTail(el);
						cout << endl << "Added " << el << " to tail." << endl;
						break;
					}
					case 3: {
						try {
						int i = UnsortedList.deleteFromHead();
						cout << "Removed " << i << " from head." << endl;
						}
						catch (...) {
							cout << "List is empty." << endl;
						}
						break;
					}
					case 4: {
						try {
						int i = UnsortedList.deleteFromTail();
						cout << "Removed " << i << " from tail." << endl;
						}
						catch (...) {
							cout << "List is empty." << endl;
						}
						break;
					}
					case 5: {
						int el;
						cout << "> ";
						cin >> el;

						bool inList = UnsortedList.isInList(el);
						if (!inList) cout << "Did not find " << el << " in list." << endl;
						else {
							UnsortedList.deleteNode(el);
							cout << "Deleted " << el << endl;
						}

						break;
					}
					case 6: {
						UnsortedList.printlist(headToTail);
						 break;
										}
					case 7: {
						optionOneMenu.set_exit();
						mainMenu.set_exit();
						break;
					}
					default: {
						if (cin.fail()) {
							cout << "Invalid choice. Exiting." << endl;
							optionOneMenu.set_exit();
							mainMenu.set_exit();
						}
						else cout << "Invalid choice. Try again." << endl;
						break;
					}
				}
				} while(!optionOneMenu.get_exit());
				break;
			}
			case 2: {
				// Setup for menu similar to the previous two.
				intDLList SortedList;
				Menu optionTwoMenu;

				do {
					string optionTwoMenuChoices[4] = {"Enter integer for sorted insertion into list", "Search and delete integer, if present in list", "Display contents of sorted list of integers, in increasing order", "Exit program"};
					optionTwoMenu.menu(optionTwoMenuChoices, 4);
					switch (optionTwoMenu.get_choice()) {
					case 1: {
						int el;
						cout << "> ";
						cin >> el;

						SortedList.addSorted(el);
						cout << endl << "Added " << el << "." << endl;
						break;
					}
					case 2: {
						int el;
						cout << "> ";
						cin >> el;

						bool inList = SortedList.isInList(el);
						if (!inList) cout << "Did not find " << el << " in list." << endl;
						else {
							SortedList.deleteNode(el);
							cout << "Deleted " << el << endl;
						}

						break;
					}
					case 3: {
						SortedList.printlist(headToTail);
						 break;
					}
					case 4: {
						optionTwoMenu.set_exit();
						mainMenu.set_exit();
						break;
					}
					default: {
						if (cin.fail()) {
							cout << "Invalid choice. Exiting." << endl;
							optionTwoMenu.set_exit();
							mainMenu.set_exit();
						}
						else cout << "Invalid choice. Try again." << endl;
						break;
					}
				}
				} while(!optionTwoMenu.get_exit());
				break;
			}
			case 3: {
				intDLList Queue;
				Menu optionThreeMenu;

				do {
					string optionTwoMenuChoices[4] = {"ENQUEUE", "DEQUEUE", "PRINT QUEUE (first element first)", "Exit program"};
					optionThreeMenu.menu(optionTwoMenuChoices, 4);
					switch (optionThreeMenu.get_choice()) {
					case 1: {
						int el;
						cout << "> ";
						cin >> el;

						Queue.addToHead(el);
						cout << endl << "Added " << el << " to the queue." << endl;
						break;
					}
					case 2: {

						try {
							int i = Queue.deleteFromTail();
							cout << endl << "Removed " << i << " from the queue." << endl;
						}
						catch (...) {
							cout << "Queue is empty." << endl;
						}
						break;
					}
					case 3: {
						 Queue.printlist(tailToHead);
						 break;
					}
					case 4: {
						optionThreeMenu.set_exit();
						mainMenu.set_exit();
						break;
					}
					default: {
						if (cin.fail()) {
							cout << "Invalid choice. Exiting." << endl;
							optionThreeMenu.set_exit();
							mainMenu.set_exit();
						}
						else cout << "Invalid choice. Try again." << endl;
						break;
					}
				}
				} while(!optionThreeMenu.get_exit());
				break;
			}
			case 4: {
				intDLList Stack;
				Menu optionFourMenu;

				do {
					string optionTwoMenuChoices[4] = {"PUSH", "POP", "PRINT STACK", "Exit program"};
					optionFourMenu.menu(optionTwoMenuChoices, 4);
					switch (optionFourMenu.get_choice()) {
					case 1: {
						int el;
						cout << "> ";
						cin >> el;

						Stack.addToTail(el);
						cout << endl << "Added " << el << " to the stack." << endl;
						break;
					}
					case 2: {

						try {
							int i = Stack.deleteFromTail();
							cout << endl << "Removed " << i << " from the stack." << endl;
						}
						catch (...) {
							cout << "Queue is empty." << endl;
						}
						break;
					}
					case 3: {
						 Stack.printlist(tailToHead);
						 break;
					}
					case 4: {
						optionFourMenu.set_exit();
						mainMenu.set_exit();
						break;
					}
					default: {
						if (cin.fail()) {
							cout << "Invalid choice. Exiting." << endl;
							optionFourMenu.set_exit();
							mainMenu.set_exit();
						}
						else cout << "Invalid choice. Try again." << endl;
						break;
					}
				}
				} while(!optionFourMenu.get_exit());
				break;
			}
			case 5: {
				mainMenu.set_exit();
				break;
			}
			default: {
				if (cin.fail()) {
					cout << "Invalid choice. Exiting." << endl;
					mainMenu.set_exit();
				}
				else cout << "Invalid choice. Try again." << endl;
				break;
			}
		}
	} while(!mainMenu.get_exit());


	return 0;
}
