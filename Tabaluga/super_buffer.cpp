#include "stdafx.h"
#include "super_buffer.h"
#include "cyclic_buffer.h"

Super_buffer::Super_buffer():buffer() //lista inicjalizacyjna - wywolanie konstruktora dla obiektu buffer
{

}
//------------------------------------------------------------------------
Super_buffer::~Super_buffer()
{

}
//------------------------------------------------------------------------
SuperBufferErrorCode Super_buffer::push(char element)
{	
	SuperBufferErrorCode result;
	if (buffer.push(element)==BUFFER_SUCCESS)
	result = SUPER_BUFFER_SUCCESS;
	else result = SUPER_BUFFER_ERROR;

	return result;
}
//------------------------------------------------------------------------
SuperBufferErrorCode Super_buffer::pop(char *command, int size)
{	
	int i = 1;
	buffer.pop(command);
	while (*command != '\0' && i < size)
	{	
		buffer.pop(++command);
		i++;
	}
	
	return SUPER_BUFFER_SUCCESS;
}
//------------------------------------------------------------------------



