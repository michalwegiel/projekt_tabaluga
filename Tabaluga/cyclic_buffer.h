#pragma once
#include "stdafx.h"

enum CyclicBufferErrorCode
{
	SUCCESS = 0,
	BUFFER_EMPTY = -1,
	BUFFER_FULL = -2,
	ERROR = -9
};

template <typename T, int array_size>
class cyclic_buffer
{
public:

	cyclic_buffer();
	~cyclic_buffer();
	CyclicBufferErrorCode push(T element);
	CyclicBufferErrorCode pop(T *c);
	int size();
	bool empty();


private:

	T *tab;
	int fill_level;
	int head;
	int tail;

};
//------------------------------------------------------------------------
template <typename T, int array_size>
cyclic_buffer<T, array_size>::cyclic_buffer()
{
	tab = new T [array_size];
	fill_level = 0;
	head = 0;
	tail = 0;
}
//------------------------------------------------------------------------
template <typename T, int array_size>
cyclic_buffer<T, array_size>::~cyclic_buffer()
{
	delete [] tab;
}


//------------------------------------------------------------------------
template <typename T, int array_size>
CyclicBufferErrorCode cyclic_buffer<T, array_size>::push(T element)
{	
	CyclicBufferErrorCode result;
	if (fill_level >= array_size) //zabezpieczenie przed przepelnieniem
	{
		result = BUFFER_FULL;
	}

	else if (fill_level < 0)
	{
		result = ERROR;
	}
	else
	{
		tab[tail] = element;
		tail = (tail + 1) % array_size;
		fill_level++;
		result = SUCCESS;
	}
	return result;
}

//------------------------------------------------------------------------
template <typename T, int array_size>
CyclicBufferErrorCode cyclic_buffer<T, array_size>::pop(T *c)
{
	CyclicBufferErrorCode result;
	if (fill_level <= 0) //zabezpieczenie przed wyciaganiem z pustego bufora
	{
		result = BUFFER_EMPTY;
	}

	else
	{
		*(c++) = tab[head];
		head = (head + 1) % array_size;
		fill_level--;
		result = SUCCESS;
	}
	
	return result;
}
//------------------------------------------------------------------------
template <typename T, int array_size>
int cyclic_buffer<T, array_size>::size()
{
	return fill_level;
}

//------------------------------------------------------------------------
template <typename T, int array_size>
bool cyclic_buffer<T, array_size>::empty()
{

	if (fill_level == 0) return true;
	else return false;

}
