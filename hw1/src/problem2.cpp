#include "problem2.h"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void printPascalsTriangleFast(int lines) {
	vector<vector<double>> lineValues;
	for (int n = 0; n < lines; n++) {
	vector<double> lineN;
	for (int p = 0; p < n+1; p++) {
		if (n == 0 && p == 0) {
			lineN.push_back(1);
		}
		else {
			lineN.push_back(lineValues[n-1][p-1] + lineValues[n-1][p]);
		}
		cout << setw(5)<< right << lineN[p] << " ";
	}
	lineValues.push_back(lineN);
	cout << endl;
	}
}
