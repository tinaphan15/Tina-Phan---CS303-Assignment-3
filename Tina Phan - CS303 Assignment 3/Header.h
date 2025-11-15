#pragma once
#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename Item_Type>
class Queue {
private:
	struct Node {
		Item_Type data;
		Node* next;
		Node(const Item_Type& data, Node* next = nullptr) : data(data), next(next) {}
	};

	Node* head;
	Node* tail;
	int count;

public:
	// Constructor
	Queue() : head(nullptr), tail(nullptr), count(0) {}

	// Member functions
	void push(Item_Type value) {
		Node* n = new Node(value);

		if (!tail) {
			head = tail = n;
		}
		else {
			tail->next = n;
			tail = n;
		}
		count++;
	}

	void pop() {
		if (!head) {
			return;
		}

		Node* temp = head;
		head = head->next;
		
		if (!head) {
			tail = nullptr;
		}

		delete temp;
		count--;
	}

	Item_Type front() const {
		if (!head) {
			throw runtime_error("Queue is empty.");
		}
		return head->data;
	}

	int size() {
		return count;
	}

	bool empty() const {
		return head == nullptr;
	}

	// Function that moves the elements from the front of the queue to the rear of the queue
	void move_to_rear() {
		int n = size();
		for (int i = 0; i < n; i++) {
			push(front());
			pop();
		}
	}
};

// Recursive linear search function that finds the last occurrence of a target in a vector
template <typename T>
int linear_search(vector<T>& items, T& target, size_t pos_first = 0) {
	if (pos_first == items.size()) {
		return -1;
	}

	int index = linear_search(items, target, pos_first + 1); // Recursive step

	if (index != -1) {
		return index;
	}
	else if (items[pos_first] == target) {
		return pos_first;
	}
	else {
		return -1;
	}
}

// Insertion sort that can sort a list of integers (I used an LLM to help for this function)
void insertion_sort(list<int>& num) {
	if (num.empty()) {
		return;
	}

	for (auto it = next(num.begin()); it != num.end(); ++it) { // Sorts through the list
		int key = *it;
		auto j = it;

		while (j != num.begin() && *prev(j) > key) {
			*j = *prev(j);
			--j;
		}
		*j = key;
	}
}