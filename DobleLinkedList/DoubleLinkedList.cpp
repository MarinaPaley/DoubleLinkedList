#include <sstream>
#include "DoubleLinkedList.h"

namespace list
{
	DoubleLinkedList::DoubleLinkedList() : head{ nullptr }, tail{ nullptr }, size{0}
	{
	}

	DoubleLinkedList::DoubleLinkedList(std::initializer_list<int> list)
		: DoubleLinkedList()
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

	DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& other)
		: DoubleLinkedList()
	{
		auto current = other.tail;
		while (current != nullptr)
		{
			this->PushFront(current->data);
			current = current->previous;
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
		++this->size;
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
			--this->size;
		}
	}

	void DoubleLinkedList::PushFront(const int value)
	{
		auto node = new Node{ value };
		if (this->IsEmpty())
		{
			this->head = node;
			this->tail = node;
		}
		else 
		{
			this->head->previous = node;
			node->next = this->head;
			this->head = node;
		}
		++this->size;
	}

	int DoubleLinkedList::GetFront() const
	{
		if (this->IsEmpty())
		{
			throw std::out_of_range("Список пуст!");
		}

		return this->head->data;
	}

	void DoubleLinkedList::RemoveFront()
	{
		if (!this->IsEmpty())
		{
			auto temp = this->head;
			this->head = this->head->previous;
			this->head->next = nullptr;
			delete temp;
			--this->size;
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
	std::size_t DoubleLinkedList::GetSize() const
	{
		return this->size;
	}

	bool operator==(const DoubleLinkedList& lha, const DoubleLinkedList& rha)
	{
		return lha.ToString() == rha.ToString();
	}

	std::wstring ToString(const DoubleLinkedList& list)
	{
		const auto temp = list.ToString();
		std::wstring buffer{ temp.cbegin(), temp.cend() };

		return buffer;
	}
}