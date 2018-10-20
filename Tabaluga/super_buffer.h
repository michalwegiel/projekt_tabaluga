#pragma once
class buffer
{
public:

	char tab[100];
	int fill_level = 0;
	int head = 0;
	int tail = 0;


	void push(char);
	void get_command();
	void size();
	bool empty();
	

};