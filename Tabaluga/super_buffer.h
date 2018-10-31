#pragma once
#include "stdafx.h"
#include "cyclic_buffer.h"

enum SuperBufferErrorCode
{
	SUPER_BUFFER_SUCCESS = 0,
	SUPER_BUFFER_ERROR_SIZE_SMALLER_THAN_COMMAND_IN_CYCLIC_BUFFER = -1,
	SUPER_BUFFER_ERROR_COMMAND_SMALLER_THAN_EXPECTED = -2,
	SUPER_BUFFER_ERROR_CYCLIC_BUFFER_FULL = -3,
	SUPER_BUFFER_ERROR_CYCLIC_BUFFER_EMPTY = -4
};

class Super_buffer
{
	Cyclic_buffer<char, 100> buffer;
public:

	Super_buffer();
	~Super_buffer();
	SuperBufferErrorCode push(char element);
	SuperBufferErrorCode pop(char *c, int size);

	

};