#include <iostream>
#include <vector>
using namespace std;

/*

功能：能够从数组首元素跳到数组尾元素。

难点：当前元素只代表了能跳跃的最大长度，但是具体跳多少不知道。

思路：维护一个maxReach（当前能到达的最远下标），只要maxReach能覆盖到最后一个下标就返回true，否则返回false。

*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size(), i = 0, maxReach = 0;
        while (i < len) {
            if (i > maxReach) {
                return false;
            }
            maxReach = max(maxReach, i + nums[i]);
            i ++;
        }
        return true;
    }
};

int main() {
    //vector<int> nums = {2,3,1,1,4};
    vector<int> nums = {3,2,1,0,4};
    Solution sol;
    bool ans = sol.canJump(nums);
    cout << ans << endl;
    for (auto item: nums)
        cout << item << " ";
    cout << endl;
    return 0; 
}