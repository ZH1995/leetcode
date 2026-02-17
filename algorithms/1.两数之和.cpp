#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*

思路：遍历数组，同时用哈希表记录已经遍历过数字的下标。如果所求数字不在哈希表中，则添加映射；
     若在哈希表中，则代表找到了，返回即可。

*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i ++) {
            int temp = target - nums[i];
            if (hash.count(temp)) return vector<int>{hash[temp], i};
            hash[nums[i]] = i;
        }
        return vector<int>{};
    }
};

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    Solution sol;
    vector<int> ans = sol.twoSum(nums, target);
    for (auto item: ans) cout << item << " ";        
    cout << endl; 
    return 0; 
}