#pragma once
#include <iostream>

// vvvvvvvv Inspiration vvvvvvvvv
// https://www.youtube.com/watch?v=ryRf4Jh_YC0&ab_channel=TheCherno
// https://www.youtube.com/watch?v=RJPYy665fwg&ab_channel=SurajSharma

template<typename T>
class ArrayList {

private:
	T* data = nullptr;
	size_t number_of_elements = 0;
	size_t max_capacity = 5;

public:
	ArrayList() {
		data = new T[max_capacity];
	}

	~ArrayList() {
		delete[]data;
	}

	void expand() {
		max_capacity *= 2;
		int* temp = new T[max_capacity];

		for (size_t i = 0; i < number_of_elements; i++) {
			temp[i] = data[i];
		}

		delete[]data;
		data = temp;
		initialize();
	}

	void initialize() {
		for (size_t i = number_of_elements; i < max_capacity; i++)
			data[i] = 0;
	}

	void append(T el) {
		if (number_of_elements >= max_capacity)
			expand();
		data[number_of_elements++] = el;
	}

	T get(int index) {
		if (index >= number_of_elements || index < 0)
			throw("Index not in range!");

		return data[index];
	}

	void removeBack() {
		if (number_of_elements > 0)
			data[--number_of_elements] = 0;
		else
			throw("Empty array!");
	}

	size_t getSize() { return number_of_elements; }
};