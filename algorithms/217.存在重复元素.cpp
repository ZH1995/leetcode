#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    /* 解法一：时间复杂度O(nlogn)，空间复杂度O(n)
    bool containsDuplicate(vector<int>& nums) { 
        map<int, int> hash;
        for (int x : nums) {
            if (hash.count(x)) {
                return true;
            }
            hash[x] ++;
        }
        return false;
    }
    */

    /* 解法二：时间复杂度O(n)，空间复杂度O(n)
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (int x : nums) {
            // insert返回值为pair<iterator, bool>，插入成功返回true，插入失败返回false
            // 若当前元素在集合中已存在，则插入失败
            if (!set.insert(x).second) return true;
        }
        return false;
    }
    */

    // 解法三：时间复杂度O(nlogn)，空间复杂度O(1)
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i = 0; i < size - 1; i ++) {
            if (nums[i] == nums[i+1]) return true; 
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3, 1};
    bool ret = s.containsDuplicate(nums);
    cout << ret << endl;
}