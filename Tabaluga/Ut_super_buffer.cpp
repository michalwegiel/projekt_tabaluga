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
			superbuffer.push('b');
			superbuffer.push('c');
			superbuffer.push('d');
			superbuffer.push('\0');

			Assert::AreEqual(static_cast<int> (SUPER_BUFFER_SUCCESS), static_cast<int> (superbuffer.pop(wsk,5)));
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

	};
	
}