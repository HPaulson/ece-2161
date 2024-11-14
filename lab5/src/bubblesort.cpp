/*
 * bubblesort.cpp
 *
 *  Created on: Nov 7, 2024
 *      Author: Hunter Paulson
 */

#include "myheader.h"

void bubblesort(long data[], int size) {
	// For each element (i) in the array
	for (int i=0; i < size - 1; ++i) {
		// For each element (j) after the current element (i)
		for (int j = size-1; j> i; --j) {
			// Swap the values of data[j] and data[j-1] if they are in the incorrect order
			if (data[j] < data[j-1]) {
				swap(data[j], data[j-1]);
			}
		}
	}
}
