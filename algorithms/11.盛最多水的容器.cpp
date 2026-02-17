#include <iostream>
#include <vector>
using namespace std;

/*

思路：采用双指针法，从两端向中间移动，每次计算当前能盛的水量并更新最大值。

*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, ans = 0;
        while (left < right) {
            ans = max(ans, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) {
                left ++;
            } else {
                right --;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1,8,6,2,5,4,8,3,7};
    //vector<int> nums = {1,1};
    Solution sol;
    int ans = sol.maxArea(nums);
    cout << ans << endl;
    return 0; 
}