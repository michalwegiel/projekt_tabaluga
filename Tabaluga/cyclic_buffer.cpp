#include "stdafx.h"
#include "cyclic_buffer.h"



void cyclic_buffer::push(char element)
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
}

//------------------------------------------------------------------------

void cyclic_buffer::get_command(int *w)
{
	if (fill_level == 0)
	{
		//cout << endl << "Buffer is empty!";
	}
	else
	{
			//cout << char(tab[head]);
			*w = tab[head];
			head = (head + 1) % 100;
			fill_level--;
	}
		//cout << endl;
	


}
//------------------------------------------------------------------------

void cyclic_buffer::size()
{
	//cout << endl << "Number of elements in buffer: " << fill_level;
}

//------------------------------------------------------------------------

bool cyclic_buffer::empty()
{

	if (fill_level == 0) return true;
	else return false;

}


