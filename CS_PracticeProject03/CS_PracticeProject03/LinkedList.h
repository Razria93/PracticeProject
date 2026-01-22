#pragma once

#include <iostream>
#include <iomanip>
#include <typeinfo>

template<typename T>
struct Node
{
public:
	T Value;
	Node<T>* Prev = nullptr;
	Node<T>* Next = nullptr;

public:
	Node() = default;

	Node(const T& InValue)
		: Value(InValue)
	{
	}
};

template<typename T>
class LinkedList
{
private:
	Node<T>* Head = nullptr;
	Node<T>* Tail = nullptr;
	size_t Size = 0;

public:
	LinkedList() = default;

	~LinkedList()
	{
		Clear();
	}

// TODO:
// copy-constructor override
// operator= override

public:
	size_t GetSize() const { return Size; }

public:
	bool Empty() { return Size == 0; }

public:
	void Clear()
	{
		for (size_t i = 0; i < Size; ++i)
		{
			if (!Head) break;

			Node<T>* oldHead = Head;
			Head = Head->Next;

			Delete(oldHead, i);
		}

		Head = nullptr;
		Tail = nullptr;
		Size = 0;
	}

public:
	void Delete(Node<T>* InNode, size_t InIndex)
	{
		if (!InNode) return;

		// std::printf("[Delete(Before)]\n");
		// PrintNodeData(InNode, InIndex);

		InNode->Prev = nullptr;
		InNode->Next = nullptr;

		// std::printf("[Delete(After)]\n");
		// PrintNodeData(InNode, InIndex);

		delete InNode;
	}

public:
	void PushFront(const T& InValue)
	{
		Node<T>* newNode = new Node<T>();

		// Init Push Node
		newNode->Value = InValue;
		newNode->Prev = nullptr;
		newNode->Next = nullptr;

		if (!Head) // Init LinkedList
		{
			Head = newNode;

			if (!Tail)
			{
				Tail = newNode;
			}
		}
		else // Add to LinkedList
		{
			Node<T>* oldHead = Head;

			newNode->Next = oldHead;
			oldHead->Prev = newNode;
			Head = newNode;
		}

		++Size;
	}

	void PushBack(const T& InValue)
	{
		Node<T>* newNode = new Node<T>();

		// Init Push Node
		newNode->Value = InValue;
		newNode->Prev = nullptr;
		newNode->Next = nullptr;

		if (!Tail) // Init LinkedList
		{
			Tail = newNode;

			if (!Head)
			{
				Head = newNode;
			}
		}
		else  // Add to LinkedList
		{
			Node<T>* oldTail = Tail;

			newNode->Prev = oldTail;
			oldTail->Next = newNode;
			Tail = newNode;
		}

		++Size;
	}

public:
	bool PopFront()
	{
		if (!Head) return false;

		if (Size <= 1)
		{
			Clear();
			return true;
		}

		Node<T>* oldHead = Head;
		size_t oldHeadIdx = 0;

		size_t newSize = Size - 1;

		Node<T>* afterNode = oldHead->Next;
		if (!afterNode)
		{
			std::printf("%-15s : Pointer: %s | Index: %zd\n", "Error", "nullptr", oldHeadIdx + 1ull);
			return false;
		}
		else
		{
			afterNode->Prev = nullptr;

			Head = afterNode;
			Size = newSize;

			Delete(oldHead, oldHeadIdx);
			return true;
		}
		return false; // Undefined
	}

public:
	bool PopBack()
	{
		if (!Tail) return false;

		if (Size <= 1)
		{
			Clear();
			return true;
		}

		Node<T>* oldTail = Tail;
		size_t oldTailIdx = Size - 1;

		size_t newSize = Size - 1;

		Node<T>* beforeNode = oldTail->Prev;
		if (!beforeNode)
		{
			std::printf("%-15s : Pointer: %s | Index: %d\n", "Error", "nullptr", (int)oldTailIdx - 1);
			return false;
		}
		else
		{
			beforeNode->Next = nullptr;

			Tail = beforeNode;
			Size = newSize;

			Delete(oldTail, oldTailIdx);
			return true;
		}
		return false; // Undefined
	}

public:
	bool Contain(size_t InIndex)
	{
		if (!Head) return false;
		if (InIndex >= Size) return false;

		if (InIndex == 0) return true; // Head is Valid

		Node<T>* beforeNode = nullptr;
		for (size_t i = 0; i <= InIndex; ++i)
		{
			if (i == 0) // Init
			{
				beforeNode = Head;
				continue;
			}

			// UpdateNextNode
			Node<T>* curNode = beforeNode->Next;

			// Validate
			if (!curNode)
			{
				std::printf("%-15s : Pointer: %p | Index: %zd\n", "Error", curNode, i);
				return false;
			}

			// Check Index
			if (i < (InIndex))
			{
				beforeNode = curNode;
				curNode = nullptr;
				continue;
			}
			else // Last index (i == InIndex)
			{
				std::printf("%-15s : Pointer: %p | Index: %zd\n", "Valid", curNode, InIndex);
				return true;
			}
		}
		return false; // Undefined
	}

public:
	Node<T>* Find(const T& InValue)
	{
		Node<T>* beforeNode = nullptr;
		Node<T>* curNode = nullptr;

		for (size_t i = 0; i < Size; ++i)
		{
			if (i == 0)
			{
				curNode = Head;
			}
			else
			{
				curNode = beforeNode->Next;
			}

			// Validate
			if (!curNode) return nullptr;

			// Check
			if (curNode->Value == InValue)
			{
				return curNode;
			}
			else // curNode->Value != InValue
			{
				beforeNode = curNode;
				curNode = nullptr;
				continue;
			}
		}
		return nullptr; // Undefined
	}

public:
	bool Insert_after(size_t InIndex, const T& InValue)
	{
		if (!Head) return false;
		if (!Tail) return false;
		if (InIndex >= Size) return false;

		Node<T>* newNode = new Node<T>;
		newNode->Value = InValue;
		newNode->Prev = nullptr;
		newNode->Next = nullptr;

		if (InIndex == 0) // Head is Valid 
		{
			Node<T>* beforeNode = Head;
			Node<T>* afterNode = Head->Next;

			newNode->Prev = beforeNode;
			beforeNode->Next = newNode;

			if (afterNode)
			{
				newNode->Next = afterNode;
				afterNode->Prev = newNode;
			}
			else
			{
				newNode->Next = nullptr;
				Tail = newNode;
			}

			++Size;
			
			return true; 
		}

		Node<T>* beforeNode = nullptr;
		for (size_t i = 0; i <= InIndex; ++i)
		{
			if (i == 0) // Init
			{
				beforeNode = Head;
				continue;
			}

			// UpdateNextNode
			Node<T>* curNode = beforeNode->Next;

			// Validate
			if (!curNode)
			{
				std::printf("%-15s : Pointer: %p | Index: %zd\n", "Error", curNode, i);
				return false;
			}

			// Check Index
			if (i < (InIndex))
			{
				beforeNode = curNode;
				curNode = nullptr;
				continue;
			}
			else // Last index (i == InIndex)
			{
				Node<T>* beforeNode = curNode;
				Node<T>* afterNode = curNode->Next;

				newNode->Prev = beforeNode;
				beforeNode->Next = newNode;

				if (afterNode)
				{
					newNode->Next = afterNode;
					afterNode->Prev = newNode;
				}
				else
				{
					newNode->Next = nullptr;
					Tail = newNode;
				}

				++Size;

				std::printf("%-15s : Pointer: %p | Index: %zd\n", "Valid", curNode, InIndex);
				return true;
			}
		}
		return false; // Undefined
	}

public:
	bool erase_after(size_t InIndex)
	{
		if (!Head) return false;
		if (!Tail) return false;
		if (InIndex >= Size) return false;

		if (InIndex == 0) // Head is Valid 
		{
			Node<T>* curNode = Head;

			Node<T>* targetNode = Head->Next;
			if (!targetNode) return false;

			Node<T>* afterNode = targetNode->Next;

			if (afterNode)
			{
				curNode->Next = afterNode;
				afterNode->Prev = curNode;
			}
			else
			{
				curNode->Next = nullptr;
				Tail = curNode;
			}

			--Size;

			Delete(targetNode, 1);
			return true;
		}

		Node<T>* beforeNode = nullptr;
		for (size_t i = 0; i <= InIndex; ++i)
		{
			if (i == 0) // Init
			{
				beforeNode = Head;
				continue;
			}

			// UpdateNextNode
			Node<T>* curNode = beforeNode->Next;

			// Validate
			if (!curNode)
			{
				std::printf("%-15s : Pointer: %p | Index: %zd\n", "Error", curNode, i);
				return false;
			}

			// Check Index
			if (i < (InIndex))
			{
				beforeNode = curNode;
				curNode = nullptr;
				continue;
			}
			else // Last index (i == InIndex)
			{
				Node<T>* targetNode = curNode->Next;
				if (!targetNode) return false;

				Node<T>* afterNode = targetNode->Next;

				if (afterNode)
				{
					curNode->Next = afterNode;
					afterNode->Prev = curNode;
				}
				else
				{
					curNode->Next = nullptr;
					Tail = curNode;
				}

				--Size;

				Delete(targetNode, 1);

				std::printf("%-15s : Pointer: %p | Index: %zd\n", "Valid", curNode, InIndex);
				return true;
			}
		}
		return false; // Undefined
	}

public:
	static void PrintValue(const T& value)
	{
		std::cout << "Value" << std::setw(13) << " : " << value << "\n";
	}

	static void PrintLinkedListData(LinkedList<T>* InLinkedList)
	{
		std::printf("========================================\n");
		std::printf("[PrintLinkedListData]\n");

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

	static void PrintNodeData(const Node<T>* InNode, size_t InIndex)
	{
		std::printf("----------------------------------------\n");
		std::printf("[%s]\n", "PrintNodeData");

		if (InNode == nullptr)
		{
			std::printf("%-15s : %s\n", "Node", "nullptr");
			std::printf("----------------------------------------\n");

			return;
		}

		PrintValue(InNode->Value);

		std::printf("%-15s : %s\n", "ValueType", typeid(T).name());
		std::printf("%-15s : %zu\n", "NodeIndex", InIndex);
		std::printf("%-15s : %p\n", "NodePointer", (void*)InNode);
		std::printf("%-15s : %p\n", "PrevNode", (void*)InNode->Prev);
		std::printf("%-15s : %p\n", "NextNode", (void*)InNode->Next);
		std::printf("----------------------------------------\n");
	}

	static void PrintAllNodeData(LinkedList<T>* InLinkedList)
	{
		std::printf("========================================\n");
		std::printf("[%s]\n", "PrintAllNodeData");

		if (InLinkedList == nullptr)
		{
			std::printf("%-15s : %s\n", "LinkedList", "nullptr");
			std::printf("========================================\n");
			return;
		}

		if (InLinkedList->Head == nullptr)
		{
			std::printf("%-15s : %p\n", "LinkedList", (const void*)InLinkedList);
			std::printf("%-15s : %s\n", "Head", "nullptr");
			std::printf("========================================\n");
			return;
		}

		const Node<T>* printNode = InLinkedList->Head;
		std::size_t index = 0;

		while (printNode != nullptr)
		{
			PrintNodeData(printNode, index);
			printNode = printNode->Next;
			++index;
		}
		std::printf("========================================\n");
	}
};