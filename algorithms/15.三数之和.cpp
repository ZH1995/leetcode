#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

思路：先排序，然后从0开始遍历第一个数，到n-3为止（如果更大，后面就不够两个数了，无法组成三元组）。
     接下来左指针从i+1开始，右指针从n-1开始。如果三元组和为0，则记录，移动指针时记注意去重。
     如果三元组和小于0，则移动左指针；如果三元组和大于0，则移动右指针。
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i ++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                } else if (sum < 0) left ++;
                else right --;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution sol;
    vector<vector<int>> ans = sol.threeSum(nums);
    for (auto item: ans) {
        for (auto ele: item) {
            cout << ele << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0; 
}