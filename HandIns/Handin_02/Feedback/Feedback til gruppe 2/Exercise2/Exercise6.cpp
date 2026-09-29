#include <iostream>
#include <vector>
#include <utility>
using namespace std;

template <typename K, typename V>
class Dictionary {
private:
    vector<pair<K, V>> data;
public:
    bool insert(const K& key, const V& value) {
        if (contains(key)) {
            return false;
        }
        data.push_back({ key,value });
        return true;
    };
    bool contains(const K& key) const {
        for (auto& p : data) {
            if (p.first == key) {
                return true;
            }
        }
        return false;
    };
    bool remove(const K& key) {
        for (int i = 0; i < data.size(); i++) {
            if (data[i].first == key) {
                data.erase(data.begin() + i);
                return true;
            }
        }
        return false;
    };
    V get(const K& key) const {
        for (auto& p : data) {
            if (p.first == key) {
                return p.second;
            }
        }
    };
};

int main() {
    Dictionary<int, string> dict;
    dict.insert(1, "a");
    dict.insert(55, "AAAA");

    cout << "Dict contains 1? " << dict.contains(1) << endl << endl;
    cout << "What does 1 contain? " << dict.get(1) << endl << endl;
    cout << "Has 1 been removed? " << dict.remove(1) << endl << endl;
    cout << "Dict contains 1? " << dict.contains(1) << endl << endl;


    cout << "Dict contains 55? " << dict.contains(55) << endl << endl;
    cout << "What does 55 contain? " << dict.get(55) << endl << endl;
    cout << "Has 55 been removed? " << dict.remove(55) << endl << endl;
    cout << "Dict contains 55? " << dict.contains(55) << endl << endl;

}