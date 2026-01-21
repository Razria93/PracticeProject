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
		: Value(InValue), Next(nullptr)
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
		: Head(nullptr), Tail(nullptr), Size(0)
	{
		std::printf("[Constructor]\n");
	}

	~LinkedList()
	{
		std::printf("[Destructor]\n");
		
		for (int i = 0; i < Size; ++i)
		{
			if (!Head) break;

			Node* oldHead = Head;
			Head = Head->Next;

			oldHead->Value = 0;
			oldHead->Next = nullptr;

			delete oldHead;
		}

		Head = nullptr;
		Tail = nullptr;
		Size = 0;
	}
};