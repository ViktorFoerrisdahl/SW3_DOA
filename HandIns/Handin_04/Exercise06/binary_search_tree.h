#pragma once

#include <cstddef>
#include <utility>

template <typename Comparable>
class BinarySearchTree
{
private:
    struct BinaryNode
    {
        Comparable element;
        BinaryNode* left;
        BinaryNode* right;
        BinaryNode* parent;

        BinaryNode(const Comparable& value, BinaryNode* p = nullptr)
            : element(value),
              left(nullptr),
              right(nullptr),
              parent(p)
        {
        }
    };

public:
    class iterator
    {
        friend class BinarySearchTree<Comparable>;

    private:
        BinaryNode* current;

        explicit iterator(BinaryNode* node)
            : current(node)
        {
        }

    public:
        iterator()
            : current(nullptr)
        {
        }

        const Comparable& operator*() const
        {
            return current->element;
        }

        const Comparable* operator->() const
        {
            return &current->element;
        }

        iterator& operator++()
        {
            if (current == nullptr)
                return *this;

            // Case 1:
            // højre subtree findes.
            if (current->right != nullptr)
            {
                current = current->right;

                while (current->left != nullptr)
                    current = current->left;
            }

            // Case 2:
            // intet right subtree.
            else
            {
                BinaryNode* parent = current->parent;

                while (parent != nullptr &&
                       current == parent->right)
                {
                    current = parent;
                    parent = parent->parent;
                }

                current = parent;
            }

            return *this;
        }

        iterator operator++(int)
        {
            iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const iterator& rhs) const
        {
            return current == rhs.current;
        }

        bool operator!=(const iterator& rhs) const
        {
            return !(*this == rhs);
        }
    };


    BinarySearchTree()
        : root(nullptr),
          nodeCount(0)
    {
    }


    // Deep-copy constructor
    BinarySearchTree(const BinarySearchTree& rhs)
        : root(clone(rhs.root, nullptr)),
          nodeCount(rhs.nodeCount)
    {
    }


    ~BinarySearchTree()
    {
        makeEmpty(root);
    }


    BinarySearchTree& operator=(const BinarySearchTree& rhs)
    {
        if (this != &rhs)
        {
            BinarySearchTree copy(rhs);
            swap(copy);
        }

        return *this;
    }


    void swap(BinarySearchTree& other) noexcept
    {
        std::swap(root, other.root);
        std::swap(nodeCount, other.nodeCount);
    }


    bool isEmpty() const
    {
        return root == nullptr;
    }


    std::size_t size() const
    {
        return nodeCount;
    }


    // Iterator to smallest element
    iterator begin() const
    {
        return iterator(findMin(root));
    }


    // end() is represented by nullptr
    iterator end() const
    {
        return iterator(nullptr);
    }


    iterator find(const Comparable& x) const
    {
        BinaryNode* current = root;

        while (current != nullptr)
        {
            if (x < current->element)
            {
                current = current->left;
            }
            else if (current->element < x)
            {
                current = current->right;
            }
            else
            {
                return iterator(current);
            }
        }

        return end();
    }


    // Inserts x or returns iterator to existing duplicate.
    iterator insert(const Comparable& x)
    {
        bool inserted = false;

        BinaryNode* node =
            insert(x, root, nullptr, inserted);

        if (inserted)
            ++nodeCount;

        return iterator(node);
    }


    bool remove(const Comparable& x)
    {
        bool removed = remove(x, root);

        if (removed)
            --nodeCount;

        return removed;
    }


private:
    BinaryNode* root;
    std::size_t nodeCount;


    static BinaryNode* findMin(BinaryNode* node)
    {
        if (node == nullptr)
            return nullptr;

        while (node->left != nullptr)
            node = node->left;

        return node;
    }


    static BinaryNode* insert(const Comparable& x,
                              BinaryNode*& node,
                              BinaryNode* parent,
                              bool& inserted)
    {
        if (node == nullptr)
        {
            node = new BinaryNode(x, parent);
            inserted = true;
            return node;
        }

        if (x < node->element)
        {
            return insert(x,
                          node->left,
                          node,
                          inserted);
        }

        if (node->element < x)
        {
            return insert(x,
                          node->right,
                          node,
                          inserted);
        }

        // Duplicate:
        // return existing node without inserting.
        return node;
    }


    static bool remove(const Comparable& x,
                       BinaryNode*& node)
    {
        if (node == nullptr)
            return false;

        if (x < node->element)
        {
            return remove(x, node->left);
        }

        if (node->element < x)
        {
            return remove(x, node->right);
        }

        // Element found.

        // Case: two children
        if (node->left != nullptr &&
            node->right != nullptr)
        {
            BinaryNode* successor =
                findMin(node->right);

            node->element = successor->element;

            return remove(successor->element,
                          node->right);
        }

        // Case: zero or one child
        BinaryNode* oldNode = node;

        BinaryNode* child =
            (node->left != nullptr)
                ? node->left
                : node->right;

        node = child;

        if (child != nullptr)
            child->parent = oldNode->parent;

        delete oldNode;

        return true;
    }


    static void makeEmpty(BinaryNode*& node)
    {
        if (node == nullptr)
            return;

        makeEmpty(node->left);
        makeEmpty(node->right);

        delete node;
        node = nullptr;
    }


    static BinaryNode* clone(BinaryNode* node,
                             BinaryNode* parent)
    {
        if (node == nullptr)
            return nullptr;

        BinaryNode* copy =
            new BinaryNode(node->element, parent);

        copy->left =
            clone(node->left, copy);

        copy->right =
            clone(node->right, copy);

        return copy;
    }
};