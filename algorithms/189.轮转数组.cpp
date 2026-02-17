#include <iostream>
#include <vector>
using namespace std;

/*

功能：将数组中的元素向右移动k个位置。

难点：数组翻转的技巧。

思路：先整体翻转数组，然后将前k个元素及剩余的元素分别翻转。
    为了防止k大于数组长度，所以先对数组长度求余（保证k的值一定小于数组长度）。

*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k <= 0) return;
        int len = nums.size();
        k %= len;
        reverse(nums, 0, len - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, len - 1);
    }

    void reverse(vector<int>& nums, int left, int right) {
        for (int i = left, j = right; i < j; i ++, j --)
            swap(nums[i], nums[j]);
    }
};

int main() {
    //vector<int> nums = {1,2,3,4,5,6,7};
    //int k = 3;
    vector<int> nums = {-1,-100,3,99};
    int k = 2;
    Solution sol;
    sol.rotate(nums, k);
    for (auto item: nums)
        cout << item << " ";
    cout << endl;
    return 0; 
}