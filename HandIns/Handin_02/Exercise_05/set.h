#ifndef SET_H
#define SET_H
#include <stack>
#include <stdexcept>

template <typename T>
class set
{
private:
    std::stack<T> data;
    std::stack<T> temp;

    bool foundItem(const T &x)
    {
        bool found = false;
        while (!data.empty())
        {
            if (x == data.top())
            {
                found = true;
            }
            temp.push(data.top());
            data.pop();
        }
        while (!temp.empty())
        {
            data.push(temp.top());
            temp.pop();
        }
        return found;
    }

public:
    void addItem(const T &x)
    {
        if (!foundItem(x))
        {
            data.push(x);
        }
    }

    void removeItem(const T &x)
    {
        while (!data.empty())
        {
            if (!(x == data.top()))
            {
                temp.push(data.top());
                data.pop();
            }
            else
            {
                data.pop();
            }
        }
        while (!temp.empty())
        {
            data.push(temp.top());
            temp.pop();
        }
    }

    bool contains(const T &x)
    {
        return foundItem(x);
    }
};

#endif