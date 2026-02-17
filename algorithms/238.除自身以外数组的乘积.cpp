#include <iostream>
#include <vector>
using namespace std;

/*

功能：数组中除当前元素外，其余元素的乘积。

难点：不允许用除法，时间复杂度O(n)。

思路：先从左往右遍历，计算每个元素左侧所有元素的成绩；
     再从右往左遍历，计算每个元素右侧所有元素的乘积；
     最后遍历数组，将每个元素左右侧乘积相乘即可。
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size(), left = 1, right = 1;
        vector<int> ans(len, 1);
        for (int i = 1; i < len; i ++) {
            left *= nums[i-1];
            ans[i] = left;
        }
        for (int i = len - 2; i >= 0; i --) {
            right *= nums[i+1];
            ans[i] *= right;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1,2,3,4};
    Solution sol;
    vector<int> ans = sol.productExceptSelf(nums);
    for (auto item: ans)
        cout << item << " ";
    cout << endl;
    return 0; 
}