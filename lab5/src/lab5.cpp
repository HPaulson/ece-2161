// Hunter Paulson
// ECE 2161 - Lab 5
// Bubble & Merge Sort Time Complexity

// Included Sample Code:
// Copyright (C) 2023 Sarvesh Kulkarni <sarvesh.kulkarni@villanova.edu>
// If you are a student in the ECE 2161 lab, you may use this code.
// Permission is NOT granted to use this code for non-educational purposes.
// Write code for bubble sort, merge sort, etc. and call the functions in main.

// WARNING! WARNING! WARNING!
//  This program declares *very* large arrays. If you have not increased your
//  stack space, expect a segmentation fault. In order to increase your
//  stack space, run the following command from your terminal:
//  ulimit -s 819200

#include <iostream>
#include <ctime>
#include "myheader.h"

using namespace std;


int main() {

	int		choice, sz;
	long	data1[MAXSIZE], data2[MAXSIZE];
	double  begin_time, end_time, cpu_time_used;
	string  ifilename, ofilename;

	while (1) {

		printmenu();
		cin >> choice;

		switch (choice) {

			case 1: // Read input file and store data in arrays data1 and data2
                    // The function 'readfile' returns the size of the file that was read
					// If the file could not be read, 'readfile' returns -1

					ifilename = "./data/lab5_input.txt";
					sz = readfile(ifilename, data1, data2);

					if (sz < 0)	 {
						 cerr << endl << "ERROR: Input File Not Found or File cannot be opened." <<endl;
						 cerr << "       Please check that the file exists, its path, and try again!" << endl << endl;
						 return 0;
					}
					else cout << endl << "File size is: " << sz << endl;

					break;

			case 2: // Bubblesort

					begin_time = clock();   // start cpu timer

					// Call your BubbleSort function here to sort the array data1
			        //  Note that data1 is of size 'sz' (see case 1).
					bubblesort(data1, sz);


					end_time = clock();		// end cpu timer

					cpu_time_used = (end_time - begin_time) / CLOCKS_PER_SEC;
					cout << endl << "BubbleSort ran for " << cpu_time_used << " secs.";

					ofilename = "./data/lab5_bubbleout.txt";
					writefile(data1, sz, ofilename);

					if (sz < 0)	 {
						 cerr << endl << "ERROR: Output File could not be opened." <<endl;
						 cerr << "       Quiting Now!" << endl << endl;
						 return 0;
					}
					else cout << endl << "Output written to " << ofilename << endl;

					break;

			case 3: // Mergesort

					begin_time = clock();   // start cpu timer

					// Call your MergeSort function here to sort the array data2
			        //  Note that data2 is of size 'sz' (see case 1).
					mergesort(data2, 0, sz-1);



					end_time = clock();		// end cpu timer

					cpu_time_used = (end_time - begin_time) / CLOCKS_PER_SEC;
					cout << endl << "MergeSort ran for " << cpu_time_used << " secs.";

					ofilename = "./data/lab5_mergeout.txt";
					writefile(data2, sz, ofilename);

					if (sz < 0)	 {
						 cerr << endl << "ERROR: Output File could not be opened." <<endl;
						 cerr << "       Quiting Now!" << endl << endl;
						 return 0;
					}
					else cout << endl << "Output written to " << ofilename << endl;

					break;

			case 4: // Exit Program

					cout << endl << "Received program exit command - I QUIT!" << endl << endl;

					return 0;

			default: // Error in selection

					cout << endl << "Incorrect selection, try again from the menu below." << endl;

		} // switch

	} // while

	return 0;
}

