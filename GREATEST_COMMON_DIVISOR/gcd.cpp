#include <iostream>
#include "ArrayList.h"

// This is my own implementation of the euclidean algorithm in c++. I created this pattern by myself (I only used tutorials to create "ArrayList.h").
int main(int argc, char* argv[]) {

	int p = 27;
	int q = 11;

	int const N = p * q;
	const int M = (p-1) * (q-1);
	const int A = 54;

	int counter = 1;

	int m = M;
	int a = A;

	ArrayList<int> rest_list;
	rest_list.append(m);
	while (a != 0) {
		rest_list.append(m / a);
		rest_list.append(a);
		a = m % a;
		m = rest_list.get(counter + 1);
		counter += 2;
	}
	
	std::cout << "--------------------" << std::endl;
	for (int i = 0; i < rest_list.getSize(); i++)
		std::cout << rest_list.get(i) << std::endl;
	std::cout << "--------------------" << std::endl;
	
	std::cout << "Greatest common divisor : " << rest_list.get(rest_list.getSize() - 1) << "\n" << std::endl;
	
	system("pause");
	return 0;
}
