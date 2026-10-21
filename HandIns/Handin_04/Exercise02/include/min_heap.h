#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node *parent;
    Node *left;
    Node *right;

    // Constructor
    Node(T value)
    {
        data = value;
        left = right = nullptr;
    }
};

/**
 * @brief Min-Heap Class
 *
 * @tparam T
 */

template <typename T>
class MinHeap
{
public:
    /**
     * @brief Inserts an element and updates the Heap
     *
     * @param x Element to insert
     */
    void insert(const T &x)
    {
        Node<T>* newNode = new Node<T>(x); //Allokere plads til vores nye node og danner den

        if (root == nullptr) //hvis heapen er tom dannes vores nye root
        {
            root = newNode;
        }


    }

    /**
     * @brief Remove minimum (top) element and update Heap
     *
     */
    void remove()
    {
        // YOUR CODE GOES HERE
    }

    /**
     * @brief Inspect if Heap is empty
     *
     * @return true Heap is empty
     * @return false Heap is not empty
     */
    bool isEmpty() const
    {
        return root == nullptr;
    }

    /**
     * @brief Access the minimum (top) element of the Heap
     *
     * @return T Minimum element in Heap
     */
    T peek()
    {
        if (root == nullptr)
        {
            throw std::runtime_error("Heapen er tom og derfor findes ingen minimum / top element :( \n");
        }
        else
        {
            return root->data;
        }
    }

private:
    Node<T>* root = nullptr;
};

#endif