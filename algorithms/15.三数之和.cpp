#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 时间复杂度O(n^2),空间复杂度O(logn)（排序的递归栈空间）
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> ret;
        if (size < 3) return ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 2; i ++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (nums[i] > 0) break;
            int left = i + 1, right = size - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    ret.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left+1]) left ++;
                    while (left < right && nums[right] == nums[right-1]) right --;
                    left ++;
                    right --;
                } else if (sum < 0)
                    left ++;
                else if (sum > 0)
                    right --;
            }
        }
        return ret;
    }
};

void showOutput(vector<vector<int>> nums) {
    for (auto row: nums) {
        for (auto x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution s;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> output = s.threeSum(nums);
    showOutput(output);
}