#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*

功能：实现O(1)时间的插入、删除和随机查找。

难点：只用unordered_set可以剞劂插入和删除，但是没办法O(1)时间内解决查找。

思路：同时使用unordered_map和vector，数组用来解决查找，哈希表用来解决插入和删除。
     注意哈希表中存储数组元素的下标，当插入元素时，直接利用vec.size()-1取得下表；
     当删除元素时，将数组的最后一个元素覆盖到当前要删除的元素位置。
*/
class RandomizedSet {
public:
    unordered_map<int, int> iMap;
    vector<int> vec;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (iMap.count(val)) return false;
        vec.push_back(val);
        iMap[val] = vec.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!iMap.count(val)) return false;
        int idx = iMap[val];
        int lastVal = vec.back();
        vec[idx] = lastVal;
        vec.pop_back();
        iMap[lastVal] = idx;
        iMap.erase(val);
        return true;
    }
    
    int getRandom() {
        int idx = rand() % vec.size(); 
        return vec[idx];
    }
};

int main() {
    RandomizedSet* obj = new RandomizedSet();
    cout << obj->insert(1) << endl;
    cout << obj->remove(2) << endl;
    cout << obj->insert(2) << endl;
    cout << obj->getRandom() << endl;
    cout << obj->remove(1) << endl;
    cout << obj->insert(2) << endl;
    cout << obj->getRandom() << endl;
    return 0; 
}