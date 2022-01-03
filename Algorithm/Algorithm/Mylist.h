#pragma once


template<typename T> 
class Node
{
public:
	Node() :prev(nullptr), next(nullptr), Data(T()) {}

	Node(const T& _value) :prev(nullptr), next(nullptr), Data(_value) {}



	Node* prev;
	Node* next;
	T	  Data;
}; 



template<typename T>
class List
{
public:
	List() : _size(0)
	{
		// [head] <-> ... <-> [tail]
		_head = new Node<T>();
		_tail = new Node<T>();
		_head->_next = _tail;
		_tail->_prev = _head;
	}

	~List()
	{
		while (_size > 0)
			pop_back();

		delete _head;
		delete _tail;
	}

	void push_back(const T& value)
	{
		AddNode(_tail, value);
	}

	void pop_back()
	{
		RemoveNode(_tail->_prev);
	}

private:
	Node<T>* AddNode(Node<T>* before, const T& value);
	Node<T>* RemoveNode(Node<T>* node);
	int size() { return _size; }
private:
	Node<T>* _head;
	Node<T>* _tail;
	int			_size;
};

template<typename T>
inline Node<T>* List<T>::AddNode(Node<T>* before, const T& value)
{
	Node<T>* newNode = new Node<T>(value);

	Node<T>* prevNode = before->prev;

	prevNode->next = newNode;
	newNode->prev = prevNode;

	newNode->next = before;
	before->prev = newNode;

	_size++;

	return newNode;
}

template<typename T>
inline Node<T>* List<T>::RemoveNode(Node<T>* node)
{
	Node<T>* prevNode = node->_prev;
	Node<T>* nextNode = node->_next;

	prevNode->_next = nextNode;
	nextNode->_prev = prevNode;

	delete node;

	_size--;

	return nextNode;
}
