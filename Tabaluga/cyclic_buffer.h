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
int cyclic_buffer<T, array_size>::push(T element)
{	
	int result;
	if (fill_level >= array_size) //zabezpieczenie przed przepelnieniem
	{
		result = -1;
	}

	else
	{
		tab[tail] = element;
		tail = (tail + 1) % array_size;
		fill_level++;
		result = 0;
	}
	return result;
}

//------------------------------------------------------------------------
template <typename T, int array_size>
char cyclic_buffer<T, array_size>::pop()
{
	char result;
	if (fill_level <= 0) //zabezpieczenie przed wyciaganiem z pustego bufora
	{
		result = '!';
	}
	else
	{
		
		result = tab[head];
		head = (head + 1) % array_size;
		fill_level--;
		
	}
	


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