// Name: Tina Phan
// Course: CS303
// Assignment: Assignment 3

#include "Header.h"

int main() {
	// Question 1.
	Queue<int> q;

	for (int i = 1; i <= 10; i++) { // Pushes 10 values into the queue
		q.push(i);
	}

	int num = q.size();
	for (int i = 0; i < num; i++) { // Displays all the elements in a queue
		cout << q.front() << " ";
		q.push(q.front());
		q.pop();
	}
	cout << endl;

	q.move_to_rear(); // Moves the elements at the front of the queue to the rear of the queue

	for (int i = 0; i < num; i++) { // Displays all the elements in a queue after moving them
		cout << q.front() << " ";
		q.push(q.front());
		q.pop();
	}
	cout << endl;


	// Question 2.
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int target = 5;
	int find_last = linear_search(nums, target);

	if (find_last != -1) { // Displays the last occurrence of a target in a vector
		cout << "\nLast occurrence of " << target << " is at index: " << find_last << endl;
	}
	else {
		cout << target << " not found in vector. " << endl;
	}


	// Question 3.
	list<int> numbers = {1, 3, 2, 6, 4, 8, 9, 5, 7, 10};

	cout << "\nOriginal list: "; 
	for (int n : numbers) { // Displays the original list of numbers 
		cout << n << " ";
	}
	cout << endl;

	insertion_sort(numbers); // Calls the insertion sort function to sort the list of integers

	cout << "\nSorted list: ";
	for (int n : numbers) { // Displays the sorted list of numbers
		cout << n << " ";
	}
	cout << endl;

	return 0;
}