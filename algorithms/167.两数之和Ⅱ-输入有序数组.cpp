#include <iostream>
#include <vector>
using namespace std;

/*

思路：双指针从两端开始遍历，如果当前两个元素之和等于target，则直接返回；
     如果当前两个元素之和大于target，则右指针减1；
     如果当前两个元素之和小于target，则左指针加1；

*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size(), left = 0, right = n - 1, temp;
        while (left < right) {
            temp = numbers[left] + numbers[right];
            if (temp == target) {
                return vector<int>{left+1, right+1};
            } else if (temp > target) right --;
            else left ++;
        }
        return vector<int>{};
    }
};

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    Solution sol;
    vector<int> ans = sol.twoSum(nums, target);
    for (auto item: ans) cout << item << " ";
    cout << endl;
    return 0; 
}