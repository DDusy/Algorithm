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
class Iterator
{
public:
	Iterator() :_node(nullptr) {}
	Iterator(Node<T>* node) :_node(node) {}

	Iterator& operator++()
	{	
		_node = _node->next;
		return *this;
	}

	Iterator& operator++(int)
	{
		Iterator<T> temp = *this;
		_node = _node->next;
		return temp;
	}

	Iterator& operator--()
	{
		_node = _node->prev;
		return *this;
	}

	Iterator& operator--(int)
	{
		Iterator<T> temp = *this;
		_node = _node->prev;
		return temp;
	}

	// *it
	T& operator*()
	{
		return _node->Data;
	}

	bool operator==(const Iterator& other)
	{
		return _node == other._node;
	}

	bool operator!=(const Iterator& other)
	{
		return _node != other._node;
	}


public:
	Node<T>* _node;
};

template<typename T>
class List
{
public:
	List() : _size(0)
	{
		_head = new Node<T>();
		_tail = new Node<T>();
		_head->next = _tail;
		_tail->prev = _head;
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
		RemoveNode(_tail->prev);
	}

private:
	Node<T>* AddNode(Node<T>* before, const T& value);
	Node<T>* RemoveNode(Node<T>* node);
	int size() { return _size; }

public:
	using iterator = Iterator<T>;
	iterator begin() { return iterator(_head->next); }
	iterator end() { return iterator(_tail); }

	//iterator 앞에 추가
	iterator insert(iterator it, const T& value)
	{
		Node<T>* node = AddNode(it._node, value);
		return iterator(node);
	}

	iterator erase(iterator it)
	{
		Node<T>* node = RemoveNode(it._node);
		return iterator(node);
	}

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
	Node<T>* prevNode = node->prev;
	Node<T>* nextNode = node->next;

	prevNode->next = nextNode;
	nextNode->prev = prevNode;

	delete node;

	_size--;

	return nextNode;
}
