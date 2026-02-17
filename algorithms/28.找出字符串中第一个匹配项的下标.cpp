#include <iostream>
using namespace std;

/*

思路：遍历haystack字符串，判断以当前字符作为起点，能否构成needle字符串。
     注意只需要遍历到n-m即可。
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;
        for (int i = 0; i <= n - m; i++) {
            if (haystack.substr(i, m) == needle) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    //string haystack = "sadbutsad";
    //string needle = "sad";
    string haystack = "leetcode";
    string needle = "leeto";
    Solution sol;
    int ans = sol.strStr(haystack, needle);
    cout << ans << endl;
    return 0; 
}