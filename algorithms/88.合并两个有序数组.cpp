#include <iostream>
#include <vector>
using namespace std;

/*

功能：把两个递增数组合并成一个递增数组

难点：不允许开辟新的数组空间，新数组存储在第一个数组内

思路：从后往前（从大到小）遍历两个数组，将每次比较中，较大的数放在新数组的尾部。
     当某个数组处理完毕后，将另一个数组的剩余元素直接依次放到新数组中。

*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i];
                i--;
            } else {
                nums1[k--] = nums2[j];
                j--;
            }
        }
        while (i >= 0) {
            nums1[k--] = nums1[i--];
        }
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3, n = 3;
    Solution sol;
    sol.merge(nums1, m, nums2, n);
    for (auto item: nums1)
        cout << item << " ";
    cout << endl;
    return 0; 
}