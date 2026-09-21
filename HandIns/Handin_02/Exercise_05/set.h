#ifndef SET_H
#define SET_H
#include <stack>

template <typename T>
class set
{
private:
    std::stack<T> data; // Stack der bruges til at gemme alle værdierne i vores Set
    std::stack<T> temp; // Midlertidig stack der bruges når vi gennemløber data og bagefter skal gendanne rækkefølgen

    /* Gennemløber hele stacken for at undersøge om en bestemt værdi allerede findes.
    Værdierne flyttes midlertidigt over i temp, så data kan gendannes bagefter */
    bool foundItem(const T &x)
    {
        bool found = false;
        while (!data.empty())
        {
            if (x == data.top()) // Hvis værdien findes sættes found til true
            {
                found = true;
            }
            temp.push(data.top()); // Flytter værdien midlertidigt væk så næste element kan undersøges
            data.pop();
        }
        // Gendanner data efter hele stacken er blevet gennemløbet
        while (!temp.empty())
        {
            data.push(temp.top());
            temp.pop();
        }
        return found;
    }

public:
    /* Tilføjer kun værdien hvis den ikke allerede findes,
    da et Set ikke må indeholde duplicates */
    void addItem(const T &x)
    {
        if (!foundItem(x))
        {
            data.push(x);
        }
    }

    /* Gennemløber hele Settet og flytter alle værdier undtagen den der skal fjernes
    over i temp, Derefter gendannes data uden den fjernede værdi. */
    void removeItem(const T &x)
    {
        while (!data.empty())
        {
            if (!(x == data.top())) // Hvis det ikke er værdien der skal fjernes gemmes den midlertidigt
            {
                temp.push(data.top());
                data.pop();
            }
            else // Hvis værdien matcher fjernes den ved ikke at gemme den i temp
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

    // Returnerer true hvis værdien findes i Set ellers false
    bool setContains(const T &x)
    {
        return foundItem(x);
    }

    /* Laver et nyt Set der indeholder alle værdier fra begge Sets
    addItem sørger selv for at duplicates ikke bliver tilføjet */
    set<T> setUnion(set<T> &other)
    {
        set<T> result;
        std::stack<T> tempUnion; // Midlertidig stack der bruges til at gendanne de oprindelige Sets bagefter
        while (!data.empty())    // Tilføjer alle værdier fra det første Set til resultatet
        {
            result.addItem(data.top());
            tempUnion.push(data.top());
            data.pop();
        }
        while (!tempUnion.empty()) // Gendanner det første Set
        {
            data.push(tempUnion.top());
            tempUnion.pop();
        }
        while (!other.data.empty()) // Tilføjer alle værdier fra det andet Set til resultatet
        {
            result.addItem(other.data.top());
            tempUnion.push(other.data.top());
            other.data.pop();
        }
        while (!tempUnion.empty()) // Gendanner det andet Set
        {
            other.data.push(tempUnion.top());
            tempUnion.pop();
        }
        return result;
    }

    // Laver et nyt Set med de værdier som findes i begge Sets
    set<T> setIntersection(set<T> &other)
    {
        set<T> result;
        std::stack<T> tempInter; // Midlertidig stack der bruges til at gendanne det første Set bagefter

        while (!data.empty())
        {
            T value = data.top();
            if (other.setContains(value)) // Tilføjer kun værdien hvis den også findes i det andet Set
            {
                result.addItem(data.top());
            }
            tempInter.push(data.top());
            data.pop();
        }
        while (!tempInter.empty())
        {
            data.push(tempInter.top());
            tempInter.pop();
        }
        return result;
    }

    /* Laver et nyt Set med de værdier som findes i det første Set,
    men ikke findes i det andet Set */
    set<T> setDifference(set<T> &other)
    {
        set<T> result;
        std::stack<T> tempDiff;

        while (!data.empty())
        {
            T value = data.top();
            if (!other.setContains(value)) // Tilføjer kun værdien hvis den ikke findes i det andet Set
            {
                result.addItem(data.top());
            }
            tempDiff.push(data.top());
            data.pop();
        }
        while (!tempDiff.empty())
        {
            data.push(tempDiff.top());
            tempDiff.pop();
        }
        return result;
    }
};

#endif
