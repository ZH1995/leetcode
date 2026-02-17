#include <iostream>
#include <vector>
using namespace std;

/*

功能：求股票买卖能获得的最大利润（可以交易多次）。

难点：低买高卖利润才是最高，但是不清除当前是不是低点，也无法知道后面会不会有高点。

思路：遍历数组，只要相邻两个元素后者减前者有利润，就累加起来（有钱就赚）。

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size(), ans = 0;
        for (int i = 1; i < len; i ++)
            ans += (prices[i] > prices[i-1]) ? (prices[i] - prices[i-1]) : 0;
        return ans;
    }
};

int main() {
    //vector<int> nums = {7,1,5,3,6,4};
    vector<int> nums = {1,2,3,4,5};
    Solution sol;
    int k = sol.maxProfit(nums);
    cout << k << endl;
    for (auto item: nums)
        cout << item << " ";
    cout << endl;
    return 0; 
}