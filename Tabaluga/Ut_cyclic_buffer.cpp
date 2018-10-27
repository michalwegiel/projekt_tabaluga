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
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			cyclic_buffer<char, 5> buffer;
			buffer.push('a');
			
			Assert::AreEqual(static_cast<int> (SUCCESS), static_cast<int> (buffer.pop(wsk)));
		}

		TEST_METHOD(pushAndPop1)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			cyclic_buffer<char, 5> buffer;
			buffer.push('a');
			buffer.pop(wsk);
			Assert::AreEqual('a', tab[0]);
		}


		TEST_METHOD(pushAndPop_1)
		{	
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			cyclic_buffer<char, 5> buffer;
			buffer.push('a');
			buffer.push('b');

			Assert::AreEqual(static_cast<int> (SUCCESS), static_cast<int> (buffer.pop(wsk)));
		}

		TEST_METHOD(pushAndPop_2)
		{	
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			cyclic_buffer<char, 5> buffer;
			buffer.push('a');
			buffer.push('b');

			
			Assert::AreEqual(static_cast<int> (SUCCESS), static_cast<int> (buffer.pop(wsk)));
		}
		
		TEST_METHOD(pushAndpop_3)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			cyclic_buffer<char, 10> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.pop(tab);
			buffer.pop(tab);

			Assert::AreEqual(static_cast<int> (SUCCESS), static_cast<int> (buffer.pop(wsk)));
		}

		TEST_METHOD(pushAndfillbuffer)
		{
			cyclic_buffer<char, 5> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.push('d');
			buffer.push('e');
			


			Assert::AreEqual(static_cast<int> (BUFFER_FULL), static_cast<int> (buffer.push('f')));
		}

		
		TEST_METHOD(pushpositive)
		{
			cyclic_buffer<char, 5> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.push('d');
			



			Assert::AreEqual(static_cast<int> (SUCCESS),static_cast<int> (buffer.push('e')));
		}
		
		TEST_METHOD(emptybuffer)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			cyclic_buffer<char, 5> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.pop(tab);
			buffer.pop(tab);
			buffer.pop(tab);



			Assert::AreEqual(static_cast<int> (BUFFER_EMPTY), static_cast<int> (buffer.pop(wsk)));
		}


	};
}