#include <iostream>
#include <unordered_set>
using namespace std;

/*

思路：采用滑动窗口方法，利用unordered_set记录窗口内的字符。右指针每次扩展窗口，
     遇到重复时只移动左指针，直到窗口无重复，每次更新最大长度即可。
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> windows;
        int n = s.size(), left = 0, right = 0, ans = 0;
        while (right < n) {
            while (windows.count(s[right])) {
                windows.erase(s[left]);
                left ++;
            }
            windows.insert(s[right]);
            ans = max(ans, right - left + 1);
            right ++;
        }
        return ans;
    }
};

int main() {
    //string s = "abcabcbb";
    //string s = "bbbb";
    string s = "pwwkew";
    Solution sol;
    int ans = sol.lengthOfLongestSubstring(s);
    cout << ans << endl;
    return 0; 
}