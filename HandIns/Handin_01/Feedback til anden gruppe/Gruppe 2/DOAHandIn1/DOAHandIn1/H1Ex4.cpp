#include <vector>
#include <stdexcept>
#include <cassert>

using namespace std;

class MaxHeap
{
public:
    virtual bool isEmpty() const = 0;
    virtual int size() = 0;
    virtual void insert(const int x) = 0;
    virtual const int findMax() const = 0;
    virtual int deleteMax() = 0;
};

// Our implementation
class VectorMaxHeap : public MaxHeap {
private:
    vector<int> data; // Vector containing class data

public:
    // Check if heap is empty
    bool isEmpty() const override {
        return data.empty();
    }

    // Returns number of elements
    int size() override {
        return data.size();
    }

    // Adds element to heap
    void insert(const int x) override {
        data.push_back(x);
    }

    // Finds the maximal value in the heap through iteration
    const int findMax() const override {

        assert(!isEmpty()); // Heap must not be empty

        vector<int>::const_iterator it = data.begin(); // Initialize iteration

        // Set first element of the hap as max value and continue iteration
        int maxVal = *it;
        ++it;

        // Iterate through the entire heap, and update max value accordingly
        while (it != data.end()) {
            if (*it > maxVal) {
                maxVal = *it;
            }
            ++it;
        }

        return maxVal;
    }

    // Find, delete and return max value in heap
    int deleteMax() override {

        assert(!isEmpty()); // Heap must not be empty

        vector<int>::iterator it = data.begin(); // Initialize iterator
        vector<int>::iterator tempMax = it; // Saves address of current max value

        // Set first element of the hap as max value and continue iteration
        int maxVal = *it;
        ++it;

        // Iterate through the entire heap, and update max value accordingly
        // Save address of the maximal value for deletion later
        while (it != data.end()) {
            if (*it > maxVal) {
                maxVal = *it;
                tempMax = it;
            }
            ++it;
        }

        // Delete max value from heap, then return it
        data.erase(tempMax);
        return maxVal;
    }
};