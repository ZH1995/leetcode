#include <iostream>
#include <vector>
using namespace std;

/*

思路：如果加的总油数减去消耗的总油数大于等于0，则能够将数组遍历一遍。
    维护cur（累计油量），当累计油量小于0时，起点应该从下一个站点重新开始，
    并且累计油量归零。
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), sum = 0, start = 0, cur = 0, diff;
        for (int i = 0; i < n; i ++) {
            diff = gas[i] - cost[i];
            sum += diff;
            cur += diff;
            if (cur < 0) {
                start = i + 1;
                cur = 0;
            }
        }
        return (sum < 0) ? -1 : start;
    }
};

int main() {
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    // -2 -2 -2 3 3
    Solution sol;
    int ans = sol.canCompleteCircuit(gas, cost);
    cout << ans << endl;
    return 0; 
}