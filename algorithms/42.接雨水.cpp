#include <iostream>
#include <vector>
using namespace std;

/*

思路：
    1.每个位置能接多少水，取决于它左边和右边的最高柱子。
    2.对于每个下标 i，能接的水 = min(左边最高, 右边最高) - 当前高度（如果为正）。
    3.可以先分别预处理出每个位置左边最高和右边最高的高度（用两个数组）。
    4.最后遍历一遍，累加每个位置能接的水。
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; i ++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        rightMax[n-1] = height[n-1];
        for (int i = n - 2; i >= 0; i --) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i ++)
            ans += min(leftMax[i], rightMax[i]) - height[i];
        return ans;
    }
};

int main() {
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution sol;
    int ans = sol.trap(nums);
    cout << ans << endl;
    return 0; 
}