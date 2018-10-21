#pragma once
class cyclic_buffer
{
public:

	char tab[100];
	int fill_level = 0;
	int head = 0;
	int tail = 0;
	


	void push(char);
	char pop();
	void size();
	bool empty();


};