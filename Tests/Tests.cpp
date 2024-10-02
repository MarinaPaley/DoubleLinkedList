#include "pch.h"
#include "CppUnitTest.h"
#include "../DobleLinkedList/DoubleLinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace list;

namespace DoubleLinkedListTests
{
	TEST_CLASS(DoubleLinkedListTests)
	{
	public:
		
		TEST_METHOD(ToString_ValidData_Success)
		{
			// arrange
			DoubleLinkedList list{ 1, 2, 3, 4, 5 };
			std::string expected{ "1 2 3 4 5 " };

			// act
			auto actual = list.ToString();

			// assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(PushBack_ValidData_Success)
		{
			// arrange
			DoubleLinkedList list{ };
			std::string expected{ "1 " };

			// act
			list.PushBack(1);
			auto actual = list.ToString();

			// assert
			Assert::AreEqual(expected, actual);
		}
	};
}
