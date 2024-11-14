/*
 * mergesort.cpp
 *
 *  Created on: Nov 7, 2024
 *      Author: Hunter Paulson
 */

#include "myheader.h"
#include <iostream>


void merge(long data[], int leftIndex, int rightIndex) {
	// Sorting the portion of the array from leftIndex to rightIndex.
	// Left Sub-Array: data[leftIndex ... midIndex]
	// Right Sub-Array: data[midIndex+1 ... rightIndex]

	int midIndex = (leftIndex + rightIndex) / 2; // Calculate the midpoint of the array
	int i1 = 0; // Number of elements evaluated (Regardless of sub array)
	int i2 = leftIndex; // Index of the next element in the left sub-array
	int i3 = midIndex + 1; // Index of the next element in the right sub-array

	int tempSize = rightIndex - leftIndex + 1; 	// Number of elements to be sorted
	long temp[tempSize]; // Temp array holds result during calculation

	// Iterate until all the elements are done, the entire right sub-array is done, or the entire left sub-array is done
	while (i1 < tempSize && i2 <= midIndex && i3 <= rightIndex) {
		if (data[i2] < data[i3]) {
			temp[i1++] = data[i2++];
		}
		else {
			temp[i1++] = data[i3++];
		}
	}

	// If the previous loop finished because the right sub-array finished but the left sub-array still has remaining elements, add them to temp
	while (i2 <= midIndex) {
		temp[i1++] = data[i2++];
	}

	// Same as above but for remaining elements of right sub-array
	while (i3 <= rightIndex) {
		temp[i1++] = data[i3++];
	}

	// Put sorted elements from temp back into data in their appropriate order
	for (int i = 0; i < tempSize; i++) {
		data[leftIndex + i] = temp[i];
	}

	return;
}

void mergesort(long data[], int firstIndex, int lastIndex) {
	if (firstIndex < lastIndex) {
		// Sort by recursively splitting the main array into a left and right sub-array, then merging them.
		int midIndex = (firstIndex+lastIndex)/2;
		mergesort(data, firstIndex, midIndex);
		mergesort(data, midIndex+1, lastIndex);
		merge(data, firstIndex, lastIndex);
	}
	return;
}

