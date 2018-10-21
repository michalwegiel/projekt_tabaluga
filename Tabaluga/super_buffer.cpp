#include "stdafx.h"
#include "super_buffer.h"



void buffer::push(char element)
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

void buffer::get_command()
{
	if (fill_level == 0)
	{
		//cout << endl << "Buffer is empty!";
	}
	else
	{
		//cout << endl;
		while (tab[head] != 'Q' && buffer::empty() != true)
		{
			//cout << char(tab[head]);
			head = (head + 1) % 100;
			fill_level--;
		}
		if (tab[head] == 'Q')
		{
			head = (head + 1) % 100;
			fill_level--;
		}
		//cout << endl;
	}


}
//------------------------------------------------------------------------

void buffer::size()
{
	//cout << endl << "Number of elements in buffer: " << fill_level;
}

//------------------------------------------------------------------------

bool buffer::empty()
{

	if (fill_level == 0) return true;
	else return false;

}


