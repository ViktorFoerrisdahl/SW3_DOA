#include <iostream>
#include <queue>

template <typename T>
class QueueSet {
private:
    std::queue<T> q;

public:
    // Default constructor
    QueueSet() = default;

    // Checks if an element exists in the set
    bool contains(const T& element) {
        bool found = false;
        size_t n = q.size();

        // Full rotation to inspect each element while preserving original order
        for (size_t i = 0; i < n; ++i) {
            T item = q.front();
            q.pop();

            if (item == element) {
                found = true;
            }

            q.push(item); // Rotate back to rear
        }

        return found;
    }

    // Inserts an element only if it is not already present
    bool add(const T& element) {
        if (!contains(element)) {
            q.push(element);
            return true;
        }
        return false;
    }

    // Removes an element from the set if present
    bool remove(const T& element) {
        if (!contains(element)) {
            return false;
        }

        size_t n = q.size();
        for (size_t i = 0; i < n; ++i) {
            T item = q.front();
            q.pop();

            // Re-enqueue everything EXCEPT the target element
            if (item != element) {
                q.push(item);
            }
        }

        return true;
    }

    // Returns current size of the set
    size_t size() const {
        return q.size();
    }

    // Checks if the set is empty
    bool is_empty() const {
        return q.empty();
    }

    // Returns a new QueueSet representing the union of this set and otherSet
    QueueSet<T> set_union(QueueSet<T>& otherSet) {
        QueueSet<T> resultSet;

        // Copy elements from this set
        size_t n1 = q.size();
        for (size_t i = 0; i < n1; ++i) {
            T item = q.front();
            q.pop();
            resultSet.add(item);
            q.push(item);
        }

        size_t n2 = otherSet.q.size();
        for (size_t i = 0; i < n2; ++i) {
            T item = otherSet.q.front();
            otherSet.q.pop();
            resultSet.add(item);
            otherSet.q.push(item);
        }

        return resultSet;
    }

  
    void print() {
        std::cout << "{ ";
        size_t n = q.size();
        for (size_t i = 0; i < n; ++i) {
            T item = q.front();
            q.pop();
            std::cout << item << (i == n - 1 ? "" : ", ");
            q.push(item);
        }
        std::cout << " }\n";
    }
};

int main() {
    QueueSet<int> setA;

    // Test add and duplicate prevention
    setA.add(10);
    setA.add(20);
    setA.add(30);
    setA.add(20); // Duplicate, will not be added

    std::cout << "Set A: ";
    setA.print(); // Output: { 10, 20, 30 }

    // Test removal
    setA.remove(20);
    std::cout << "Set A after removing 20: ";
    setA.print(); // Output: { 10, 30 }

    // Test union
    QueueSet<int> setB;
    setB.add(30);
    setB.add(40);
    setB.add(50);

    QueueSet<int> setC = setA.set_union(setB);
    std::cout << "Union of A and B: ";
    setC.print(); // Output: { 10, 30, 40, 50 }

    return 0;
}