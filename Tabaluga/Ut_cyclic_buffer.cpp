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

		TEST_METHOD(pushAndfillbuffer)
		{
			cyclic_buffer<char, 5> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.push('d');
			buffer.push('e');
			


			Assert::AreEqual(-1, buffer.push('f'));
		}

		TEST_METHOD(pushpositive)
		{
			cyclic_buffer<char, 5> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.push('d');
			



			Assert::AreEqual(0, buffer.push('e'));
		}

		TEST_METHOD(emptybuffer)
		{
			cyclic_buffer<char, 5> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.pop();
			buffer.pop();
			buffer.pop();



			Assert::AreEqual('!', buffer.pop());
		}


	};
}