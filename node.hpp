#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

class Node {
public:
	int id;
	int data;
	Node* p_next;

	Node(int, int);
	~Node();

	friend std::ostream& operator<<(std::ostream&,
		const Node&);
};

#endif