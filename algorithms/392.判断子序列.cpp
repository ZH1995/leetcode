#include <iostream>
using namespace std;

/*

思路：四个指针分别从首尾两端向中间推进，最后比较下计数器是否和s的长度相等。

推荐：使用解法二，更清晰优雅。
*/
class Solution {
public:
    /*
    // 解法一：
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size(), count = 0;
        if (n > m) return false;
        int ls = 0, rs = n - 1, lt = 0, rt = m - 1;
        while (count != n && lt <= rt) {
            while (lt <= rt && t[lt] != s[ls]) lt ++;
            if (lt <= rt) {
                ls ++;
                count ++;
                lt ++;
            }
            while (lt <= rt && t[rt] != s[rs]) rt --;
            if (lt <= rs) {
                rs --;
                count ++;
                rt --;
            }
        }
        return count == n ? true : false;
    }
    */
    // 解法二：
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size(), i = 0, j = 0;
        while (i < n && j < m) {
            if (s[i] == t[j]) i ++;
            j ++;
        }
        return i == n;
    }
};

int main() {
    //string s = "abc", t = "ahbgdc";
    string s = "axc", t = "ahbgdc";
    Solution sol;
    bool ans = sol.isSubsequence(s, t);
    cout << ans << endl;
    return 0; 
}