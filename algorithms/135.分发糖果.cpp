#include <iostream>
#include <vector>
using namespace std;

/*

思路：贪心思想，两次遍历。
     第一次从左往右遍历，如果右边孩子分数高于左边，就比左边多分一个糖果；
     第二次从右往左遍历，如果左边孩子分数高于右边，就要保证左边比右边多一个糖果（和第一次的结果取最大值）。
     最后把每个孩子分到的糖果加起来。
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> count(n, 1);
        for (int i = 1; i < n; i ++) {
            if (ratings[i] > ratings[i-1]) {
                count[i] = count[i-1]+1;
            }
        }
        for (int i = n - 2; i >= 0; i --) {
            if (ratings[i] > ratings[i+1]) {
                count[i] = max(count[i], count[i+1]+1);
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i ++) sum += count[i];
        return sum;
    }
};

int main() {
    vector<int> nums = {1,0,2};
    Solution sol;
    int ans = sol.candy(nums);
    cout << ans << endl;
    return 0; 
}