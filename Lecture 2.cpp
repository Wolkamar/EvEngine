#include <iostream>
#include <memory>

template <class T>
class DynamicArray
{
	size_t _size = 0;
	T* _array = nullptr;

public:
	DynamicArray(size_t size)
		: _size(size)
		, _array(new T[size])
	{
		std::cout << "Array constructor\n";

		for (size_t i = 0; i < size; ++i)
		{
			_array[i] = 0;
		}
	}

	~DynamicArray()
	{
		std::cout << "Array destructor\n";
		delete[] _array;
	}

	void set(size_t index, T value)
	{
		_array[index] = value;
	}

	T get(size_t index)
	{
		return _array[index];
	}

	void print(size_t index)
	{
		std::cout << index << " : " << get(index) << "\n";
	}

	T& operator [](size_t index)
	{
		return _array[index];
	}

	size_t getSize()
	{
		return _size;
	}
};

void print(std::shared_ptr<DynamicArray<int>> arr)
{
	size_t size = arr->getSize();
	for (size_t i = 0; i < size; ++i)
	{
		arr->print(i);
	}
}

int main(int argc, char* argv[])
{
	auto arr = std::make_shared<DynamicArray<int>>(10);
	print(arr);

	return 0;
}