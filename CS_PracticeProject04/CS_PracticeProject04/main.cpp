#include <iostream>

#include "BinarySearchTree.h"

int main()
{
	std::printf("\n[BST Init]\n");
	BinarySearchTree bst;

	std::printf("\n[Insert]\n");
	bst.Insert(300);
	bst.Insert(100);
	bst.Insert(50);
	bst.Insert(200);
	bst.Insert(500);
	bst.Insert(400);
	bst.Insert(25);
	bst.Insert(75);

	// std::printf("\n[Find]\n");
	// Node* find_before = bst.Find(100);
	// std::printf("%-20s : Node: %-5p | InValue: %-5d\n", "Find_Result", find_before, find_before ? find_before->Value : -1);
	// 
	// Node* largest = bst.FindLargest();
	// std::printf("%-20s : Node: %-5p | InValue: %-5d\n", "FindLargest", largest, largest ? largest->Value : -1);
	// 
	// Node* smallest = bst.FindSmallest();
	// std::printf("%-20s : Node: %-5p | InValue: %-5d\n", "FindSmallest", smallest, largest ? smallest->Value : -1);

	// std::printf("\n[Erase_0]\n");
	// bool result_0 = bst.Erase(50);
	// std::printf("\n%-20s : %s\n", "[Erase_Result]", result_0 ? "Complete" : "Fail");
	// 
	// std::printf("\n[Erase_1]\n");
	// bool result_1 = bst.Erase(300);
	// std::printf("\n%-20s : %s\n", "[Erase_Result]", result_1 ? "Complete" : "Fail");
	// 
	// std::printf("\n[Find_0]\n");
	// Node* find_0 = bst.Find(50);
	// std::printf("%-20s : Node: %-5p | InValue: %-5d\n", "[Find_Result]", find_0, find_0 ? find_0->Value : -1);
	// 
	// std::printf("\n[Find_1]\n");
	// Node* find_1 = bst.Find(300);
	// std::printf("%-20s : Node: %-5p | InValue: %-5d\n", "[Find_Result]", find_1, find_1 ? find_1->Value : -1);

	// std::printf("\n[Clear]\n");
	// if (bst.Clear())
	// 	std::printf("[Clear_Complete]\n");
	// else
	// 	std::printf("[Clear_Failed]\n");

	return 0;
}