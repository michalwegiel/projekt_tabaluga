#include "stdafx.h"
#include "CppUnitTest.h"
#include "cyclic_buffer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CyclicBuffer
{
	TEST_CLASS(BasicFunctionality)
	{
	public:

		TEST_METHOD(pushAndPop)
		{
			cyclic_buffer<char, 5> buffer;
			buffer.push('a');
			Assert::AreEqual('a', buffer.pop());	
		}


		TEST_METHOD(pushAndPop_1)
		{
			cyclic_buffer<char, 5> buffer;
			buffer.push('a');
			buffer.push('b');

			Assert::AreEqual('a', buffer.pop());
		}

		TEST_METHOD(pushAndPop_2)
		{
			cyclic_buffer<char, 5> buffer;
			buffer.push('a');
			buffer.push('b');

			buffer.pop();
			Assert::AreEqual('b', buffer.pop());
		}
		
		TEST_METHOD(pushAndpop_3)
		{
			cyclic_buffer<char, 10> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.pop();
			buffer.pop();

			Assert::AreEqual('c', buffer.pop());
		} 


	};
}