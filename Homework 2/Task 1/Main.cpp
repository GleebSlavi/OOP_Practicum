#include <iostream>
#include "String.h"

int main()
{
	String s1, s2;
	s1.setString("Young", 6, 7);
	s2.setString("Thug", 5, 7);
	std::cout << s1.operator[](5) << std::endl;
	return 0;
}