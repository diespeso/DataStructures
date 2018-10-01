#include "node.hpp"

Node::Node(int id, int data) {
	this->id = id;
	this->data = data;
}

Node::~Node() {
	std::cout << id << ": " << "Deleted" 
	<< " with data: " << data << std::endl;
}

std::ostream& operator<<(std::ostream& os,
	const Node& node) {
	os << "[" << node.id << ", " << node.data << ", ";
	os << node.p_next << "]";
	return os;
}