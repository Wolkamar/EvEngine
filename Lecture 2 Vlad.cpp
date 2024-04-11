/*#include <iostream>

template <class T>
class IntArray
{
	size_t _size = 0;
	T* _array = nullptr;

public:

	IntArray(size_t size)
		:_size(size)
		, _array(new T[size])
	{
		std::cout << "Constructor\n";
	}

	~IntArray()
	{
		std::cout << "Destructor\n";
		delete[]_array;
	}

	void print()
	{
		for (size_t i = 0; i < _size; i++)
		{
			std::cout << i << ":" << _array[i] << "\n";
		}
	}

	T& operator[] (size_t index)
	{
		return _array[index];
	};
};

int main(int argc, char* argv[])
{
	IntArray<int> a(10);
	a[5] = 16;
	a.print();


	return 0;
}*/