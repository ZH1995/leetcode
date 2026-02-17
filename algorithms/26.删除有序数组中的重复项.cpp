#include <iostream>
#include <vector>
using namespace std;

/*

功能：原地删除数组中的所有重复元素，返回数组中不重复的元素个数

思路：借鉴快慢指针的思想，快指针遍历数组，慢指针遍历不重复数组的下标。
     注意遍历过程中需要保存前一个数的值，以和当前数判断是否为重复元素。

推荐：也是快慢指针，但是更简洁。
     从下标1开始遍历，若相邻两个数不相等，则更新慢指针。
*/
class Solution {
public:
    /*
    #define INT_MAX 2147483647
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size(), slow = 0, fast = 0, prev = INT_MAX;
        for (fast = 0; fast < len; fast ++) {
            if (prev == INT_MAX) {
                prev = nums[fast];
                nums[slow++] = nums[fast];
            } else if (prev != nums[fast]) {
                prev = nums[fast];
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
    */
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int len = nums.size(), slow = 1, fast = 1;
        for (fast = 1; fast < len; fast ++) {
            if (nums[fast] != nums[fast-1]) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    Solution sol;
    int k = sol.removeDuplicates(nums);
    cout << k << endl;
    for (auto item: nums)
        cout << item << " ";
    cout << endl;
    return 0; 
}