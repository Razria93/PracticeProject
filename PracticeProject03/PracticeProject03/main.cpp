#include <iostream>

#include "LinkedList.h"

int main()
{
	LinkedList* linkedList = new LinkedList;
	LinkedList::PrintLinkedListData(linkedList);

	linkedList->push_back(1);
	linkedList->push_back(2);
	linkedList->push_back(3);

	LinkedList::PrintLinkedListData(linkedList);
	LinkedList::PrintAllNodeData(linkedList);

	delete linkedList;
	return 0;
}