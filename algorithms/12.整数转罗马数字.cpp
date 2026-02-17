#include <iostream>
#include <vector>
using namespace std;

/*

注意：unordered_map是无序的，本题要用贪心思想，从大到小遍历；
     如果用map的话（默认从小到大排序），需要声明比较规则（map<int, string, greater<int>>）。

思路：预处理一个从大到小的数值-罗马数字对照表，每次用最大的罗马数字去拼接，直到num变为0。
*/
class Solution {
public:
    string intToRoman(int num) {
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {
            "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V",
            "IV", "I"};
        int n = values.size();
        string ans = "";
        for (int i = 0; i < n; i ++) {
            while (num >= values[i]) {
                num -= values[i];
                ans += symbols[i];
            }
        }
        return ans;
    }
};

int main() {
    int num = 3749;
    Solution sol;
    string ans = sol.intToRoman(num);
    cout << ans << endl;
    return 0; 
}