#include <iostream>
#include <vector>
using namespace std;

/*

思路：采用滑动窗口方法，左右指针初始化为0，维护sum记录当前窗口内元素之和。
     若当前窗口元素之和大于等于target，则维护ans取最小值。每次移动窗口左指针，
     注意需要同时维护窗口元素之和（减去原来的首元素）
*/
class Solution {
public:
    #define INT_MAX 2147483647
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0, ans = INT_MAX, sum = 0;
        while (right < n) {
            sum += nums[right];
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left ++;
            }
            right ++;
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};

int main() {
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    Solution sol;
    int ans = sol.minSubArrayLen(target, nums);
    cout << ans << endl;
    return 0; 
}