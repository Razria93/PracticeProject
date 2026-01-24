#pragma once

#include <cstdio>

struct Node
{
public:
	int Value;
	Node* Parent = nullptr;
	Node* Left = nullptr;
	Node* Right = nullptr;

public:
	Node() = default;

	Node(int InValue)
		: Value(InValue)
	{
	}
};

class BinarySearchTree
{
public:
	Node* Root = nullptr;
	size_t Size = 0;

public:
	BinarySearchTree() = default;

	~BinarySearchTree()
	{
		std::printf("\n[Destructor]\n");
		Clear();
	}

public:
	size_t GetSize() const { return Size; }
	bool Empty() const { return Size == 0; }

public:
	bool Clear()
	{
		bool result = Clear(Root);

		Root = nullptr;
		Size = 0;

		return result;
	}

	bool Clear(Node* InNode)
	{
		if (!InNode)
		{
			return false; // this Node is NULL
		}

		std::printf("%-20s : Value: %-11d | Node: %p\n", "TryClear_LNode", InNode->Value, InNode);
		if (Clear(InNode->Left))
		{
			std::printf("------------------------------\n");
			std::printf("%-20s : ParentValue: %-11d | ParentNode: %p\n", "CompleteClear_LNode", InNode->Value, InNode);
			std::printf("%-20s   Parent: %p |[Left : %p]| Right : %p\n", "", InNode->Parent, InNode->Left, InNode->Right);
			std::printf("------------------------------\n");
		}
		else
		{
			std::printf("%-20s\n", "InValid_LeftNode");
		}

		std::printf("%-20s : Value: %-11d | Node: %p\n", "TryClear_RNode", InNode->Value, InNode);
		if (Clear(InNode->Right))
		{
			std::printf("------------------------------\n");
			std::printf("%-20s : OwerValue: %-11d | OwerNode: %p\n", "CompleteClear_RNode", InNode->Value, InNode);
			std::printf("%-20s   Parent: %p | Left : %p |[Right : %p]\n", "", InNode->Parent, InNode->Left, InNode->Right);
			std::printf("------------------------------\n");
		}
		else
		{
			std::printf("%-20s\n", "InValid_RightNode");
		}

		std::printf("------------------------------\n");
		std::printf("%-20s : CurValue: %-11d | CurNode: %p\n", "TryClear_CNode", InNode->Value, InNode);
		Delete(InNode);
		std::printf("%-20s : CurValue: %-11d | CurNode: %p\n", "CompleteClear_CNode", InNode->Value, InNode);
		std::printf("%-20s   Parent: %p | Left : %p | Right : %p\n", "", InNode->Parent, InNode->Left, InNode->Right);
		std::printf("------------------------------\n");

		return true;
	}

public:
	void Delete(Node* InNode)
	{
		std::printf("\n[Delete Before]\n");
		std::printf("%-20s : CurValue: %-11d | CurNode: %p\n", "Delete_BF", InNode->Value, InNode);
		std::printf("%-20s   Parent: %p | Left : %p | Right : %p\n", "", InNode->Parent, InNode->Left, InNode->Right);

		if (Node* parentNode = InNode->Parent)
		{
			std::printf("[Delete ParentCache Before]\n");
			std::printf("%-20s : ParentValue: %-11d | ParentNode: %p\n", "Delete_BF", parentNode->Value, parentNode);
			std::printf("%-20s   Parent: %p | Left : %p | Right : %p\n", "", parentNode->Parent, parentNode->Left, parentNode->Right);

			if (InNode == parentNode->Left)
			{
				parentNode->Left = nullptr;
			}
			else if (InNode == InNode->Parent->Right)
			{
				parentNode->Right = nullptr;
			}
			std::printf("[Delete ParentCache After]\n");
			std::printf("%-20s : ParentValue: %-11d | ParentNode: %p\n", "Delete_AF", parentNode->Value, parentNode);
			std::printf("%-20s   Parent: %p | Left : %p | Right : %p\n", "", parentNode->Parent, parentNode->Left, parentNode->Right);
			
		}
		else // bIsRoot?
		{
			if (InNode == Root)
				Root = nullptr;

			std::printf("%-20s : %s\n", "NOTE", "Root Delete");
		}

		InNode->Parent = nullptr;
		InNode->Left = nullptr;
		InNode->Right = nullptr;
		InNode->Value = 0;

		std::printf("[Delete After]\n");
		std::printf("%-20s : CurValue: %-11d | CurNode: %p\n", "Delete_AF", InNode->Value, InNode);
		std::printf("%-20s   Parent: %p | Left : %p | Right : %p\n", "", InNode->Parent, InNode->Left, InNode->Right);

		delete InNode;
	}

public:
	bool Insert(int InValue)
	{
		Node* node = new Node;

		node->Value = InValue;
		node->Parent = nullptr;
		node->Left = nullptr;
		node->Right = nullptr;

		if (!Root)
		{
			if (Size != 0)
			{
				std::printf("%-20s : %s\n", "Error", "InValid Root. but Size != 0.");
				return false;
			}

			Root = node;
			++Size;

			std::printf("%-20s : Parent: %p | Node: %p | NodeValue: %-5d | Size: %zd\n", "Insert_Root", node->Parent, node, node->Value, Size);
			return true;
		}

		// Valid Root

		Node* targetNode = Root;
		while (targetNode != nullptr)
		{
			if (node->Value < targetNode->Value)
			{
				if (!targetNode->Left)
				{
					targetNode->Left = node;
					node->Parent = targetNode;
					++Size;

					std::printf("%-20s : Parent: %p | Node: %p | NodeValue: %-5d | Size: %zd\n", "Insert_Left", node->Parent, node, node->Value, Size);
					return true;
				}
				else // Valid targetNode->Left
				{
					targetNode = targetNode->Left;
					continue;
				}
			}
			else if (node->Value > targetNode->Value)
			{
				if (!targetNode->Right)
				{
					targetNode->Right = node;
					node->Parent = targetNode;
					++Size;

					std::printf("%-20s : Parent: %p | Node: %p | NodeValue: %-5d | Size: %zd\n", "Insert_Right", node->Parent, node, node->Value, Size);
					return true;
				}
				else // Valid targetNode->Left
				{
					targetNode = targetNode->Right;
					continue;
				}
			}
			else // node->Value == targetNode->Value
			{
				std::printf("%-20s : %s\n", "Error", "InValue be Duplicated.");
				return false;
			}
		} // while

		std::printf("%-20s : %s\n", "Error", "Undefined.");
		return false;
	} // Insert

public:
	Node* Find(int InValue)
	{
		if (!Root)
		{
			return nullptr;
		}

		return Find(InValue, Root);
	}

	Node* Find(int InValue, Node* InNode)
	{
		if (!InNode)
		{
			std::printf("%-20s : %s\n", "Error", "InValid InNode.");
			return nullptr;
		}

		if (InValue == InNode->Value) return InNode;
		if (InValue < InNode->Value) return Find(InValue, InNode->Left);
		if (InValue > InNode->Value) return Find(InValue, InNode->Right);

		std::printf("Undefined");
		return nullptr;
	} // Find

public:
	Node* FindLargest()
	{
		return FindLargest(Root);
	}

	Node* FindLargest(Node* InRootNode)
	{
		if (!InRootNode) return nullptr;

		Node* largest = FindLargest(InRootNode->Right);

		return largest ? largest : InRootNode;
	}

public:
	Node* FindSmallest()
	{
		return FindSmallest(Root);
	}

	Node* FindSmallest(Node* InRootNode)
	{
		if (!InRootNode) return nullptr;

		Node* smallest = FindSmallest(InRootNode->Left);

		return smallest ? smallest : InRootNode;
	}

public:
	bool Erase(int InValue)
	{
		return Erase(InValue, Root);
	}

	bool Erase(int InValue, Node* InNode)
	{
		if (!InNode)
		{
			std::printf("%-20s : %s\n", "Error", "InValid InNode.");
			return false;
		}

		if (InValue == InNode->Value)
		{
			Node* eraseNode = InNode;
			Node* switchNode = nullptr;

			Node* largest = FindLargest(InNode->Left);
			Node* smallest = FindSmallest(InNode->Right);

			if (!largest && !smallest) return false;
			
			if (!largest && smallest)
				switchNode = smallest;
			
			if (largest && !smallest)
				switchNode = largest;

			if (largest && smallest)
			{
				std::printf("%-20s : InNodeValue: %-11d | LargestValue Of LeftNode: %-11d | SmallestValue Of RghtNode: %-11d\n", "ValueCompation", InNode->Value, largest->Value, smallest->Value);

				if ((largest->Value - InNode->Value) >= (InNode->Value - smallest->Value))
				{
					switchNode = smallest;
				}
				else
				{
					switchNode = largest;
				}
			}

			Node* oldParentNode = switchNode->Parent ? switchNode->Parent : nullptr;
			Node* newParentNode = eraseNode->Parent ? eraseNode->Parent : nullptr;

			std::printf("\n[Erase Before]\n");
			if (oldParentNode)
			{
				std::printf("%-20s : ParentValue: %-11d | ParentNode: %p\n", "OldParentNode", oldParentNode->Value, oldParentNode);
				std::printf("%-20s   Parent: %p | Left : %p |[Right : %p]\n", "", oldParentNode->Parent, oldParentNode->Left, oldParentNode->Right);
			}
			else
			{
				std::printf("OldParentNode InValid");
			}

			if (newParentNode)
			{
				std::printf("%-20s : ParentValue: %-11d | ParentNode: %p\n", "NewParentNode", newParentNode->Value, newParentNode);
				std::printf("%-20s   Parent: %p |[Left : %p]| Right : %p\n", "", newParentNode->Parent, newParentNode->Left, newParentNode->Right);
			}
			else
			{
				std::printf("NewParentNode InValid");
			}


			std::printf("%-20s : SwitchValue: %-11d | SwitchNode: %p\n", "SwicthNode", switchNode->Value, switchNode);
			std::printf("%-20s  [Parent: %p]| Left : %p | Right : %p\n", "", switchNode->Parent, switchNode->Left, switchNode->Right);
			std::printf("%-20s : %zd\n", "Size", Size);

			bool bRight = false;
			bool bLeft = false;

			if (newParentNode)
			{
				if (newParentNode->Right == eraseNode)
					bRight = true;
				else if (newParentNode->Left == eraseNode)
					bLeft = true;
			}

			Delete(eraseNode);

			if (oldParentNode)
			{
				if (oldParentNode->Right == switchNode)
					oldParentNode->Right = nullptr;
				else if (oldParentNode->Left == switchNode)
					oldParentNode->Left = nullptr;
			}

			if (newParentNode)
			{
				if (bRight)
				{
					newParentNode->Right = switchNode;
					switchNode->Parent = newParentNode;
				}
				else if (bLeft)
				{
					newParentNode->Left = switchNode;
					switchNode->Parent = newParentNode;
				}
			}
			else
			{
				switchNode->Parent = nullptr;
			}
			
			--Size;

			std::printf("\n[Erase After]\n");
			if (oldParentNode)
			{
				std::printf("%-20s : ParentValue: %-11d | ParentNode: %p\n", "OldParentNode", oldParentNode->Value, oldParentNode);
				std::printf("%-20s   Parent: %p | Left : %p |[Right : %p]\n", "", oldParentNode->Parent, oldParentNode->Left, oldParentNode->Right);
			}
			else
			{
				std::printf("OldParentNode InValid");
			}

			if (newParentNode)
			{
				std::printf("%-20s : ParentValue: %-11d | ParentNode: %p\n", "NewParentNode", newParentNode->Value, newParentNode);
				std::printf("%-20s   Parent: %p |[Left : %p]| Right : %p\n", "", newParentNode->Parent, newParentNode->Left, newParentNode->Right);
			}
			else
			{
				std::printf("NewParentNode InValid");
			}

			std::printf("%-20s : SwitchValue: %-11d | SwitchNode: %p\n", "SwicthNode", switchNode->Value, switchNode);
			std::printf("%-20s  [Parent: %p]| Left : %p | Right : %p\n", "", switchNode->Parent, switchNode->Left, switchNode->Right);
			std::printf("%-20s : %zd\n", "Size", Size);
			

			return true;
		}

		if (InValue < InNode->Value) return Erase(InValue, InNode->Left);
		if (InValue > InNode->Value) return Erase(InValue, InNode->Right);

		std::printf("Undefined");
		return false;
	} // Erase
};