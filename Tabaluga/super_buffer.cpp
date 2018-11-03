#include "stdafx.h"
#include "super_buffer.h"
#include "cyclic_buffer.h"

Super_buffer::Super_buffer():buffer() //lista inicjalizacyjna - wywolanie konstruktora dla obiektu buffer
{
	IsBufferFull = false;
}
//------------------------------------------------------------------------
Super_buffer::~Super_buffer()
{

}
//------------------------------------------------------------------------
SuperBufferErrorCode Super_buffer::push(char element)
{	
	SuperBufferErrorCode result;
	if (IsBufferFull == false || element == '\0')
	{
		if (buffer.push(element) == BUFFER_SUCCESS)
		{
			IsBufferFull = false;
			result = SUPER_BUFFER_SUCCESS;
		}
		else
		{
			IsBufferFull = true;
			int endcondition = 0;
			char trash;
			char *trash_indicator;
			trash_indicator = &trash;
			do {
				if ((buffer.popFromtop(trash_indicator)) == BUFFER_EMPTY)
					endcondition = 1;
			} while (*trash_indicator != '\0' &&  endcondition == 0);
			buffer.push('\0');  

			result = SUPER_BUFFER_ERROR_CYCLIC_BUFFER_FULL;
		}
	} else result = SUPER_BUFFER_ERROR_CYCLIC_BUFFER_FULL;
	
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
		else if (*command == '\0' && i < size)
			result = SUPER_BUFFER_ERROR_COMMAND_SMALLER_THAN_EXPECTED;
		else if (*command != '\0' && i == size)
		{
			do {
				buffer.pop(command);
			} while (*command != '\0' && buffer.empty() != true);
			result = SUPER_BUFFER_ERROR_SIZE_SMALLER_THAN_COMMAND_IN_CYCLIC_BUFFER;
		}
		else if (result != SUPER_BUFFER_ERROR_CYCLIC_BUFFER_EMPTY)
			result = SUPER_BUFFER_SUCCESS;
	}
	

	return result;
}
//------------------------------------------------------------------------

