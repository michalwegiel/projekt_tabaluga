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
			Cyclic_buffer<char, 5> buffer;
			buffer.push('a');
			
			Assert::AreEqual(static_cast<int> (BUFFER_SUCCESS), static_cast<int> (buffer.pop(wsk)));
		}

		TEST_METHOD(pushAndPop1)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Cyclic_buffer<char, 5> buffer;
			buffer.push('a');
			buffer.pop(wsk);
			Assert::AreEqual('a', tab[0]);
		}


		TEST_METHOD(pushAndPop_1)
		{	
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Cyclic_buffer<char, 5> buffer;
			buffer.push('a');
			buffer.push('b');

			Assert::AreEqual(static_cast<int> (BUFFER_SUCCESS), static_cast<int> (buffer.pop(wsk)));
		}

		TEST_METHOD(pushAndPop_2)
		{	
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Cyclic_buffer<char, 5> buffer;
			buffer.push('a');
			buffer.push('b');

			
			Assert::AreEqual(static_cast<int> (BUFFER_SUCCESS), static_cast<int> (buffer.pop(wsk)));
		}
		
		TEST_METHOD(pushAndpop_3)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Cyclic_buffer<char, 10> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.pop(wsk);
			wsk++;
			buffer.pop(wsk);
			wsk++;

			Assert::AreEqual(static_cast<int> (BUFFER_SUCCESS), static_cast<int> (buffer.pop(wsk)));
		}

		TEST_METHOD(pushAndfillbuffer)
		{
			Cyclic_buffer<char, 5> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.push('d');
			buffer.push('e');
			


			Assert::AreEqual(static_cast<int> (BUFFER_FULL), static_cast<int> (buffer.push('f')));
		}

		
		TEST_METHOD(pushpositive)
		{
			Cyclic_buffer<char, 5> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.push('d');
			



			Assert::AreEqual(static_cast<int> (BUFFER_SUCCESS),static_cast<int> (buffer.push('e')));
		}
		
		TEST_METHOD(emptybuffer)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Cyclic_buffer<char, 5> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.pop(wsk);
			wsk++;
			buffer.pop(wsk);
			wsk++;
			buffer.pop(wsk);
			wsk++;



			Assert::AreEqual(static_cast<int> (BUFFER_EMPTY), static_cast<int> (buffer.pop(wsk)));
		}

		TEST_METHOD(pushAndpop_31)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Cyclic_buffer<char, 10> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.pop(wsk);
			wsk++;
			buffer.pop(wsk);
			wsk++;

			Assert::AreEqual('b', tab[1]);
		}
		TEST_METHOD(pushAndpop_32)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Cyclic_buffer<char, 10> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.pop(wsk);
			wsk++;
			buffer.pop(wsk);
			wsk++;
			buffer.pop(wsk);
			wsk++;

			Assert::AreEqual('c', tab[2]);
		}

		TEST_METHOD(pushAndpop_33)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Cyclic_buffer<char, 10> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.pop(wsk);
			wsk++;
			buffer.pop(wsk);
			wsk++;
			buffer.pop(wsk);
			wsk++;

			Assert::AreEqual('b', tab[1]);
		}

		TEST_METHOD(pushAndpop_41)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Cyclic_buffer<char, 10> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.push('d');
			buffer.pop(wsk);
			wsk++;
			buffer.pop(wsk);
			wsk++;
			buffer.pop(wsk);
			wsk++;
			buffer.pop(wsk);
			wsk++;

			Assert::AreEqual('a', tab[0]);
		}

		TEST_METHOD(pushAndpop_32different_incr)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Cyclic_buffer<char, 10> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.pop(wsk++);
			buffer.pop(wsk++);
			buffer.pop(wsk++);

			Assert::AreEqual('c', tab[2]);
		}

		TEST_METHOD(pushAndPop_1_int)
		{
			int tab[10];
			int *wsk;
			wsk = tab;
			Cyclic_buffer<int, 5> buffer;
			buffer.push(100);
			buffer.push(200);

			Assert::AreEqual(static_cast<int> (BUFFER_SUCCESS), static_cast<int> (buffer.pop(wsk)));
		}

		TEST_METHOD(pushAndpop_32_int)
		{
			int tab[10];
			int *wsk;
			wsk = tab;
			Cyclic_buffer<int, 10> buffer;
			buffer.push(100);
			buffer.push(200);
			buffer.push(300);
			buffer.pop(wsk);
			wsk++;
			buffer.pop(wsk);
			wsk++;
			buffer.pop(wsk);
			wsk++;

			Assert::AreEqual(300, tab[2]);
		}

		TEST_METHOD(pushAndPop_1_double)
		{
			double tab[10];
			double *wsk;
			wsk = tab;
			Cyclic_buffer<double, 5> buffer;
			buffer.push(100.099);
			buffer.push(200.21);
			buffer.push(-200.21);

			Assert::AreEqual(static_cast<int> (BUFFER_SUCCESS), static_cast<int> (buffer.pop(wsk)));
		}

		TEST_METHOD(pushAndpop_32_double)
		{
			double tab[10];
			double *wsk;
			wsk = tab;
			Cyclic_buffer<double, 10> buffer;
			buffer.push(100.010101);
			buffer.push(200.000999);
			buffer.push(300.1111);
			buffer.pop(wsk);
			wsk++;
			buffer.pop(wsk);
			wsk++;
			buffer.pop(wsk);
			wsk++;

			Assert::AreEqual(300.1111, tab[2]);
		}

		TEST_METHOD(popFromtop)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Cyclic_buffer<char, 10> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);

			Assert::AreEqual('a', tab[2]);
		}

		TEST_METHOD(popFromtop2)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Cyclic_buffer<char, 10> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.push('d');
			buffer.push('e');
			buffer.push('f');
			buffer.popFromtop(wsk++);
			Assert::AreEqual('f', tab[3]);
		}

		TEST_METHOD(popFromtop_toempty)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Cyclic_buffer<char, 10> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.push('d');
			buffer.push('e');
			buffer.push('f');
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);
			Assert::AreEqual(static_cast<int> (BUFFER_EMPTY), static_cast<int> (buffer.popFromtop(wsk)));
		}

		TEST_METHOD(popFromtop_toempty2)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Cyclic_buffer<char, 10> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.push('d');
			buffer.push('e');
			buffer.push('f');
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.pop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);
			
			Assert::AreEqual(static_cast<int> (BUFFER_EMPTY), static_cast<int> (buffer.popFromtop(wsk)));
		}

		TEST_METHOD(popFromtop_toempty2_checkarray)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			char tab2[10] = "";
			char *wsk2;
			wsk2 = tab2;
			Cyclic_buffer<char, 10> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.push('d');
			buffer.push('e');
			buffer.push('f');
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.pop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.push('d');
			buffer.push('e');
			buffer.push('f');

			Assert::AreEqual(static_cast<int> (BUFFER_SUCCESS), static_cast<int> (buffer.popFromtop(wsk2)));
		}

		TEST_METHOD(popFromtop_toempty2_checkarray2)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			char tab2[10] = "";
			char *wsk2;
			wsk2 = tab2;
			Cyclic_buffer<char, 10> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.push('d');
			buffer.push('e');
			buffer.push('f');
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.pop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.push('d');
			buffer.push('e');
			buffer.push('f');

			buffer.popFromtop(wsk2);
			Assert::AreEqual('f',tab2[0]);
		}

		TEST_METHOD(popFromtop_toempty2_checkarray21)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			char tab2[10] = "";
			char *wsk2;
			wsk2 = tab2;
			Cyclic_buffer<char, 10> buffer;
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.push('d');
			buffer.push('e');
			buffer.push('f');
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.pop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.popFromtop(wsk++);
			buffer.push('a');
			buffer.push('b');
			buffer.push('c');
			buffer.push('d');
			buffer.push('e');
			buffer.push('f');

			buffer.pop(wsk2);
			Assert::AreEqual('a', tab2[0]);
		}

		TEST_METHOD(popFromtop_scenario1)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			char tab2[10] = "";
			char *wsk2;
			wsk2 = tab2;
			Cyclic_buffer<char, 100> buffer;
			for (int i =0; i< 120; i++)
			buffer.push('a');

			do {
				buffer.popFromtop(wsk);
			} while (*wsk != '\0' && buffer.size() > 0);


			buffer.push('b');
			buffer.push('c');
			buffer.push('d');
			buffer.push('e');
			buffer.push('f');

			buffer.pop(wsk2);
			Assert::AreEqual('b', tab2[0]);
		}
	};
}