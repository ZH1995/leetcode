#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*

功能：查找数组中的众数（超过一半的数）。

难点：如何能优化为时间复杂度O(n)，空间复杂度O(1)的算法。

思路：利用哈希表记录数组中每个元素出现的次数。

推荐：投票法，维护一个候选元素和计数器。
     若计数器为0，则将当前元素设置为候选元素；
     若当前元素等于候选元素，则计数器加1，否则减1；
     最后留下的候选元素一定就是数组中的众数（因为它超过半数）。
*/
class Solution {
public:
    /*
    // 解法一：哈希表
    int majorityElement(vector<int>& nums) {
        int len = nums.size(), ans = -1;
        unordered_map<int, int> imap;
        for (int i = 0; i < len; i ++) {
            imap[nums[i]] ++;
            if (imap[ans] < imap[nums[i]])
                ans = nums[i];
        }
        return ans;
    }
    */
    // 解法二：投票法
    int majorityElement(vector<int>& nums) {
        int len = nums.size(), count = 0, candidate = 0;
        for (int i = 0; i < len; i ++) {
            if (count == 0) candidate = nums[i];
            count += (candidate == nums[i]) ? 1 : -1;
        }
        return candidate;
    }
};

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    Solution sol;
    int k = sol.majorityElement(nums);
    cout << k << endl;
    for (auto item: nums)
        cout << item << " ";
    cout << endl;
    return 0; 
}