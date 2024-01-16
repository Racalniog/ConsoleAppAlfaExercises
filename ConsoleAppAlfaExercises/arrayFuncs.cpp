#include "Header.h"

//array with smart pointers for safe memory management
unique_ptr<int[]> createArray(int a) {
	unique_ptr<int[]> dynamicArray = make_unique<int[]>(a);
	return dynamicArray;
}