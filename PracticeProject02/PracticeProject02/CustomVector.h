#pragma once

template<typename T>
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

public:
	void PrintData()
	{
		std::printf("===\n");
		if (Data)
		{
			std::printf("Data			: %p\n", (void*)Data);
		}
		else
			std::printf("Data			: nullptr\n");

		{
			std::printf("Type			: %s\n", typeid(T).name());
			std::printf("ElementSize	: %zu\n", sizeof(T));
			std::printf("Capacity		: %zu\n", Capacity);
			std::printf("Size			: %zu\n", Size);
			
		}
		std::printf("===\n");
	}
};