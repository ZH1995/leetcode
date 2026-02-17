#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /* 解法一：时间复杂度O(n)，空间复杂度O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        int size = nums.size();
        for (int i = 0; i < size; i ++) {
            int reqVal = target - nums[i];
            auto it = hash.find(reqVal);
            if (it != hash.end()) {
                return vector<int>{it->second, i};
            }
            hash[nums[i]] = i;
        }
        return vector<int>{};
    }
    */
    /* 解法二：时间复杂度O(n^2)，空间复杂度O(1)
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        for (int i = 0; i < size; i ++) {
            for (int j = i + 1; j < size; j ++) {
                if (nums[i] + nums[j] == target) {
                    return vector<int>{i, j};
                }
            }
        }
        return vector<int>{};
    }
    */
};

void showVector(vector<int>& nums) {
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    Solution s;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> output = s.twoSum(nums, target);
    showVector(output);
}