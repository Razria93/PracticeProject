#include <iostream>

#include "LinkedList.h"

int main()
{
	std::printf("## Init ##\n");
	LinkedList<int>* linkedList_int = new LinkedList<int>;
	// LinkedList::PrintLinkedListData(linkedList_int);

	std::printf("## PushBack ##\n");
	linkedList_int->PushBack(100);
	linkedList_int->PushBack(200);
	linkedList_int->PushBack(300);
	// LinkedList::PrintLinkedListData(linkedList_int);
	// LinkedList::PrintAllNodeData(linkedList_int);

	std::printf("## PushFront ##\n");
	linkedList_int->PushFront(400);
	linkedList_int->PushFront(500);
	linkedList_int->PushFront(600);
	// LinkedList::PrintLinkedListData(linkedList_int);
	// LinkedList::PrintAllNodeData(linkedList_int);

	std::printf("## PopFront ##\n");
	std::printf("%-15s : %-5s\n", "bPopFront", linkedList_int->PopFront() ? "true" : "false");
	// LinkedList::PrintLinkedListData(linkedList_int);
	// LinkedList::PrintAllNodeData(linkedList_int);

	std::printf("## PopBack ##\n");
	std::printf("%-15s : %-5s\n", "bPopBack", linkedList_int->PopBack() ? "true" : "false");
	// LinkedList::PrintLinkedListData(linkedList_int);
	// LinkedList::PrintAllNodeData(linkedList_int);

	// std::printf("## Contain_Case01##\n");
	// size_t targetIdx_0 = 1;
	// std::printf("%-15s : %-5s (TargetIdx: %zd)\n", "bContain", linkedList_int->Contain(targetIdx_0) ? "true" : "false", targetIdx_0);
	// LinkedList::PrintLinkedListData(linkedList_int);
	// LinkedList::PrintAllNodeData(linkedList_int);

	// std::printf("## Contain_Case02##\n");
	// size_t targetIdx_1 = 5;
	// std::printf("%-15s : %-5s (TargetIdx: %zd)\n", "bContain", linkedList_int->Contain(targetIdx_1) ? "true" : "false", targetIdx_1);
	// LinkedList::PrintLinkedListData(linkedList_int);
	// LinkedList::PrintAllNodeData(linkedList_int);

	// std::printf("## Find##\n");
	// int targetValue = 100;
	// Node<T>* findNode = linkedList_int->Find(targetValue);
	//
	// std::printf("%-15s : %-5s\n", "IsValid", findNode ? "Valid" : "InValid");
	//
	// if(findNode)
	// 	std::printf("%-15s : CurPointer: %p | Value: %d | NextPointer: %p\n", "Find", findNode, findNode->Value, findNode->Next);
	//
	// LinkedList::PrintLinkedListData(linkedList_int);
	// LinkedList::PrintAllNodeData(linkedList_int);

	std::printf("## Insert_after##\n");
	size_t targetIdx_insert = 3;
	int targetValue_insert = 1000;
	std::printf("%-15s : %-5s\n", "Insert_after", linkedList_int->Insert_after(targetIdx_insert, targetValue_insert) ? "true" : "false");
	LinkedList<int>::PrintLinkedListData(linkedList_int);
	LinkedList<int>::PrintAllNodeData(linkedList_int);

	std::printf("## erase_after##\n");
	size_t targetIdx_erase = 0;
	std::printf("%-15s : %-5s\n", "erase_after", linkedList_int->erase_after(targetIdx_erase) ? "true" : "false");
	LinkedList<int>::PrintLinkedListData(linkedList_int);
	LinkedList<int>::PrintAllNodeData(linkedList_int);

	std::printf("## Clear ##\n");
	linkedList_int->Clear();
	// LinkedList::PrintLinkedListData(linkedList_int);
	// LinkedList::PrintAllNodeData(linkedList_int);

	/* ---------- char Case ---------- */

	std::printf("## Init ##\n");
	LinkedList<char>* linkedList_char = new LinkedList<char>;
	// LinkedList<char>::PrintLinkedListData(linkedList_char);

	std::printf("## PushBack ##\n");
	linkedList_char->PushBack('a');
	linkedList_char->PushBack('b');
	linkedList_char->PushBack('c');
	// LinkedList<char>::PrintLinkedListData(linkedList_char);
	// LinkedList<char>::PrintAllNodeData(linkedList_char);

	std::printf("## PushFront ##\n");
	linkedList_char->PushFront('x');
	linkedList_char->PushFront('y');
	linkedList_char->PushFront('z');
	// LinkedList<char>::PrintLinkedListData(linkedList_char);
	// LinkedList<char>::PrintAllNodeData(linkedList_char);

	std::printf("## PopFront ##\n");
	std::printf("%-15s : %-5s\n", "bPopFront", linkedList_char->PopFront() ? "true" : "false");
	// LinkedList<char>::PrintLinkedListData(linkedList_char);
	// LinkedList<char>::PrintAllNodeData(linkedList_char);

	std::printf("## PopBack ##\n");
	std::printf("%-15s : %-5s\n", "bPopBack", linkedList_char->PopBack() ? "true" : "false");
	// LinkedList<char>::PrintLinkedListData(linkedList_char);
	// LinkedList<char>::PrintAllNodeData(linkedList_char);

	// std::printf("## Contain_Case01##\n");
	// size_t targetIdx_0 = 1;
	// std::printf("%-15s : %-5s (TargetIdx: %zd)\n", "bContain", linkedList_char->Contain(targetIdx_0) ? "true" : "false", targetIdx_0);
	// LinkedList<char>::PrintLinkedListData(linkedList_char);
	// LinkedList<char>::PrintAllNodeData(linkedList_char);

	// std::printf("## Contain_Case02##\n");
	// size_t targetIdx_1 = 5;
	// std::printf("%-15s : %-5s (TargetIdx: %zd)\n", "bContain", linkedList_char->Contain(targetIdx_1) ? "true" : "false", targetIdx_1);
	// LinkedList<char>::PrintLinkedListData(linkedList_char);
	// LinkedList<char>::PrintAllNodeData(linkedList_char);

	// std::printf("## Find##\n");
	// char targetValue = 'a';
	// Node<char>* findNode = linkedList_char->Find(targetValue);
	// 
	// std::printf("%-15s : %-5s\n", "IsValid", findNode ? "Valid" : "InValid");
	// 
	// if (findNode)
	// 	std::printf("%-15s : CurPointer: %p | Value: %c | NextPointer: %p\n", "Find", findNode, findNode->Value, findNode->Next);
	// 
	// LinkedList<char>::PrintLinkedListData(linkedList_char);
	// LinkedList<char>::PrintAllNodeData(linkedList_char);

	std::printf("## Insert_after##\n");
	size_t targetIdx_insert_char = 3;
	char targetValue_insert_char = 'i';
	std::printf("%-15s : %-5s\n", "Insert_after", linkedList_char->Insert_after(targetIdx_insert_char, targetValue_insert_char) ? "true" : "false");
	LinkedList<char>::PrintLinkedListData(linkedList_char);
	LinkedList<char>::PrintAllNodeData(linkedList_char);

	std::printf("## erase_after##\n");
	size_t targetIdx_erase_char = 0;
	std::printf("%-15s : %-5s\n", "erase_after", linkedList_char->erase_after(targetIdx_erase_char) ? "true" : "false");
	LinkedList<char>::PrintLinkedListData(linkedList_char);
	LinkedList<char>::PrintAllNodeData(linkedList_char);

	std::printf("## Clear ##\n");
	linkedList_char->Clear();
	// LinkedList<char>::PrintLinkedListData(linkedList_char);
	// LinkedList<char>::PrintAllNodeData(linkedList_char);


	delete linkedList_char;
	return 0;
}