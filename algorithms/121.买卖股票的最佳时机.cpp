#include <iostream>
#include <vector>
using namespace std;

/*

功能：求股票买卖能获得的最大利润。

难点：低买高卖利润才是最高，但是不清除当前是不是低点，也无法知道后面会不会有高点。
     注意股票只能交易一次！！！

思路：遍历数组，维护当前所遍历到的最小价格（作为买入点），然后比较如果今天卖出的话，是否利润最大。

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int ans = 0, minPrice = prices[0];
        for (int i = 1; i < len; i ++) {
            ans = max(ans, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return ans;
    }
};

int main() {
    //vector<int> nums = {7,1,5,3,6,4};
    vector<int> nums = {7,6,4,3,1};
    Solution sol;
    int k = sol.maxProfit(nums);
    cout << k << endl;
    for (auto item: nums)
        cout << item << " ";
    cout << endl;
    return 0; 
}