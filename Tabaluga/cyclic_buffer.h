#pragma once
#include "stdafx.h"

enum CyclicBufferErrorCode
{
	BUFFER_SUCCESS = 0,
	BUFFER_EMPTY = -1,
	BUFFER_FULL = -2,
};

template <typename T, int array_size>
class Cyclic_buffer
{
public:

	Cyclic_buffer();
	~Cyclic_buffer();
	CyclicBufferErrorCode push(T element);
	CyclicBufferErrorCode pop(T *c);
	unsigned int size();
	bool empty();


private:

	T *tab;
	unsigned int fill_level;
	int head;
	int tail;

};
//------------------------------------------------------------------------
template <typename T, int array_size>
Cyclic_buffer<T, array_size>::Cyclic_buffer()
{
	tab = new T [array_size];
	fill_level = 0;
	head = 0;
	tail = 0;
}
//------------------------------------------------------------------------
template <typename T, int array_size>
Cyclic_buffer<T, array_size>::~Cyclic_buffer()
{
	delete [] tab;
}


//------------------------------------------------------------------------
template <typename T, int array_size>
CyclicBufferErrorCode Cyclic_buffer<T, array_size>::push(T element)
{	
	CyclicBufferErrorCode result;
	if (fill_level >= array_size) //zabezpieczenie przed przepelnieniem
	{
		result = BUFFER_FULL;
	} else

	{
		tab[tail] = element;
		tail = (tail + 1) % array_size;
		fill_level++;
		result = BUFFER_SUCCESS;
	}
	return result;
}

//------------------------------------------------------------------------
template <typename T, int array_size>
CyclicBufferErrorCode Cyclic_buffer<T, array_size>::pop(T *c)
{
	CyclicBufferErrorCode result;
	if (fill_level <= 0) //zabezpieczenie przed wyciaganiem z pustego bufora
	{
		result = BUFFER_EMPTY;
	}

	else
	{
		*c = tab[head];
		head = (head + 1) % array_size;
		fill_level--;
		result = BUFFER_SUCCESS;
	}
	
	return result;
}
//------------------------------------------------------------------------
template <typename T, int array_size>
unsigned int Cyclic_buffer<T, array_size>::size()
{
	return fill_level;
}

//------------------------------------------------------------------------
template <typename T, int array_size>
bool Cyclic_buffer<T, array_size>::empty()
{

	if (fill_level == 0) return true;
	else return false;

}
