#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*

思路：采用哈希表+双指针的方法，遍历数组时，若当前元素遍历过且满足下标差小于等于k，则返回true。

*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i ++) {
            if (hash.count(nums[i]) && i - hash[nums[i]] <= k) return true;
            hash[nums[i]] = i;
        }
        return false;
    }
};
int main() {
    //vector<int> nums = {1,2,3,1};
    //int k = 3;
    //vector<int> nums = {1,2,3,1,2,3};
    //int k = 2;
    vector<int> nums = {1,0,1,1};
    int k = 1;
    Solution sol;
    bool ans = sol.containsNearbyDuplicate(nums, k);
    cout << ans << endl; 
    return 0; 
}