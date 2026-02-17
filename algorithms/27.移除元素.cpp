#include <iostream>
#include <vector>
using namespace std;

/*

功能：原地删除数组中的指定元素，返回数组中非指定元素的个数

难点：
    1.若数组本身就是空的话，k应该返回0；
    2.右指针往左遍历的时候，注意不要越界（例如： nums = {3,3},  val=3）

思路：利用双指针的思想，从两边向中间遍历。
    若当前元素非指定元素，则计数器自增、左指针向右遍历；
    若当前元素是指定元素，则右指针向左遍历到第一个非指定元素的位置（注意下表不能越界），然后交换两个元素。
    最后需要特判left=right情况下，是否和指定元素相等。

推荐：快慢指针法，更加简洁高效。
*/
class Solution {
public:
    /*
    // 解法一：双指针
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size(), k = 0, left = 0, right = len -1;
        if (len <= 0) return 0;
        while (left < right) {
            if (nums[left] != val) {
                k ++;
                left ++;
            } else {
                while (right >= 0 && nums[right] == val) right --;
                if (left < right) {
                    swap(nums[left], nums[right]);
                    k ++;
                    left ++;
                    right --;
                }
            }
        }
        if (nums[left] != val) k++; 
        return k;
    }
    */
    // 解法二：快慢指针
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size(), fast = 0, slow = 0;
        for (fast = 0; fast < len; fast ++) {
            if (nums[fast] != val)
                nums[slow ++] = nums[fast];
        }
        return slow;
    }
};

int main() {
    //vector<int> nums = {0,1,2,2,3,0,4,2};
    //int val = 2;
    vector<int> nums = {2,3,3};
    int val = 3;
    Solution sol;
    int k = sol.removeElement(nums, val);
    cout << k << endl;
    for (auto item: nums)
        cout << item << " ";
    cout << endl;
    return 0; 
}