#include <stdexcept>
#include <iostream>

template <typename Object>
void List<Object>::clear()
{
	Node *p = head->next;
	while (p != tail)
	{
		Node *t = p->next;
		delete p;
		p = t;
		head->next = t;
	}
	theSize = 0;
}

template <typename Object>
void List<Object>::insert(const Object x, int pos)
{
	if (pos < 0 || theSize < pos)
	{
		throw std::out_of_range("Position is out of range");
	}
	Node *p = head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	Node *pNew = new Node;
	pNew->data = x;
	pNew->next = p->next;
	p->next = pNew;
	theSize++;
}
template <typename Object>
void List<Object>::push_front(const Object x)
{
	Node *p = new Node;
	p->data = x;
	p->next = head->next;
	head->next = p;
	theSize++;
}

template <typename Object>
void List<Object>::push_back(const Object x)
{
	Node *p = head;
	while (p->next != tail)
	{
		p = p->next;
	}
	Node *pNew = new Node;
	pNew->data = x;
	p->next = pNew;
	pNew->next = tail;
	theSize++;
}

template <typename Object>
void List<Object>::reverse()
{
	Node *pre = tail;
	Node *cur = head->next;
	Node *next = cur->next;

	while (cur != tail)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	head->next = pre;
}

template <typename Object>
void List<Object>::print()
{
	Node *p = head;
	while (p->next != tail)
	{
		p = p->next;
		std::cout << p->data << ", ";
	}
}

template <typename Object>
Object List<Object>::remove(int pos)
{
	if (pos < 0 || pos >= theSize)
	{
		throw std::out_of_range("Position is out of range");
	}
	Node *p = head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	Node *temp = p->next;
	Object x = temp->data;
	p->next = p->next->next;
	delete temp;
	theSize--;
	return x;
}

template <typename Object>
Object List<Object>::pop_front()
{
	if (theSize == 0)
	{
		throw std::out_of_range("Cannot pop from the front of empty list");
	}
	Node *p = head->next;
	Object x = p->data;
	head->next = p->next;
	theSize--;
	delete p;
	return x;
}

template <typename Object>
Object List<Object>::pop_back()
{
	if (theSize == 0)
	{
		throw std::out_of_range("Cannot pop from the back of empty list");
	}
	Node *p = head;
	while (p->next->next != tail)
	{
		p = p->next;
	}

	Node *pLast = p->next;
	Object x = pLast->data;
	p->next = tail;
	delete pLast;
	theSize--;
	return x;
}

template <typename Object>
Object List<Object>::find_kth(int pos)
{
	if (pos < 0 || pos >= theSize)
	{
		throw std::out_of_range("Position is out of range");
	}
	Node *p = head->next;
	while (pos > 0)
	{
		p = p->next;
		pos--;
	}
	return p->data;
}

template <typename Object>
bool List<Object>::contains(Object x)
{
	Node *p = head;
	while (p->next != tail)
	{
		p = p->next;
		if (p->data == x)
		{
			return true;
		}
	}
	return false;
}
