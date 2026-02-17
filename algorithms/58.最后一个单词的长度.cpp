#include <iostream>
#include <vector>
using namespace std;

/*

思路：从后往前遍历，先过滤掉结尾所有的空格，然后开始计数。接下来遍历到第一个空格出现为止。
     注意遍历过程中数组下标不要越界。
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size(), i = n - 1, ans = 0;
        while (i >= 0 && s[i] == ' ') {
            i --;
        }
        while (i >= 0 && s[i] != ' ') {
            i --;
            ans ++;
        }
        return ans;
    }
};

int main() {
    //string s = "   fly me   to   the moon  ";
    string s = "Hello World";
    Solution sol;
    int ans = sol.lengthOfLastWord(s);
    cout << ans << endl;
    return 0; 
}