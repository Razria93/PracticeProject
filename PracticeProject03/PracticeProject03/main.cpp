#include <iostream>

#include "LinkedList.h"

int main()
{
	LinkedList* linkedList = new LinkedList;
	LinkedList::PrintLinkedListData(linkedList);

	linkedList->PushBack(100);
	linkedList->PushBack(200);
	linkedList->PushBack(300);

	LinkedList::PrintLinkedListData(linkedList);
	LinkedList::PrintAllNodeData(linkedList);

	linkedList->PushFront(400);
	linkedList->PushFront(500);
	linkedList->PushFront(600);

	LinkedList::PrintLinkedListData(linkedList);
	LinkedList::PrintAllNodeData(linkedList);

	delete linkedList;
	return 0;
}