#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /* 解法一：时间复杂度O(nlogn),空间复杂度O(logn)（排序的递归栈空间）
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if (size <= 0) return 0;
        sort(nums.begin(), nums.end());
        int idx = 1, maxLen = 1, len = 1;
        while (idx < size) {
            if (nums[idx] - nums[idx-1] <= 1) {
                if (nums[idx] - nums[idx-1] == 1)
                    len ++;
            } else {
                maxLen = max(maxLen, len);
                len = 1;
            }
            idx ++;
        }
        maxLen = max(maxLen, len);
        return maxLen;
    }
    */

    // 解法二：时间复杂度O(n)，空间复杂度O(n)
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if (size <= 0) return 0;
        unordered_set<int> st(nums.begin(), nums.end());
        int maxLen = 1;
        for (int x : st) {
            if (!st.count(x-1)) {
                int len = 1;
                while (st.count(x+1)) {
                    x ++;
                    len ++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};

int main() {
    Solution s;
    //vector<int> nums = {1, 0, 1, 2};
    //vector<int> nums = {100,4,200,1,3,2};
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    cout << s.longestConsecutive(nums) << endl;
}