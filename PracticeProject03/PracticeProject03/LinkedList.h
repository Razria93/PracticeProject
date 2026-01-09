#pragma once

#include <iostream>
#include <typeinfo>

struct Node
{
public:
	int Value = 0;
	Node* Next = nullptr;

public:
	Node()
		: Value(0), Next(nullptr)
	{
	}

	Node(const int InValue)
		: Value(InValue)
	{
	}
};

class LinkedList
{
private:
	Node* Head = nullptr;
	Node* Tail = nullptr;
	size_t Size = 0;

public:
	LinkedList()
	{
		std::printf("[Constructor]\n");

		Head = nullptr;
		Tail = nullptr;
		Size = 0;
	}

	~LinkedList()
	{
		for (int i = 0; i < Size; ++i)
		{
			if (!Head) break;

			Node* old = Head;
			Head = Head->Next;

			old->Value = 0;
			old->Next = nullptr;

			delete old;
		}

		Size = 0;
	}

	LinkedList(const LinkedList&) = delete;				// copy constructor				[deprecated]
	LinkedList& operator=(const LinkedList&) = delete;	// copy assignment operator		[deprecated]

public:
	void SetSize(size_t InSize) { Size = InSize; }

public:
	size_t GetSize() const { return Size; }

public:
	bool Empty() const { return Size == 0; }

public:
	void PushFront(int InValue)
	{
		Node* newNode = new Node();

		newNode->Value = InValue;
		newNode->Next = nullptr;

		if (!Head)
		{
			Head = newNode;
			Tail = newNode;
		}
		else
		{
			Node* oldHead = Head;

			newNode->Next = oldHead;
			Head = newNode;
		}

		++Size;
	}

	void PushBack(int InValue)
	{
		Node* newNode = new Node();

		newNode->Value = InValue;
		newNode->Next = nullptr;

		if (!Tail)
		{
			Head = newNode;
			Tail = newNode;
		}
		else
		{
			Node* oldTail = Tail;

			oldTail->Next = newNode;
			Tail = newNode;
		}
		
		++Size;
	}

public:
	static void PrintLinkedListData(LinkedList* InLinkedList)
	{
		std::printf("[%s]\n", "PrintLinkedListData");
		if (InLinkedList == nullptr)
		{
			std::printf("========================================\n");
			std::printf("%-15s : %s\n", "LinkedList", "nullptr");
			std::printf("========================================\n");
			return;
		}

		std::printf("========================================\n");
		std::printf("%-15s : %p\n", "InLinkedList", (void*)InLinkedList);
		std::printf("%-15s : %p\n", "Head", (void*)InLinkedList->Head);
		std::printf("%-15s : %p\n", "Tail", (void*)InLinkedList->Tail);
		std::printf("%-15s : %zu\n", "Size", InLinkedList->Size);
		std::printf("========================================\n");
	}

	static void PrintNodeData(const Node* InNode, size_t InIdex)
	{
		
		if (InNode == nullptr)
		{
			std::printf("----------------------------------------\n");
			std::printf("[%s]\n", "PrintNodeData");
			std::printf("%-15s : %s\n", "Node", "nullptr");
			std::printf("----------------------------------------\n");
			return;
		}

		std::printf("----------------------------------------\n");
		std::printf("[%s]\n", "PrintNodeData");
		std::printf("%-15s : %zu\n", "NodeIndex", InIdex);
		std::printf("%-15s : %p\n", "Node", (void*)InNode);
		std::printf("%-15s : %s\n", "ValueType", typeid(int).name());
		std::printf("%-15s : %d\n", "Value", (int)InNode->Value);
		std::printf("%-15s : %p\n", "NextNode", (void*)InNode->Next);
		std::printf("----------------------------------------\n");
	}


	static void PrintAllNodeData(LinkedList* InLinkedList)
	{
		if (InLinkedList == nullptr)
		{
			std::printf("========================================\n");
			std::printf("[%s]\n", "PrintAllNodeData");
			std::printf("%-15s : %s\n", "LinkedList", "nullptr");
			std::printf("========================================\n");
			return;
		}

		if (InLinkedList->Head == nullptr)
		{
			std::printf("========================================\n");
			std::printf("[%s]\n", "PrintAllNodeData");
			std::printf("%-15s : %p\n", "LinkedList", (const void*)InLinkedList);
			std::printf("%-15s : %s\n", "Head", "nullptr");
			std::printf("%-15s : %zu\n", "Size", InLinkedList->Size);
			std::printf("========================================\n");
			return;
		}

		const Node* printNode = InLinkedList->Head;
		std::size_t index = 0;

		std::printf("========================================\n");
		std::printf("[%s]\n", "PrintAllNodeData");
		while (printNode != nullptr)
		{
			PrintNodeData(printNode, index);
			printNode = printNode->Next;
			++index;
		}
		std::printf("========================================\n");
	}
};