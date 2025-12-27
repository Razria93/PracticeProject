#pragma once

template<typename T> // Determined at compile time
class CustomVector
{
private:
	T* Data;
	size_t Capacity;
	size_t Size;

public:
	CustomVector()
	{
		std::printf("[Constructor]\n");

		Data = nullptr;
		Capacity = 0;
		Size = 0;
	}

	~CustomVector()
	{
		delete[] Data;
		Data = nullptr;
	}

	CustomVector(const CustomVector&) = delete;				// copy constructor				[deprecated]
	CustomVector& operator=(const CustomVector&) = delete;	// copy assignment operator		[deprecated]

public:
	size_t capacity() const { return Capacity; }
	size_t size() const { return Size; }

public:
	T* begin() { return Data; }
	T* end() { return Data + Size; }
	const T* begin() const { return Data; }
	const T* end()   const { return Data + Size; }

public:
	bool empty() const { return Size == 0; }

public:
	void push_back(T InData)
	{
		std::printf("[push_back]\n");

		// -----------------------------------------------------------------------------------------------
		// [TODO] Refactor
		// 1. 'new T[n]' allocates memory AND calls default constructors for all 'n' elements.
		// 2. 'malloc' (or allocator) only reserves raw memory without any initialization.
		// 3. Vector uses 'placement new' to construct objects only when they are actually needed.

		if (Size >= Capacity)
		{
			size_t newCapacity = (Capacity == 0) ? 1 : Capacity * 2;
			if (newCapacity < Capacity) return; // overflow guard

			T* tempData = new T[newCapacity];	
			for (size_t i = 0; i < Size; ++i)
				tempData[i] = Data[i];

			delete[] Data;
			Data = tempData;
			Capacity = newCapacity;
		}
		// -----------------------------------------------------------------------------------------------

		if (Size < Capacity)
		{
			Data[Size] = InData;
			++Size;
		}

		PrintData();
	}

	void insert(size_t InIndex, const T& InData)
	{
		std::printf("[insert] ElementNum: %zu\n", InIndex);

		// Check Area [0, Size]
		if (InIndex > Size) return;

		// Push_Back
		if (InIndex == Size)
		{
			push_back(InData);
			return;
		}

		// Insert
		if (Size == Capacity)
		{
			size_t newCapacity = (Capacity == 0) ? 1 : Capacity * 2;
			if (newCapacity < Capacity) return; // overflow guard

			T* tempData = new T[newCapacity];

			// Copy Element_Forward
			for (size_t i = 0; i < InIndex; i++)
			{
				tempData[i] = Data[i];
			}

			// Insert Element_InData
			tempData[InIndex] = InData;

			// Copy Element_Backward
			for (size_t i = InIndex; i < Size; i++)
			{
				tempData[i + 1] = Data[i];
			}

			delete[] Data;

			Data = tempData;
			Capacity = newCapacity;
			++Size;
		}
		else // (Size < Capacity)
		{
			// Move Backward-Elements
			for (size_t i = Size; i > InIndex; i--)
			{
				Data[i] = Data[i - 1];
			}

			Data[InIndex] = InData;
			++Size;
		}

		PrintData();
	}

	void erase(size_t InIndex)
	{
		std::printf("[erase] ElementNum: %zu\n", InIndex);

		// Check Area [0, Size]
		if (InIndex >= Size) return;

		// Push_Back
		if (InIndex == Size - 1)
		{
			pop_back();
			return;
		}

		// Copy Element_Forward
		for (size_t i = 0; i < InIndex; i++)
		{
			Data[i] = Data[i];
		}

		// Copy Element_Backward
		for (size_t i = InIndex; i < Size - 1; i++)
		{
			Data[InIndex] = Data[InIndex + 1];
		}

		--Size;

		PrintData();
	}

	void pop_back()
	{
		std::printf("[pop_back]\n");

		if (Size == 0) return;

		--Size;

		PrintData();
	}

	void clear()
	{
		std::printf("[clear]\n");

		if (Size == 0) return;

		Size = 0;

		PrintData();
	}

public:
	void PrintData() const
	{
		std::printf("==============================\n");

		if (Data)
		{
			std::printf("%-15s : %p\n", "Data", (void*)Data);
		}
		else
			std::printf("%-15s : %p\n", "Data", nullptr);

		{
			std::printf("%-15s : %s\n", "Type", typeid(T).name());
			std::printf("%-15s : %zu\n", "ElementSize", sizeof(T));
			std::printf("%-15s : %zu\n", "Capacity", Capacity);
			std::printf("%-15s : %zu\n", "Size", Size);
		}

		std::printf("==============================\n");
	}

	void PrintElements() const
	{
		std::printf("[PrintElements]\n");

		if (Size <= 0) return;

		std::printf("==============================\n");

		for (size_t i = 0; i < Size; i++)
		{
			std::cout << "Element_" << i << ": " << Data[i] << std::endl;
		}

		std::printf("==============================\n");
	}

};