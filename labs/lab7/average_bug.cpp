/*
	Sample code to be used with Valgrind Memory Debugger
	Written by Justin Goins
	This code has bugs!
*/

#include <iostream>
#include <cstdlib>
using namespace std;

#define NUMSTUDENTS 15

/*
	This function accepts a pointer to a double (which will be set to the average),
	a pointer to an array, and an int with the number of items in the array.
*/

void calculate_average(double* result, int* array, int num) {
	cout << "Calculating the average value... " << endl;

	int sum = 0;
	for (int i = 1; i <= num; i++) {
		cout << "Grade " << i << ": " << array[i-1] << endl; // Was array[i] which would read beyond the end of the array.
		sum += array[i-1]; // Another error with program reading outside the array.
	}
	//cout << "Sum: " << sum << endl;
	*result = (double)sum/num;
	//cout << "Result: " << *result << endl;

}

/*
	This program is designed to calculate the average of an array of values.
*/
int main() {
	int* grades = new int[NUMSTUDENTS];
	double* average = new double;

	// fill the grades with random values
	srand(time(0));
	for (int i = 0; i < NUMSTUDENTS; i++) {
		grades[i] = rand() % (100 + 1);
	}

	calculate_average(average, grades, NUMSTUDENTS);

	cout << "The calculated average is: " << *average << endl; // Had to dereference average as it was printing the address, as average is defined as a pointer.

	// clean up the dynamic memory
	delete[] grades;
	delete average; // Added this to delete the memory location tied up by average

  return 0;
}
