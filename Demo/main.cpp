#include <iostream>
#include "../DobleLinkedList/DoubleLinkedList.h"

int main()
{
	list::DoubleLinkedList list{ 1, 2, 3, 4, 5 };
	std::cout << "list " << list.ToString() << std::endl;
	list::DoubleLinkedList other(list);
	std::cout << "Copy ctor " << other.ToString() << std::endl;
	list.PushBack(6);
	other = list;
	std::cout << "Copy operator= " << other.ToString() << std::endl;
	list::DoubleLinkedList move(std::move(list));
	std::cout << "Move ctor " << move.ToString() << std::endl;
	move.RemoveBack();
	other = std::move(move);
	std::cout << "Move operator= " << other.ToString() << std::endl;

	return 0;
}