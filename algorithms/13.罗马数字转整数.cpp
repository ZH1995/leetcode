#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*

思路：使用map记录每个字符对应的数组，如果当前字符代表的数字小于下一个字符代表的数字，
     则减去对应的值，反之加上对应的值。
*/
class Solution {
public:
    /*
    // 解法一：
    int romanToInt(string s) {
        int n = s.size(), ans = 0, i = 0;
        unordered_map<string, int> hash = {
            {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50},
            {"C", 100}, {"D", 500}, {"M", 1000}, {"IV", 4},
            {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400},
            {"CM", 900}
        };
        while (i < n) {
            if (i + 1 < n) {
                string temp = "";
                temp += s[i];
                temp += s[i+1];
                if (hash.count(temp)) {
                    ans += hash[temp];
                    i += 2;
                    continue;
                }
            }
            string newTmp = "";
            newTmp += s[i];
            ans += hash[newTmp];
            i ++;
        }
        return ans;
    }
    */
    // 解法二：
    int romanToInt(string s) {
        unordered_map<char, int> hash = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int ans = 0, n = s.size();
        for (int i = 0; i < n; i ++) {
            if (i + 1 < n && hash[s[i]] < hash[s[i+1]]) {
                ans -= hash[s[i]];
            } else {
                ans += hash[s[i]];
            }
        }
        return ans;
    }
};

int main() {
    //string s = "LVIII";
    //string s = "MCMXCIV";
    string s = "IX";
    Solution sol;
    int ans = sol.romanToInt(s);
    cout << ans << endl;
    return 0; 
}