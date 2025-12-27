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
	bool empty() const { return Size == 0; }

public:
	void push_back(T Indata)
	{
		size_t newCapacity = (Capacity == 0) ? 1 : Capacity * 2;
		if (newCapacity < Capacity) return; // prevent overflow

		if (Capacity == 0)
		{
			std::printf("[push_back/init]\n");

			Data = new T[newCapacity];

			Data[0] = Indata;
			++Size;
		}
		else
		{
			if (Size >= Capacity)
			{
				std::printf("[push_back/Add Capacity] %zu -> %zu\n", Capacity, newCapacity);

				T* tempData = new T[newCapacity];

				for (size_t i = 0; i < Size; i++)
				{
					tempData[i] = Data[i];
				}

				tempData[Size] = Indata;
				++Size;

				delete[] Data;

				Data = tempData;
			}
			else // Size < Capcacity
			{
				Data[Size] = Indata;
				++Size;
			}
		}

		Capacity = newCapacity;

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
		std::printf("===\n");
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
		std::printf("===\n");
	}
};