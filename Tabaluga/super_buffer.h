#pragma once
#include "stdafx.h"
#include "cyclic_buffer.h"

enum SuperBufferErrorCode
{
	SUPER_BUFFER_SUCCESS = 0,
	SUPER_BUFFER_ERROR = -1
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