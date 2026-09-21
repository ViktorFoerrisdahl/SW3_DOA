#pragma once
#include <vector>
#include <utility>
#include <iostream>

class Dictionary
{
private:
    std::vector<std::pair<int, int>> data;

public:
    void print() const
    {
        for (const auto& entry : data)
            std::cout << entry.first << ": " << entry.second << '\n';
    }

    bool insert(int key, int value) // Add a key-value pair to the dictionary
    {
        for (const auto& entry : data) // check if key already exists
        {
            if (entry.first == key)
            {
                return false;
            }
        }

        data.push_back({key, value});
        return true;
    }


    bool remove(int key) // Remove a key-value and its associated value
    {
        for (auto it = data.begin(); it != data.end(); ++it)
        {
            if (it->first == key)
            {
                data.erase(it);
                return true;
            }
        }

        return false;
    }


    bool get(int key, int& value) const // Retrieve the value associated with a given key.
    {
        for (const auto& entry : data)
        {
            if (entry.first == key)
            {
                value = entry.second;
                return true;
            }
        }

        return false;
    }


    bool update(int key, int newValue) // Change the value associated with a given key
    {
        for (auto& entry : data)
        {
            if (entry.first == key)
            {
                entry.second = newValue;
                return true;
            }
        }

        return false;
    }
};
