#include <iostream>
#include "Vector.h"

int main()
{
	int arr[3] = { 1,2,3 };
	int arr2[2] = { 4,5 };
	Vector v1, v2;
	v1.setVector(arr, 3, 5);
	v2.setVector(arr2, 2, 4);
	
	Vector v3;
	v3 = v1 + v2;
	v3.printVector();


	return 0;
}