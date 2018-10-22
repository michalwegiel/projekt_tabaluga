#pragma once
#include "stdafx.h"
template <typename T, int array_size>
class cyclic_buffer
{
public:

	cyclic_buffer();
	~cyclic_buffer();
	int push(T);
	char pop();
	int size();
	bool empty();
	

private:

	T *tab;
	int fill_level;
	int head;
	int tail;

};

template <typename T, int array_size>
cyclic_buffer<T, array_size>::cyclic_buffer()
{
	tab = new T [array_size];
	fill_level = 0;
	head = 0;
	tail = 0;
}

template <typename T, int array_size>
cyclic_buffer<T, array_size>::~cyclic_buffer()
{
	delete [] tab;
}



template <typename T, int array_size>
int cyclic_buffer<T, array_size>::push(T element)
{
	if (fill_level >= 100)
	{
		//cout << endl << "Buffer is full!";
	}

	else
	{
		tab[tail] = element;
		//cout << endl << element << " added in buffer on position: " << tail;
		tail = (tail + 1) % 100;
		fill_level++;
	}
	return 0;
}

//------------------------------------------------------------------------
template <typename T, int array_size>
char cyclic_buffer<T, array_size>::pop()
{
	char result;
	if (fill_level == 0)
	{
		//cout << endl << "Buffer is empty!";
	}
	else
	{
		//cout << char(tab[head]);

		head = (head + 1) % 100;
		fill_level--;
		result = tab[head - 1];
	}
	//cout << endl;


	return result;
}
//------------------------------------------------------------------------
template <typename T, int array_size>
int cyclic_buffer<T, array_size>::size()
{
	//cout << endl << "Number of elements in buffer: " << fill_level;
}

//------------------------------------------------------------------------
template <typename T, int array_size>
bool cyclic_buffer<T, array_size>::empty()
{

	if (fill_level == 0) return true;
	else return false;

}