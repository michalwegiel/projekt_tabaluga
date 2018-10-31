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
	else result = SUPER_BUFFER_ERROR_CYCLIC_BUFFER_FULL;

	return result;
}
//------------------------------------------------------------------------
SuperBufferErrorCode Super_buffer::pop(char *command, int size)
{	
	SuperBufferErrorCode result = SUPER_BUFFER_SUCCESS;
	int i = 1;
	buffer.pop(command);
	if (*command == '\0')
	{
		do {
			if (buffer.pop(command) == BUFFER_EMPTY)
				result = SUPER_BUFFER_ERROR_CYCLIC_BUFFER_EMPTY;
		} while (*command == '\0' && result != SUPER_BUFFER_ERROR_CYCLIC_BUFFER_EMPTY);
	}
	while (*command != '\0' && i < size && result != SUPER_BUFFER_ERROR_CYCLIC_BUFFER_EMPTY)
	{	
		i++;
		if (buffer.pop(++command) == BUFFER_EMPTY)
			result = SUPER_BUFFER_ERROR_CYCLIC_BUFFER_EMPTY;
		if (*command == '\0' && i < size)
			result = SUPER_BUFFER_ERROR_COMMAND_SMALLER_THAN_EXPECTED;
		else if (*command != '\0' && i == size)
		{
			do {
				buffer.pop(command);
			} while (*command != '\0');
			result = SUPER_BUFFER_ERROR_SIZE_SMALLER_THAN_COMMAND_IN_CYCLIC_BUFFER;
		}
		else if (result != SUPER_BUFFER_ERROR_CYCLIC_BUFFER_EMPTY)
			result = SUPER_BUFFER_SUCCESS;
	}
	
	return result;
}
//------------------------------------------------------------------------



