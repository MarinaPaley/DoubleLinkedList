#include <sstream>
#include "DoubleLinkedList.h"

namespace list
{
	void DoubleLinkedList::Swap(DoubleLinkedList other) noexcept
	{
		std::swap(this->head, other.head);
		std::swap(this->tail, other.tail);
		std::swap(this->size, other.size);
	}

	DoubleLinkedList::DoubleLinkedList() : head{ nullptr }, tail{ nullptr }, size{ 0 }
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

	DoubleLinkedList::DoubleLinkedList(DoubleLinkedList&& other) noexcept
		: DoubleLinkedList()
	{
		*this = std::move(other); 
	}

	DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList& other)
	{
		if (this != &other)
		{
			DoubleLinkedList temp(other);
			this->Swap(temp);
		}

		return *this;
	}

	DoubleLinkedList& DoubleLinkedList::operator=(DoubleLinkedList&& other) noexcept
	{
		if (this != &other)
		{
			this->Swap(other);
		}

		return *this;
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

	bool DoubleLinkedList::Find(const int value)
	{
		auto current = this->head;
		while (current != nullptr && current->data != value)
		{
			current = current->next;
		}

		return current != nullptr;
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