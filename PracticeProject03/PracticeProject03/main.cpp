#include <iostream>

#include "LinkedList.h"

int main()
{
	std::printf("## Init ##\n");
	LinkedList* linkedList = new LinkedList;

	delete linkedList;
	return 0;
}