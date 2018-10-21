#include "stdafx.h"
#include "CppUnitTest.h"
#include "cyclic_buffer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CyclicBuffer
{
	TEST_CLASS(BasicFunctionality)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			cyclic_buffer buffer;

			buffer.push('a');
			
			Assert::AreEqual('a', buffer.pop());	
		}


	};
}