#include <iostream>
#include <vector>
using namespace std;

/*

思路：先求出最小字符串的长度（最多不能超过它），然后开始按照这个长度依次遍历所有字符串。
     如果对于当前下标，所有字符串的字符都相同，则累加到结果上，否则直接返回目前已求得的公共前缀。
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size(), minLen = strs[0].size();
        for (int i = 1; i < n; i ++) {
            minLen = min(minLen, (int)strs[i].size());
        }
        string ans = "";
        for (int j = 0; j < minLen; j ++) {
            char c = strs[0][j];
            for (int i = 1; i < n; i ++) {
                if (strs[i][j] != c) {
                    return strs[0].substr(0, j);
                }
            }
        }
        return strs[0].substr(0, minLen);
    }
};

int main() {
    //vector<string> strs = {"flower","flow","flight"};
    vector<string> strs = {"dog","racecar","car"};
    Solution sol;
    string ans = sol.longestCommonPrefix(strs);
    cout << ans << endl;
    return 0; 
}