#include <iostream>
#include "../DobleLinkedList/DoubleLinkedList.h"

int main()
{
	list::DoubleLinkedList list{1, 2, 3, 4, 5};
	std::cout << list.ToString() << std::endl;
	list::DoubleLinkedList other(list);
	std::cout << other.ToString();
	return 0;
}