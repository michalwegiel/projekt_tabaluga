#include "stdafx.h"
#include "CppUnitTest.h"
#include "cyclic_buffer.h"
#include "super_buffer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SuperBuffer
{
	TEST_CLASS(BasicFunctionalityOfSuperbuffer)
	{
	public:

		TEST_METHOD(push)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Super_buffer superbuffer;
			
			Assert::AreEqual(static_cast<int> (SUPER_BUFFER_SUCCESS), static_cast<int> (superbuffer.push('a')));
		}

		TEST_METHOD(pushAndpop)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Super_buffer superbuffer;
			superbuffer.push('a');
			superbuffer.push('\0');

			Assert::AreEqual(static_cast<int> (SUPER_BUFFER_SUCCESS), static_cast<int> (superbuffer.pop(wsk, 2)));
		}

		TEST_METHOD(pushAndpop2)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Super_buffer superbuffer;
			superbuffer.push('a');
			superbuffer.push('b');
			superbuffer.push('c');
			superbuffer.push('d');
			superbuffer.push('\0');

			Assert::AreEqual(static_cast<int> (SUPER_BUFFER_SUCCESS), static_cast<int> (superbuffer.pop(wsk,5)));
		}

		TEST_METHOD(pushAndpopEnter)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Super_buffer superbuffer;
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('a');

			Assert::AreEqual(static_cast<int> (SUPER_BUFFER_SUCCESS), static_cast<int> (superbuffer.pop(wsk, 1)));
		}

		TEST_METHOD(pushAndpopAndCheckArray)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Super_buffer superbuffer;
			superbuffer.push('a');
			superbuffer.push('b');
			superbuffer.pop(wsk++, 10);
			
			Assert::AreEqual('b', tab[1]);
		}

		TEST_METHOD(pushAndpopAndCheckArray2)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Super_buffer superbuffer;
			superbuffer.push('a');
			superbuffer.push('b');
			superbuffer.push('c');
			superbuffer.push('d');
			superbuffer.push('e');
			superbuffer.push('f');
			superbuffer.push('\0');
			superbuffer.pop(wsk++, 10);
			
			Assert::AreEqual('f', tab[5]);
		}

		TEST_METHOD(CommandStartsFromEnter)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Super_buffer superbuffer;
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('a');
			superbuffer.push('b');
			superbuffer.push('c');
			superbuffer.push('d');
			superbuffer.push('\0');

			Assert::AreEqual(static_cast<int> (SUPER_BUFFER_SUCCESS), static_cast<int> (superbuffer.pop(wsk, 5)));
		}
		TEST_METHOD(CommandStartsFromEnterCheckArray)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Super_buffer superbuffer;
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('a');
			superbuffer.push('b');
			superbuffer.push('c');
			superbuffer.push('d');
			superbuffer.push('\0');
			superbuffer.pop(wsk, 5);

			Assert::AreEqual('d', tab[3]);
		}

		TEST_METHOD(CommandStartsFromEnterCheckArray2)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Super_buffer superbuffer;
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('a');
			superbuffer.push('b');
			superbuffer.push('c');
			superbuffer.push('d');
			superbuffer.push('\0');
			superbuffer.pop(wsk, 5);

			Assert::AreEqual('a', tab[0]);
		}

		TEST_METHOD(CommandInCyclicBufferBiggerThanExpected)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Super_buffer superbuffer;
			superbuffer.push('a');
			superbuffer.push('b');
			superbuffer.push('c');
			superbuffer.push('d');
			superbuffer.push('e');
			superbuffer.push('f');
			superbuffer.push('g');
			superbuffer.push('h');
			superbuffer.push('i');
			superbuffer.push('\0');

			Assert::AreEqual(static_cast<int> (SUPER_BUFFER_ERROR_SIZE_SMALLER_THAN_COMMAND_IN_CYCLIC_BUFFER), static_cast<int> (superbuffer.pop(wsk, 5)));
		}

		TEST_METHOD(CommandInCyclicBufferBiggerThanExpectedCheckIfCyclicBufferIsEmpty)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Super_buffer superbuffer;
			superbuffer.push('a');
			superbuffer.push('b');
			superbuffer.push('c');
			superbuffer.push('d');
			superbuffer.push('e');
			superbuffer.push('f');
			superbuffer.push('g');
			superbuffer.push('h');
			superbuffer.push('i');
			superbuffer.push('\0');
			superbuffer.pop(wsk, 5);

			Assert::AreEqual(static_cast<int> (SUPER_BUFFER_ERROR_CYCLIC_BUFFER_EMPTY), static_cast<int> (superbuffer.pop(wsk, 5)));
		}

		TEST_METHOD(CommandInCyclicBufferSmallerThanExpected)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Super_buffer superbuffer;
			superbuffer.push('a');
			superbuffer.push('b');
			superbuffer.push('c');
			superbuffer.push('\0');
			
			Assert::AreEqual(static_cast<int> (SUPER_BUFFER_ERROR_COMMAND_SMALLER_THAN_EXPECTED), static_cast<int> (superbuffer.pop(wsk, 5)));
		}

		TEST_METHOD(BufferEmptyAndPop)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Super_buffer superbuffer;

			Assert::AreEqual(static_cast<int> (SUPER_BUFFER_ERROR_CYCLIC_BUFFER_EMPTY), static_cast<int> (superbuffer.pop(wsk, 5)));
		}

		TEST_METHOD(BufferEmptyAndPop2)
		{
			char tab[10] = "";
			char *wsk;
			wsk = tab;
			Super_buffer superbuffer;
			superbuffer.push('a');
			superbuffer.pop(wsk, 1);

			Assert::AreEqual(static_cast<int> (SUPER_BUFFER_ERROR_CYCLIC_BUFFER_EMPTY), static_cast<int> (superbuffer.pop(wsk, 5)));
		}

		TEST_METHOD(FewCommands)
		{
			char tab1[4] = "";
			char *wsk1;
			wsk1 = tab1;
			char tab2[4] = "";
			char *wsk2;
			wsk2 = tab2;
			char tab3[4] = "";
			char *wsk3;
			wsk3 = tab3;
			Super_buffer superbuffer;
			superbuffer.push('a');
			superbuffer.push('b');
			superbuffer.push('c');
			superbuffer.push('\0');
			superbuffer.push('d');
			superbuffer.push('e');
			superbuffer.push('f');
			superbuffer.push('\0');
			superbuffer.push('g');
			superbuffer.push('h');
			superbuffer.push('i');
			superbuffer.push('\0');
			superbuffer.push('j');
			superbuffer.push('k');
			superbuffer.push('l');
			superbuffer.push('\0');
			superbuffer.push('m');
			superbuffer.push('n');
			superbuffer.push('o');
			superbuffer.push('\0');
			superbuffer.pop(wsk1, 4);
			superbuffer.pop(wsk2, 4);
			superbuffer.pop(wsk3, 4);

			Assert::AreEqual('g',tab3[0]);
		}

		TEST_METHOD(FewCommands_many_enters)
		{
			char tab1[4] = "";
			char *wsk1;
			wsk1 = tab1;
			char tab2[4] = "";
			char *wsk2;
			wsk2 = tab2;
			char tab3[4] = "";
			char *wsk3;
			wsk3 = tab3;
			Super_buffer superbuffer;
			superbuffer.push('\0');
			superbuffer.push('a');
			superbuffer.push('b');
			superbuffer.push('c');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('d');
			superbuffer.push('e');
			superbuffer.push('f');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('g');
			superbuffer.push('h');
			superbuffer.push('i');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('j');
			superbuffer.push('k');
			superbuffer.push('l');
			superbuffer.push('\0');
			superbuffer.push('m');
			superbuffer.push('n');
			superbuffer.push('o');
			superbuffer.push('\0');
			superbuffer.pop(wsk1, 4);
			superbuffer.pop(wsk2, 4);
			superbuffer.pop(wsk3, 4);

			Assert::AreEqual('g', tab3[0]);
		}

		TEST_METHOD(FewCommands_firsttooshort)
		{
			char tab1[4] = "";
			char *wsk1;
			wsk1 = tab1;
			char tab2[4] = "";
			char *wsk2;
			wsk2 = tab2;
			char tab3[4] = "";
			char *wsk3;
			wsk3 = tab3;
			Super_buffer superbuffer;
			superbuffer.push('a');
			superbuffer.push('b');
			superbuffer.push('c');
			superbuffer.push('c');
			superbuffer.push('c');
			superbuffer.push('c');
			superbuffer.push('c');
			superbuffer.push('c');
			superbuffer.push('\0');
			superbuffer.push('d');
			superbuffer.push('e');
			superbuffer.push('f');
			superbuffer.push('\0');
			superbuffer.push('g');
			superbuffer.push('h');
			superbuffer.push('i');
			superbuffer.push('\0');
			superbuffer.push('j');
			superbuffer.push('k');
			superbuffer.push('l');
			superbuffer.push('\0');
			superbuffer.push('m');
			superbuffer.push('n');
			superbuffer.push('o');
			superbuffer.push('\0');
			superbuffer.pop(wsk1, 4);
			superbuffer.pop(wsk2, 4);
			superbuffer.pop(wsk3, 4);

			Assert::AreEqual('g', tab3[0]);
		}

		TEST_METHOD(FewCommands_mixed)
		{
			char tab1[4] = "";
			char *wsk1;
			wsk1 = tab1;
			char tab2[4] = "";
			char *wsk2;
			wsk2 = tab2;
			char tab3[4] = "";
			char *wsk3;
			wsk3 = tab3;
			Super_buffer superbuffer;
			superbuffer.push('a');
			superbuffer.push('b');
			superbuffer.push('c');
			superbuffer.push('c');
			superbuffer.push('c');
			superbuffer.push('c');
			superbuffer.push('c');
			superbuffer.push('c');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('d');
			superbuffer.push('e');
			superbuffer.push('f');
			superbuffer.push('\0');
			superbuffer.push('g');
			superbuffer.push('h');
			superbuffer.push('i');
			superbuffer.push('\0');
			superbuffer.push('j');
			superbuffer.push('k');
			superbuffer.push('l');
			superbuffer.push('\0');
			superbuffer.push('m');
			superbuffer.push('n');
			superbuffer.push('o');
			superbuffer.push('\0');
			superbuffer.pop(wsk1, 4);
			superbuffer.pop(wsk2, 10);
			superbuffer.pop(wsk3, 4);

			Assert::AreEqual('g', tab3[0]);
		}

		TEST_METHOD(FewCommands_mixed2)
		{
			char tab1[4] = "";
			char *wsk1;
			wsk1 = tab1;
			char tab2[4] = "";
			char *wsk2;
			wsk2 = tab2;
			char tab3[4] = "";
			char *wsk3;
			wsk3 = tab3;
			Super_buffer superbuffer;
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('a');
			superbuffer.push('b');
			superbuffer.push('c');
			superbuffer.push('c');
			superbuffer.push('c');
			superbuffer.push('c');
			superbuffer.push('c');
			superbuffer.push('c');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('\0');
			superbuffer.push('d');
			superbuffer.push('\0');
			superbuffer.push('g');
			superbuffer.push('h');
			superbuffer.push('i');
			superbuffer.push('i');
			superbuffer.push('\0');
			superbuffer.push('j');
			superbuffer.push('k');
			superbuffer.push('l');
			superbuffer.push('\0');
			superbuffer.push('m');
			superbuffer.push('n');
			superbuffer.push('o');
			superbuffer.push('\0');
			superbuffer.pop(wsk1, 4);
			superbuffer.pop(wsk2, 10);
			superbuffer.pop(wsk3, 4);

			Assert::AreEqual('g', tab3[0]);
		}

		TEST_METHOD(FillBufferFromEmptyAndCheckErrorCode)
		{
			char tab1[100] = "";
			char *wsk1;
			wsk1 = tab1;

			Super_buffer superbuffer;
			for(int i =0; i<120; i++)
			superbuffer.push('a');
			
			Assert::AreEqual(static_cast<int> (SUPER_BUFFER_ERROR_CYCLIC_BUFFER_FULL), static_cast<int> (superbuffer.push('a')));
		}

		TEST_METHOD(FillBufferAndCheckErrorCode)
		{
			char tab1[100] = "";
			char *wsk1;
			wsk1 = tab1;
			Super_buffer superbuffer;
			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('\0');

			for (int i = 0; i < 120; i++)
				superbuffer.push('a');

			Assert::AreEqual(static_cast<int> (SUPER_BUFFER_ERROR_CYCLIC_BUFFER_FULL), static_cast<int> (superbuffer.push('a')));
		}

		TEST_METHOD(FillBuffer)
		{
			char tab1[100] = "";
			char *wsk1;
			wsk1 = tab1;

			Super_buffer superbuffer;
			for (int i = 0; i < 120; i++)
				superbuffer.push('a');

			Assert::AreEqual(static_cast<int> (SUPER_BUFFER_ERROR_CYCLIC_BUFFER_EMPTY), static_cast<int> (superbuffer.pop(wsk1, 5)));
		}

		TEST_METHOD(FillBuffer2)
		{
			char tab1[100] = "";
			char *wsk1;
			wsk1 = tab1;

			Super_buffer superbuffer;
			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('\0');
			for (int i = 0; i < 94; i++)
				superbuffer.push('b');

			superbuffer.push('c');
			superbuffer.push('c');
			Assert::AreEqual(static_cast<int> (SUPER_BUFFER_SUCCESS), static_cast<int> (superbuffer.pop(wsk1, 5)));

		}

		TEST_METHOD(FillBuffer3)
		{
			char tab1[100] = "";
			char *wsk1;
			wsk1 = tab1;

			Super_buffer superbuffer;
			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('\0');
			for (int i = 0; i < 100; i++)
				superbuffer.push('b');

			superbuffer.push('c');
			superbuffer.push('c');
			
			superbuffer.pop(wsk1, 5);
			Assert::AreEqual('a', tab1[0]);
		}
		
		TEST_METHOD(FillBuffer4)
		{
			char tab1[100] = "";
			char *wsk1;
			wsk1 = tab1;
			char tab2[100] = "";
			char *wsk2;
			wsk2 = tab2;

			Super_buffer superbuffer;
			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('\0');
			for (int i = 0; i < 100; i++)
				superbuffer.push('b');


			superbuffer.pop(wsk1, 5);
			
			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('\0');
			superbuffer.push('d');
			superbuffer.push('d');
			superbuffer.push('d');
			superbuffer.push('\0');
			
			superbuffer.pop(wsk2, 4);
			Assert::AreEqual('d', tab2[0]);
				
		}

		TEST_METHOD(FillBuffer_mixed)
		{
			char tab1[100] = "";
			char *wsk1;
			wsk1 = tab1;
			char tab2[100] = "";
			char *wsk2;
			wsk2 = tab2;

			Super_buffer superbuffer;
			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('\0');
			superbuffer.push('b');
			superbuffer.push('b');
			superbuffer.push('b');
			superbuffer.push('b');
			superbuffer.push('\0');
			for (int i = 0; i < 100; i++)
				superbuffer.push('c');


			superbuffer.pop(wsk1, 5);

			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('\0');
			superbuffer.push('d');
			superbuffer.push('d');
			superbuffer.push('d');
			superbuffer.push('\0');
			superbuffer.push('e');
			superbuffer.push('e');
			superbuffer.push('e');
			superbuffer.push('\0');
			superbuffer.push('f');
			superbuffer.push('f');
			superbuffer.push('f');
			superbuffer.push('\0');

			for (int i = 0; i < 100; i++)
				superbuffer.push('c');



			superbuffer.pop(wsk2, 4);
			Assert::AreEqual('b', tab2[0]);

		}

		TEST_METHOD(FillBuffer_mixed2)
		{
			char tab1[100] = "";
			char *wsk1;
			wsk1 = tab1;
			char tab2[100] = "";
			char *wsk2;
			wsk2 = tab2;

			Super_buffer superbuffer;
			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('\0');
			superbuffer.push('b');
			superbuffer.push('b');
			superbuffer.push('b');
			superbuffer.push('b');
			superbuffer.push('\0');
			for (int i = 0; i < 100; i++)
				superbuffer.push('c');


			superbuffer.pop(wsk1, 5);

			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('a');
			superbuffer.push('\0');
			superbuffer.push('d');
			superbuffer.push('d');
			superbuffer.push('d');
			superbuffer.push('\0');
			superbuffer.push('e');
			superbuffer.push('e');
			superbuffer.push('e');
			superbuffer.push('\0');
			superbuffer.push('f');
			superbuffer.push('f');
			superbuffer.push('f');
			superbuffer.push('\0');

			for (int i = 0; i < 100; i++)
				superbuffer.push('c');



			superbuffer.pop(wsk2, 5);
			//superbuffer.pop(wsk2, 4);
			//superbuffer.pop(wsk2, 4);
			Assert::AreEqual('b', tab2[0]);

		}
	
	};
	
}