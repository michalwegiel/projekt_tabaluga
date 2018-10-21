/*

#include "stdafx.h"
#include "cyclic_buffer.h"

template <typename T1, typename T2>
T2 cyclic_buffer<T1,T2>::push(T1 element)
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
template <typename T1, typename T2>
char cyclic_buffer<T1, T2>::pop()
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
template <typename T1, typename T2>
int cyclic_buffer<T1, T2>::size()
{
	//cout << endl << "Number of elements in buffer: " << fill_level;
}

//------------------------------------------------------------------------
template <typename T1, typename T2>
bool cyclic_buffer<T1, T2>::empty()
{

	if (fill_level == 0) return true;
	else return false;

}


*/