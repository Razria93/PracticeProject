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
		std::printf("[Destructor]\n");
		Clear();
	}

	LinkedList(const LinkedList&) = delete;				// copy constructor				[deprecated]
	LinkedList& operator=(const LinkedList&) = delete;	// copy assignment operator		[deprecated]

public:
	void SetSize(size_t InSize) { Size = InSize; }

public:
	size_t GetSize() const { return Size; }

public:
	bool Empty() { return Size == 0; }

public:
	void Clear()
	{
		std::printf("[Clear]\n");

		for (int i = 0; i < Size; ++i)
		{
			if (!Head) break;

			Node* oldHead = Head;
			Head = Head->Next;

			Delete(oldHead, i);
		}

		Head = nullptr;
		Tail = nullptr;
		Size = 0;
	}

public:
	void Delete(Node* InNode, size_t InIndex)
	{
		if (!InNode) return;

		std::printf("[Delete(Before)]\n");
		PrintNodeData(InNode, InIndex);

		InNode->Value = 0;
		InNode->Next = nullptr;

		std::printf("[Delete(After)]\n");
		PrintNodeData(InNode, InIndex);
		
		delete InNode;
	}

public:
	void PushFront(int InValue)
	{
		std::printf("[PushFront]\n");
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
		std::printf("[PushBack]\n");
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
	void PopFront()
	{
		if (!Head) return;
		if (Size <= 1) Clear();

		std::printf("[PopFront]\n");

		Node* oldHead = Head;

		Head = oldHead->Next ? oldHead->Next : nullptr;
		--Size;

		Delete(oldHead, 0);
	}

public:
	void PopBack()
	{
		if (!Head) return;
		if (!Tail) return;
		if (Size <= 1) Clear();

		std::printf("[PopBack]\n");

		Node* oldTail = Tail;
		Node* newTail = Head;
		size_t newSize = Size - 1;
		for (int i = 0; i < newSize; ++i)
		{
			if (i == (newSize - 1))
			{
				newTail->Next = nullptr;
			}

			// i < Size - 1
			if (newTail->Next)
			{
				newTail = newTail->Next;
			}
			else
			{
				break;
			}
		}

		Tail = newTail;
		Size = newSize;

		Delete(oldTail, Size);
	}

public:
	static void PrintLinkedListData(LinkedList* InLinkedList)
	{
		std::printf("========================================\n");
		std::printf("[%s]\n", "PrintLinkedListData");

		if (InLinkedList == nullptr)
		{
			std::printf("----------------------------------------\n");
			std::printf("%-15s : %s\n", "LinkedList", "nullptr");
			std::printf("========================================\n");
			return;
		}

		std::printf("----------------------------------------\n");
		std::printf("%-15s : %p\n", "InLinkedList", (void*)InLinkedList);
		std::printf("%-15s : %p\n", "Head", (void*)InLinkedList->Head);
		std::printf("%-15s : %p\n", "Tail", (void*)InLinkedList->Tail);
		std::printf("%-15s : %zu\n", "Size", InLinkedList->Size);
		std::printf("========================================\n");
	}

	static void PrintNodeData(const Node* InNode, size_t InIdex)
	{
		std::printf("========================================\n");
		std::printf("[%s]\n", "PrintNodeData");

		if (InNode == nullptr)
		{
			std::printf("----------------------------------------\n");
			std::printf("%-15s : %s\n", "Node", "nullptr");
			std::printf("========================================\n");
			return;
		}

		std::printf("----------------------------------------\n");
		std::printf("[%s]\n", "PrintNodeData");
		std::printf("%-15s : %zu\n", "NodeIndex", InIdex);
		std::printf("%-15s : %p\n", "Node", (void*)InNode);
		std::printf("%-15s : %s\n", "ValueType", typeid(int).name());
		std::printf("%-15s : %d\n", "Value", (int)InNode->Value);
		std::printf("%-15s : %p\n", "NextNode", (void*)InNode->Next);
		std::printf("========================================\n");
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