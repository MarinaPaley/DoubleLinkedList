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

		TEST_METHOD(GetBack_DDLNotEmpty_GetValue)
		{
			// arrange
			DoubleLinkedList list{ 1, 2, 3, 4, 5 };
			auto expected = 5;

			// Act
			auto actual = list.GetBack();

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetBack_DDLEmpty_ExpectedException)
		{
			// arrange
			DoubleLinkedList list{};
			
			Assert::ExpectException<std::out_of_range>([&]() {auto x = list.GetBack(); });
		}

		TEST_METHOD(GetFront_DDLEmpty_ExpectedException)
		{
			// arrange
			DoubleLinkedList list{};

			Assert::ExpectException<std::out_of_range>([&]() {auto x = list.GetBack(); });
		}

		TEST_METHOD(RemoveBack_DDLNotEmpty_Success)
		{
			// Arrange
			DoubleLinkedList list{ 1, 2, 3, 4, 5 };
			DoubleLinkedList expected{ 1, 2, 3, 4 };

			// Act
			list.RemoveBack();

			//Assert
			Assert::AreEqual(expected, list);
		}

		TEST_METHOD(CopyCtor_ValidData_Success)
		{
			// Arrange
			DoubleLinkedList list{ 1, 2, 3, 4, 5 };

			// Act
			DoubleLinkedList other(list);
			list.PushBack(6);

			// Assert
			Assert::AreNotEqual(list, other);
			Assert::AreNotSame(list, other);
		}

		TEST_METHOD(CopyOperator_ValidData_Success)
		{
			// Arrange
			DoubleLinkedList expected{ 1, 2, 3, 4 };
			DoubleLinkedList actual{ 0 };

			// Act
			actual = expected;

			// Assert
			Assert::AreEqual(expected, actual);
			Assert::AreNotSame(expected, actual);
		}

		TEST_METHOD(CopyOperator_SameData_Success)
		{
			// Arrange
			DoubleLinkedList expected{ 1, 2, 3, 4 };

			// Act
			expected = expected;

			// Assert
			Assert::AreEqual(expected, expected);
			Assert::AreSame(expected, expected);
		}

		TEST_METHOD(MoveCtor_ValidData_Success)
		{
			// Arrange
			DoubleLinkedList list{ 1, 2, 3, 4, 5 };

			// Act
			DoubleLinkedList other(std::move(list));

			// Assert
			Assert::AreNotSame(list, other);
		}

		TEST_METHOD(MoveOperator_ValidData_Success)
		{
			// Arrange
			DoubleLinkedList expected{ 1, 2, 3, 4 };
			DoubleLinkedList actual{ 0 };

			// Act
			actual = std::move(expected);

			// Assert
			Assert::AreNotSame(expected, actual);
		}

		TEST_METHOD(MoveOperator_SameData_Success)
		{
			// Arrange
			DoubleLinkedList expected{ 1, 2, 3, 4 };

			// Act
			expected = expected;

			// Assert
			Assert::AreSame(expected, expected);
		}

		TEST_METHOD(Find_DataExists_True)
		{
			// Arrange
			DoubleLinkedList list{ 1, 2, 3, 4 };

			// Act & Assert
			Assert::IsTrue(list.Find(4));
		}

		TEST_METHOD(Find_DataNotExist_False)
		{
			// Arrange
			DoubleLinkedList list{ 1, 2, 3, 4 };

			// Act & Assert
			Assert::IsFalse(list.Find(6));
		}
	};
}
