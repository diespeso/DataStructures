#include "linkedlist.hpp"

int LinkedList::_counter = 0;

LinkedList::LinkedList() {
	p_head = NULL;
	p_tail = NULL;
}

LinkedList::~LinkedList() {
	if(isEmpty()) {
		return;
	}
	Node* next = p_head;
	Node* deleting = next;
	while(next != NULL) {
		next = deleting->p_next;
		delete deleting;
		deleting = next;
	}
}

void LinkedList::push(int data) {
	if(isEmpty()) {
		p_head = new Node(_counter, data);
		p_tail = p_head;
		_counter++;
	} else {
		p_tail->p_next = new Node(_counter, data);
		p_tail = p_tail->p_next;
		_counter++;
	}
}

/**
 * Erases the Node with the given data. If there's no
 * Node with the given data it throws a NodeNotFoundException.
 * Side effect: all the Id's of the Nodes after the erased Node
 * will be diminished by one to keep the LinkedList healthy.
 */
void LinkedList::erase(int data) {
	if(isEmpty()) {
		throw NodeNotFoundException(data);
	} else if(!contains(data)) {
		throw NodeNotFoundException(data);
	} else if(p_head->data == data) {
		Node* newHead = p_head->p_next;
		delete p_head;
		p_head = newHead;
	} else if(p_tail->data == data) {
		pop();
	} else {
		Node* current = p_head;
		while(current->p_next->data != data) {
			current = current->p_next;
		}
		Node* deleting = current->p_next;
		current->p_next = current->p_next->p_next;
		delete deleting;
	}
	

}

void LinkedList::pop() {
	if(isEmpty()) {
		throw NotPoppableException();
	} else if(p_head == p_tail && !isEmpty()) {
		delete p_head;
		p_head = p_tail = NULL;
		_counter--;
	}else {
		Node* p_newTail = p_head;
		while(p_newTail != p_tail) {
			if(p_newTail->p_next == p_tail) {
				p_newTail->p_next = NULL;
				delete p_tail;
				p_tail = p_newTail;
				_counter--;
				break;
			} else {
				p_newTail = p_newTail->p_next;
			}
		}
	}
}

//Doesn't work yet
void LinkedList::clear() {
	if(isEmpty()) {
		return;
	} else {
		Node *current = p_head;
		Node *deleting = NULL;
		while(current != NULL) {
			deleting = current;
			delete deleting;
			current = current->p_next;
		}
	}
	p_head = p_tail = NULL;
}

bool LinkedList::isEmpty() const {
	return p_head == NULL && p_tail == NULL;
}

bool LinkedList::contains(int data) const {
	Node *current = p_head;
	while(current != NULL) {
		if(current->data == data) {
			return true;
		}
		current = current->p_next;
	}
	return false;
}

std::ostream& operator<<(std::ostream& os,
	const LinkedList& list) {
	os << "[";
	Node* iter = list.p_head;
	while(iter != NULL) {
		std::cout << *iter << "->";
		iter = iter->p_next;
	}
	os << "NULL";
	os << "]";
	return os;
}

NotPoppableException::NotPoppableException() {
	_message = "This linked list is empty so it cannot pop()";
}

const char* NotPoppableException::what() const noexcept {
	return _message.data();
}

NodeNotFoundException::NodeNotFoundException(int data){
	_message = std::string("Couldn't find Node with data: ") +
	std::to_string(data) + std::string(".");
}

const char* NodeNotFoundException::what() const noexcept {
	return _message.data();
}