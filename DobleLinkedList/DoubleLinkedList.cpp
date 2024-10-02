#include <sstream>
#include "DoubleLinkedList.h"

namespace list
{
	DoubleLinkedList::DoubleLinkedList() : head{ nullptr }, tail{ nullptr }
	{
	}

	DoubleLinkedList::DoubleLinkedList(std::initializer_list<int> list)
	{
		for (auto item = list.begin(); item != list.end(); ++item)
		{
			this->PushBack(*item);
		}
	}

	DoubleLinkedList::~DoubleLinkedList()
	{
		auto current = this->head;
		while (current != nullptr)
		{
			auto temp = current;
			current = current->next;
			delete temp;
		}
	}

	void DoubleLinkedList::PushBack(const int value)
	{
		auto node = new Node{ value };
		if (this->IsEmpty())
		{
			this->head = node;
			this->tail = node;
		}
		else
		{
			this->tail->next = node;
			node->previous = this->tail;
			this->tail = node;
		}
	}

	int DoubleLinkedList::GetBack() const
	{
		if (this->IsEmpty())
		{
			throw std::out_of_range("Список пуст!");
		}

		return this->tail->data;
	}

	void DoubleLinkedList::RemoveBack()
	{
		if (!this->IsEmpty())
		{
			auto temp = this->tail;
			this->tail = this->tail->previous;
			this->tail->next = nullptr;
			delete temp;
		}
	}

	bool DoubleLinkedList::IsEmpty() const
	{
		return this->head == nullptr;
	}

	std::string DoubleLinkedList::ToString() const
	{
		std::stringstream buffer{};
		auto current = this->head;
		while (current != nullptr)
		{
			buffer << current->data << " ";
			current = current->next;
		}

		return buffer.str();
	}
}