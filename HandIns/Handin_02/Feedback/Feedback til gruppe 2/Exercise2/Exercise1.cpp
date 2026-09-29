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

int main() {
    LinkedList<int> intList;
    intList.insertFirst(1);
    intList.insertLast(3);
    intList.insertAt(2, 1);
    intList.printList();
    cout << endl;
    cout << endl;
    for (int i = 4; i <= 10; i++) {
        intList.insertLast(i);
    }

    intList.printList();
    cout << endl << endl;
    cout << "5 in list?" << endl << intList.inList(5) << endl << endl;
    cout << "Delete at 5? " << intList.deleteAt(4) << endl << endl;
    cout << "5 in list?" << endl << intList.inList(5) << endl << endl;

    cout << "10 in list?" << endl << intList.inList(10) << endl << endl;
    cout << "Delete last? " << intList.deleteLast() << endl << endl;
    cout << "10 in list?" << endl << intList.inList(10) << endl << endl;
    cout << "1 in list?" << endl << intList.inList(1) << endl << endl;
    cout << "Delete first? " << intList.deleteFirst() << endl << endl;
    cout << "1 in list?" << endl << intList.inList(1) << endl << endl;

    bool run = true;
    while (run) {
        intList.printList();
        cout << endl;
        run = intList.deleteFirst();
    }
    cout << intList.size();
    cout << endl;
    intList.printList();

    LinkedList<string> stringList;

    stringList.insertFirst("a");
    stringList.insertFirst("b");
    stringList.insertFirst("c");
    stringList.insertFirst("d");
    stringList.insertFirst("e");

    cout << endl;
    stringList.printList();
    stringList.reverse();
    cout << endl;
    stringList.printList();
    cout << endl;

    run = true;
    while (run) {
        stringList.printList();
        cout << endl;
        run = stringList.deleteFirst();
    }
    cout << stringList.size();
    cout << endl;

    stringList.insertLast("a");
    stringList.reverse();
    stringList.insertLast("b");

    cout << endl;
    stringList.printList();
    stringList.reverse();
    cout << endl;
    stringList.printList();
    stringList.insertFirst("c");
    cout << endl;
    stringList.printList();
    stringList.reverse();
    cout << endl;
    stringList.printList();

    return 0;
}