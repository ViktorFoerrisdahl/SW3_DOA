#ifndef MIN_HEAP_H
#define MIN_HEAP_H

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* parent;
    Node* left;
    Node* right;
    
    // Constructor
    Node(T value) {
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
        // YOUR CODE GOES HERE
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
        // YOUR CODE GOES HERE
    }

    /**
     * @brief Access the minimum (top) element of the Heap
     *
     * @return T Minimum element in Heap
     */
    T peek()
    {
        // YOUR CODE GOES HERE
    }
};

#endif