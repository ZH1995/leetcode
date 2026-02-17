#include <iostream>
#include <vector>
using namespace std;

/*

功能：数组中重复元素最多只允许出现两次，返回新数组中元素的个数。

难点：重复元素最多允许出现两次，需要计数器。

思路：借鉴快慢指针的思想，快指针遍历数组，慢指针遍历不重复数组的下标。
     每次相邻的两个元素做比较，注意记录重复元素出现的次数。

推荐：只要当前位置前面连续两个元素不是和当前元素一样，就可以写入。
*/
class Solution {
public:
    /*
    // 解法一：快慢指针+计数器
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size(), slow = 1, fast = 1, count = 1;
        for (fast = 1; fast < len; fast ++) {
            if (nums[fast] == nums[fast-1]) {
                if (count < 2) {
                    nums[slow++] = nums[fast];
                    count ++;
                }
            } else {
                count = 1;
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
    */
    // 解法二：快慢指针
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2) return len;
        int fast = 2, slow = 2;
        for (fast = 2; fast < len; fast ++) {
            if (nums[fast] != nums[slow-2]) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    Solution sol;
    int k = sol.removeDuplicates(nums);
    cout << k << endl;
    for (auto item: nums)
        cout << item << " ";
    cout << endl;
    return 0; 
}