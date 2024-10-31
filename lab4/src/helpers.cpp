#include <iostream>
#include <fstream>

using namespace std;

// Takes in a file by reference, opens it, and ensures it was opened correctly.
template <typename T>
int openFile(T &file, string filename) {
	file.open(filename);
	if (!file.is_open()) {
		return 1; // Return 1 so parent can check for err in opening
	}
	else return 0;
}

// Takes five numbers and returns the highest of the five
template <typename T>
T largestNum(T x1, T x2, T x3, T x4, T x5){
	T nums[] = {x1,x2,x3,x4,x5};
	T max = nums[0];
	for (int i = 1; i < 5; i++) {
		if (nums[i] > max) max = nums[i];
	}
	return max;
}

// Takes in a file by reference and gets its number of lines
template <typename T>
int getFileLineCount(T &file) {
	int nLines = 0;
	string line; // We don't use this value, but we must pass a string ref to getline()
	for (; !file.eof(); ++nLines) { // Runs loop until the entire file is read (eof). Increments number of lines each iteration.
		getline(file, line); // Gets next line of file and updates file ptr
	}
	return nLines;
}

// Takes in a file by reference and resets the file pointer
template <typename T>
void resetFilePtr(T &file) {
	file.clear();
	file.seekg(0);
}

