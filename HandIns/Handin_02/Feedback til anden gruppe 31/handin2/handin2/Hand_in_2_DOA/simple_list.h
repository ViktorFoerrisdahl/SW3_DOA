#pragma once


template <typename Object>
class List {

public:
	virtual int size() = 0;
	virtual bool empty() = 0;
	virtual void clear() = 0;
	virtual void push_front(const Object x) = 0;
	virtual void push_back(const Object x) = 0;
	virtual Object pop_front() = 0;
	virtual Object pop_back() = 0;
	virtual Object find_kth(int pos) = 0;

	//new methods 
	virtual void insert(int pos, const Object x) = 0;

	virtual Object remove(int pos) = 0;

	virtual bool contains(const Object x) = 0;

	virtual void print() = 0;

	//new method for exercise 1 b
	virtual void reverse() = 0;
	
};