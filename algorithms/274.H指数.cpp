#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

功能：找到h指数，至少发表h篇论文，至少h篇论文的引用次数大于等于h。

难点：题目描述得比较绕。

思路：贪心思想，先从小到大排序，然后从后往前遍历数组，查找满足条件的最大h。
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int len = citations.size(), ans = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (citations[i] > ans) {
                ans ++;
            } else {
                break;
            }
        }
        return ans;
    }
};

int main() {
    //vector<int> nums = {3,0,6,1,5};
    vector<int> nums = {1,3,1};
    Solution sol;
    int ans = sol.hIndex(nums);
    cout << ans << endl;
    for (auto item: nums)
        cout << item << " ";
    cout << endl;
    return 0; 
}