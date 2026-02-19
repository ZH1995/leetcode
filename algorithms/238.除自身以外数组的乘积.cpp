#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 时间复杂度O(n)，空间复杂度O(n)
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        if (size <= 0) return vector<int>{};
        vector<int> prefix(size + 1, 1), suffix(size + 1, 1), ans;
        for (int i = 0; i < size; i ++) {
            prefix[i+1] = prefix[i] * nums[i]; 
        }
        for (int i = size - 1; i >= 0; i --) {
            suffix[i] = suffix[i+1] * nums[i];
        }
        for (int i = 0; i < size; i ++) {
            ans.push_back(prefix[i] * suffix[i+1]);
        }
        return ans;
    }
};

void showVector(vector<int> nums) {
    for (auto x : nums)
        cout << x << " ";
    cout << endl;
}

int main() {
    Solution s;
    vector<int> nums = {1,2,3,4};
    vector<int> output = s.productExceptSelf(nums);
    showVector(output);
}
