#pragma once

#include "binary_search_tree.h"

template <typename Comparable>
class OrderedSet
{
public:
    using iterator =
        typename BinarySearchTree<Comparable>::iterator;


    OrderedSet() = default;


    // deep copy igennem BinarySearchTree copy constructor
    OrderedSet(const OrderedSet& s)
        : tree(s.tree)
    {
    }


    OrderedSet& operator=(const OrderedSet& rhs)
    {
        tree = rhs.tree;
        return *this;
    }


    bool empty() const
    {
        return tree.isEmpty();
    }


    std::size_t size() const
    {
        return tree.size();
    }


    iterator insert(const Comparable& x)
    {
        return tree.insert(x);
    }


    iterator find(const Comparable& x) const
    {
        return tree.find(x);
    }


    iterator erase(iterator itr)
    {
        if (itr == end())
            return end();

        Comparable valueToErase = *itr;

        iterator next = itr;
        ++next;

        if (next == end())
        {
            tree.remove(valueToErase);
            return end();
        }

        Comparable nextValue = *next;

        tree.remove(valueToErase);

        return tree.find(nextValue);
    }


    iterator begin() const
    {
        return tree.begin();
    }


    iterator end() const
    {
        return tree.end();
    }


private:
    BinarySearchTree<Comparable> tree;
};