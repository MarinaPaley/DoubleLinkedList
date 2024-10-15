#pragma once
#include <initializer_list>
#include <string>
#include "Node.h"

namespace list
{
	class DoubleLinkedList;
	bool operator==(const DoubleLinkedList& lha, const DoubleLinkedList& rha);
	std::wstring ToString(const DoubleLinkedList& list);
	class DoubleLinkedList final
	{
	private:
		Node* head;
		Node* tail;
		std::size_t size;
		void Swap(DoubleLinkedList other) noexcept;
	public:
		DoubleLinkedList();
		DoubleLinkedList(std::initializer_list<int> list);
		~DoubleLinkedList();
		DoubleLinkedList(const DoubleLinkedList& other);
		DoubleLinkedList(DoubleLinkedList&& other) noexcept;
		DoubleLinkedList& operator=(const DoubleLinkedList& other);
		DoubleLinkedList& operator=(DoubleLinkedList&& other) noexcept;
		void PushBack(const int value);
		int GetBack() const;
		void RemoveBack();
		void PushFront(const int value);
		int GetFront() const;
		void RemoveFront();
		bool IsEmpty() const;
		std::string ToString() const;
		std::size_t GetSize() const;
		bool Find(const int value);
	};
}
