#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
    struct Node {
        T obj;
        Node* next = nullptr;
        Node(const T& x) : obj(x) {}
    };
    Node* root = nullptr;
    Node* findAt(int pos) {
        Node* current_node = root;
        for (int i = 0; i < pos; i++) {
            if (current_node == nullptr) {
                return nullptr;
            }
            current_node = current_node->next;
        }
        return current_node;
    };

public:
    T getAt(int pos) {
        return findAt(pos)->obj;
    }
    bool insertAt(const T& obj, int pos) {
        if (pos == 0) {
            Node* node = new Node(obj);
            node->next = root;
            root = node;
            return true;
        } else {
            Node* prev = findAt(pos - 1);
            if (prev == nullptr) {
                return false;
            } else {
                Node* node = new Node(obj);
                node->next = prev->next;
                prev->next = node;
                return true;
            }
        }
    };

    bool insertFirst(const T& obj) {
        return insertAt(obj, 0);
    };

    bool insertLast(const T& obj) {
        Node* curr = root;
        if (root == nullptr) {
            return insertFirst(obj);
        }
        Node* node = new Node(obj);
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = node;
        return true;
    };
    bool deleteAt(int pos) {
        if (pos == 0) {
            return deleteFirst();
        }
        Node* prev = findAt(pos - 1);
        if (prev == nullptr) {
            return false;
        }
        Node* curr = prev->next;

        if (curr == nullptr) {
            return false;
        }
        prev->next = curr->next;
        delete curr;
        return true;
    };
    bool deleteFirst() {
        Node* node = root;
        if (node == nullptr) {
            return false;
        }
        root = node->next;
        delete node;
        return true;
    }
    bool deleteLast() {
        if (root == nullptr) {
            return false;
        }
        Node* curr = root;
        if (root->next == nullptr) {
            root = nullptr;
            delete curr;
            return true;
        }
        Node* prev = nullptr;
        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;
        delete curr;
        return true;
    };

    bool inList(const T& obj) const {
        Node* curr = root;
        while (curr != nullptr) {
            if (curr->obj == obj) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    };

    void printList() const {

        Node* curr = root;
        while (curr != nullptr) {
            cout << curr->obj;
            cout << endl;
            curr = curr->next;
        }
    };

    int size() const {
        int cnt = 0;
        Node* curr = root;
        while (curr != nullptr) {
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = root;
        Node* next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        root = prev;
    };
};


template <typename T>
class Set {
private:
    LinkedList<T> data;
public:
    bool insert(T val) {
        if (data.inList(val)) {
            return false;
        }
        return data.insertLast(val);
    };
    bool contains(T val) {
        return data.inList(val);
    };
    bool remove(T val) {
        if (data.inList(val)) {
            int N = data.size();
            for (int i = 0; i < N; i++) {
                if (data.getAt(i) == val) {
                    data.deleteAt(i);
                    return true;
                }
            }
        }
        return false;
    };
    void printSet() {
        data.printList();
    }
};

int main() {
    Set<int> set;

    for (int i = 0; i < 8; i++) {
        set.insert(i);
    }
    set.printSet();
    set.remove(5);
    set.remove(0);
    cout << endl;
    set.printSet();
    
    set.insert(1);
    cout << endl;
    set.printSet();
}