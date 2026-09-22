#include <iostream>
#include <vector>
#include <utility>   // For std::pair and std::make_pair
#include <string>

template <typename K, typename V>
class VectorMap {
private:
    // Core data structure: vector storing (Key, Value) pairs
    std::vector<std::pair<K, V>> data;

    // Helper: Finds the index of a key. Returns -1 if not found.
    int findIndex(const K& key) const {
        for (size_t i = 0; i < data.size(); ++i) {
            if (data[i].first == key) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }

public:
    VectorMap() = default;

    // Inserts a key-value pair. Updates value if key already exists.
    void insert(const K& key, const V& value) {
        int idx = findIndex(key);
        if (idx != -1) {
            data[idx].second = value; // Update existing key
        }
        else {
            data.push_back(std::make_pair(key, value)); // Insert new pair
        }
    }

    // Retrieves value by key. Throws exception if key doesn't exist.
    V get(const K& key) const {
        int idx = findIndex(key);
        if (idx != -1) {
            return data[idx].second;
        }
        throw std::out_of_range("Key not found in map.");
    }

    // Checks if key exists in the map
    bool contains(const K& key) const {
        return findIndex(key) != -1;
    }

    // Removes a key-value pair if present
    bool remove(const K& key) {
        int idx = findIndex(key);
        if (idx != -1) {
            // Erase the element at position idx
            data.erase(data.begin() + idx);
            return true;
        }
        return false;
    }

    // Returns number of key-value pairs
    size_t size() const {
        return data.size();
    }

    // Checks if map is empty
    bool is_empty() const {
        return data.empty();
    }

    // Overloaded operator[] for convenient key lookup / assignment
    V& operator[](const K& key) {
        int idx = findIndex(key);
        if (idx != -1) {
            return data[idx].second;
        }
        // If key doesn't exist, insert default Value and return reference to it
        data.push_back(std::make_pair(key, V()));
        return data.back().second;
    }

    // Prints all key-value pairs
    void print() const {
        std::cout << "{ ";
        for (size_t i = 0; i < data.size(); ++i) {
            std::cout << "{" << data[i].first << ": " << data[i].second << "}";
            if (i + 1 < data.size()) std::cout << ", ";
        }
        std::cout << " }\n";
    }
};

int main() {
    VectorMap<std::string, int> ageMap;

    // Insert key-value pairs
    ageMap.insert("Alice", 25);
    ageMap.insert("Bob", 30);
    ageMap.insert("Charlie", 22);

    std::cout << "Initial Map: ";
    ageMap.print();

    // Update value for existing key
    ageMap.insert("Alice", 26);
    std::cout << "After updating Alice's age: ";
    ageMap.print();

    // Look up value
    if (ageMap.contains("Bob")) {
        std::cout << "Bob's age: " << ageMap.get("Bob") << "\n";
    }

    // Subscript operator [] lookup and assignment
    ageMap["Diana"] = 28; // Inserts new entry
    std::cout << "After adding Diana with []: ";
    ageMap.print();

    // Remove key
    ageMap.remove("Charlie");
    std::cout << "After removing Charlie: ";
    ageMap.print();

    return 0;
}