#include "stdafx.h"
#include "CppUnitTest.h"
#include "super_buffer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tabaluga
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			buffer b1;
			b1.push('a');
			b1.push('b');
		

			Assert::AreEqual('a', b1.tab[0]);
		}

		TEST_METHOD(TestMethod2)
		{
			buffer b1;
			b1.push('a');
			b1.push('b');


			Assert::AreEqual('a', b1.tab[1]);
		}

	};
}