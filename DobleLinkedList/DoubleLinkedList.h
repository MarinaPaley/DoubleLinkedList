#pragma once
#include <initializer_list>
#include <string>
#include "Node.h"

namespace list
{
	class DoubleLinkedList final
	{
	private:
		Node* head;
		Node* tail;
	public:
		DoubleLinkedList();
		DoubleLinkedList(std::initializer_list<int> list);
		~DoubleLinkedList();
		DoubleLinkedList(const DoubleLinkedList& other) = delete;
		DoubleLinkedList(DoubleLinkedList&& other) noexcept = delete;
		DoubleLinkedList& operator=(const DoubleLinkedList& other) = delete;
		DoubleLinkedList& operator=(DoubleLinkedList&& other) noexcept = delete;
		void PushBack(const int value);
		int GetBack() const;
		void RemoveBack();
		bool IsEmpty() const;
		std::string ToString() const;
	};
}
