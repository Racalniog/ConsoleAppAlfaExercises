#include "Header.h"

//array with smart pointers for safe memory management
unique_ptr<int[]> createArray(int a) {
	unique_ptr<int[]> dynamicArray = make_unique<int[]>(a);
	return dynamicArray;
}


unique_ptr<int[]> fillArray(unique_ptr<int[]> a) {
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		a[i] = i;
	}
	return a;
}

void printArray(unique_ptr<int[]> a) {
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		cout << a[i] << '\n';
	}
}