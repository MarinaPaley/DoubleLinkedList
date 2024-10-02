#pragma once
namespace list
{
	struct Node final
	{
		int data;
		Node* previous;
		Node* next;
		Node(const int value);
	};
}
