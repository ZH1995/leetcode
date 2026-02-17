#include <iostream>
using namespace std;

/*

思路：处理掉非数字字母字符，并将大写字母都转为小写。
     最后双指针遍历，检查是否满足回文串的条件。

推荐：使用解法二，更清晰优雅。
*/
class Solution {
public:
    /*
    // 解法一：
    bool isPalindrome(string s) {
        int n = s.size(), i, j, newLen = 0;
        for (int i = 0; i < n; i ++) {
            if (isalpha(s[i])) {
                if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
                s[newLen++] = s[i];
            } else if (isdigit(s[i])) {
                s[newLen++] = s[i];
            }
        }
        for (i = 0, j = newLen - 1; i < j; i ++, j --) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
    */
    // 解法二：
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) i ++;
            while (i < j && !isalnum(s[j])) j --;
            if (tolower(s[i]) != tolower(s[j])) return false;
            i ++;
            j --;
        }
        return true;
    }
};

int main() {
    string s = "A man, a plan, a canal: Panama";
    //string s = "race a car";
    //string s = "0P";
    Solution sol;
    bool ans = sol.isPalindrome(s);
    cout << ans << endl;
    return 0; 
}