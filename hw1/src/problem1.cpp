#include "problem1.h"
#include <iostream>
#include <iomanip>

using namespace std;

double factorial(int n) {
	double f = 1;
	for (int i = n; i > 0; i--) {
		f = f*(double)i;
	}
	return f;
}

void printPascalsTriangle(int lines) {
	for (int n = 0; n < lines; n++) {
	for (int p = 0; p < n+1; p++) {
		cout << setw(5)<< right << factorial(n) / (factorial(p)*factorial(n-p)) << " ";
	}
	cout << endl;
	}
}
