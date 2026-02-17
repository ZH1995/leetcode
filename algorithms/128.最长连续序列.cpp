#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*

思路：首先把数组中的所有元素放进哈希表，然后遍历哈希表。若num-1不在哈希表中，
     则说明num是连续序列的第一个数字，此时统计最多能构成的【连续】序列，并更新最大长度。

*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxLen = 0;
        for (int num: s) {
            if (!s.count(num - 1)) {
                int cur = num;
                int len = 1;
                while (s.count(cur + 1)) {
                    cur ++;
                    len ++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};

int main() {
    // 1 2 3 4 100 200
    //vector<int> nums = {100,4,200,1,3,2};
    vector<int> nums = {4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3};
    Solution sol;
    int ans = sol.longestConsecutive(nums);
    cout << ans << endl; 
    return 0; 
}