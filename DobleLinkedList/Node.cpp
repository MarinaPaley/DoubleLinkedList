#include "Node.h"

namespace list
{
	Node::Node(const int value) : data{ value }, previous{ nullptr }, next{ nullptr }
	{
	}
}