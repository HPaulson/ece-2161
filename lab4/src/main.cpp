// Hunter Paulson
// ECE 2161 - Lab 4
// Pointers, Dynamic Arrays & File Processing
// Reads lab4_input and writes max values of each line to lab4_output

#include <iostream>
#include <fstream>
#include "helpers.cpp"

#define INPUT_FILE "./src/data/lab4_input.txt"
#define OUTPUT_FILE "./src/data/lab4_output.txt"

using namespace std;

int main() {
	// Create infile and outfile objects
	ifstream infile;
	ofstream outfile;

	// Call openFile to open the respective files and ensure they open correctly
	int infileErr = openFile(infile, INPUT_FILE);
	int outfileErr = openFile(outfile, OUTPUT_FILE);

	// openFile will return 1 if it couldn't open the file, so check for that case
	if (infileErr || outfileErr) {
		cout << "Failed to open file." << endl;
		return 1;
	}

	// Count lines of inFile, then create dynamic array to hold max values
	int nLines = getFileLineCount(infile);
 	double* maxValues = new double[nLines]; // Ideally I could use a template here (and below for x1 .. x5) so the file can have any number data type, but this is sufficient for now.
 	// Counting the lines moves the file ptr to the end of the file, so we must reset it before actually processing the file
	resetFilePtr(infile);

	// For each line,
	for (int i = 0; i < nLines; ++i) {
		// Read next 5 values from file ptr as doubles
		double x1, x2, x3, x4, x5;
		infile >> x1 >> x2 >> x3 >> x4 >> x5;
		// Set this line's index of maxValues to the largestNumber on this line
		maxValues[i] = largestNum(x1, x2, x3, x4, x5);
		// Write this value to the output file. In practice we wouldn't use a dynamic array (above) and would just do this, but the lab requires a dynamic array for learning purposes.
		outfile << maxValues[i];
		// Write endline unless this is the last line, that way the output file has the same numnber of lines as the infile (Does not having hanging whitespace line)
		if (i != nLines - 1) outfile << endl;
	}

	// Cleanup; Close both files & dealloc maxValues
	infile.close();
	outfile.close();
	delete [] maxValues;

	cout << "Wrote to" << OUTPUT_FILE << endl;
	return 0;
}

