//
//#include<iostream>
//
//using namespace std;
//
//template<typename T>
//class Node
//{
//public:
//	Node() : _prev(nullptr), _next(nullptr), _data(T()) {}
//	Node(const T& _value) : _prev(nullptr), _next(nullptr), _data(_value) {}
//private:
//
//	Node* _prev;
//	Node* _next;
//	T	  _data;
//};
//
//template<typename T>
//class List
//{
//	List() : Head(nullptr), Tail(nullptr), _size(0)
//	{
//		Head = new Node < T >();
//		Tail= new Node < T >();
//		Head->_next = Tail;
//		Tail->_prev = Head;
//	}
//
//public:
//	Node* Head;
//	Node* Tail;
//	int  _size;
//};
//
