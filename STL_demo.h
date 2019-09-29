#pragma once
#include <iostream>
#include <vector>

using namespace std;

// ----- Vectors
/*
Description: Dynamic arrays that can reszize automatically. Stored contigously so can be accessed by iterators

Time Complexity:
Insertion: End -> O(N), Otherwise -> O(1), Amortized Constant Time
Deletion:  End -> O(N), Otherwise -> O(1), Amortized Constant Time
Selection: O(1)

*/

void printVector(vector<int> v, bool printAll = false) {
	// Print the vector from begining to end (using type iterator)
	cout << "Output v from begining to end: ";
	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
		cout << *i << " ";

	if (printAll == true) {
		// Print the vector from begining to end (using const auto iterator)
		cout << "\nOutput of v from cbegin and cend: ";
		for (auto i = v.cbegin(); i != v.cend(); ++i)
			cout << *i << " ";

		// Print the vector from end to begining (using auto iterator)
		cout << "\nOutput of v from rbegin and rend: ";
		for (auto ir = v.rbegin(); ir != v.rend(); ++ir)
			cout << *ir << " ";

		// Print the vector from end to begining (using const auto iterator)
		cout << "\nOutput of v from crbegin and crend : ";
		for (auto ir = v.crbegin(); ir != v.crend(); ++ir)
			cout << *ir << " ";
	}

	cout << "\n";
}

int getLast(vector<int> v) {
	int size = v.size();
	return v[size - 1];
}

bool isEmpty(vector<int> v) {
	if (v.empty()) {
		cout << "Vector is empty \n";
		return true;
	}
	else {
		cout << "Vector is not empty \n";
	}
	return false;
}

void vectorDemo() {
	const int size = 10;

	// Declare an empty vector
	vector<int> v;

	// Fill empty vector
	for (int i = 0; i < size; i++) {
		v.push_back(i);
	}

	// Print vector
	printVector(v, true);

	// Vector capacities
	cout << "Vector size: " << v.size() << "\n";
	cout << "Vector capacity: " << v.capacity() << "\n";
	cout << "Vector max size: " << v.max_size() << "\n";
	v.resize(4);
	cout << "Resize vector to 4 elements: " << v.size() << "\n";

	// Check if vector is empty
	isEmpty(v);

	v.shrink_to_fit();
	printVector(v);

	// Data acesss
	cout << "v[2] = " << v[2] << "\n";
	cout << "v.at(2) = " << v.at(2) << "\n";
	cout << "v.front() = " << v.front() << "\n";
	cout << "v.back() = " << v.back() << "\n";

	// Iterate over vector with ptr
	cout << "Iterate vector with ptr: ";
	int *ptr = v.data();

	// fill the array with n, m times -> v.assign(m, n)
	// fill v.assign(5,10) with 10 five times
	cout << "Filling v with 10 five times" << "\n";
	v.assign(5, 10);
	printVector(v);

	// Inserting 5 in the last position of v
	v.push_back(5);
	cout << "Inserting 5 in the last element of v" << "\n";
	cout << "The last element in v is: " << getLast(v) << "\n";

	// Remove the last element in v
	v.pop_back();
	cout << "Removing the last element of v" << "\n";
	cout << "The last element in v is: " << getLast(v) << "\n";

	// Inserting 5 in the second position
	v.insert(v.begin()+1, 5);
	cout << "Inserting in the second element of v" << "\n";
	printVector(v);

	// Erasing 5 in the second position
	v.erase(v.begin() + 1);
	cout << "Erasing the second element of v" << "\n";
	printVector(v);

	// Erase vector
	v.clear();
	cout << "Clearing v" << "\n";
	isEmpty(v);
	printVector(v);

	// Swag vector
	// two vector to perform swap 
	vector<int> v1, v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(4);
	v2.push_back(5);

	printVector(v1);
	printVector(v2);

	v1.swap(v2);

	printVector(v1);
	printVector(v2);

	return;
};