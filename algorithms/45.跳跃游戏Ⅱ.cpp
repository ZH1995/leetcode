#include <iostream>
#include <vector>
using namespace std;

/*

功能：从数组首元素跳到数组尾元素所需的最少跳跃次数。

难点：没思路。注意当i==len-1时，已经到达终点，不需要再跳。

思路：维护end（本次跳跃的边界）、farthest(最远的边界)；
     当到达end时，需要跳跃一次，并把end更新为farthest。
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size(), end = 0, farthest = 0, jumps = 0;
        for (int i = 0; i < len - 1; i ++) {
            farthest = max(farthest, i + nums[i]);
            if (i == end) {
                jumps += 1;
                end = farthest;
            }
        }
        return jumps;
    }
};

int main() {    
    vector<int> nums = {2,3,0,1,4};
    Solution sol;
    int ans = sol.jump(nums);
    cout << ans << endl;
    for (auto item: nums)
        cout << item << " ";
    cout << endl;
    return 0; 
}