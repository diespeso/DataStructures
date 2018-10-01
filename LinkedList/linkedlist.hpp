#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "node.hpp"
#include <iostream>

#include <exception>
using std::exception;

class LinkedList {
private:
	static int _counter;
public:
	Node* p_head;
	Node* p_tail;
	LinkedList();
	~LinkedList();

	void push(int);
	void pop();
	void erase(int);
	void clear();

	bool isEmpty() const;
	bool contains(int) const;

	friend std::ostream& operator<<(std::ostream&,
		const LinkedList&);
};

class NotPoppableException: public exception {
private:
	std::string _message;
public:
	NotPoppableException();
	const char* what() const noexcept override;

};

class NodeNotFoundException: public exception {
private:
	std::string _message;
public:
	NodeNotFoundException(int);
	const char* what() const noexcept override;
};

#endif
