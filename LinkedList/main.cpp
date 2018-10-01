#include <iostream>

#include "node.hpp"
#include "linkedlist.hpp"

int main() {
	LinkedList list = LinkedList();
	list.push(23);
	list.push(32);
	list.push(53);
	list.push(43);
	list.push(443);
	std::cout << list << std::endl;
	list.clear();
	std::cout << list << std::endl;

}
