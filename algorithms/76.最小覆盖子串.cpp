#include <iostream>
#include <unordered_map>
using namespace std;

/*

思路：采用滑动窗口方法，统计t中每个字符出现的次数，每次将s[right]加入窗口。如果该字符在t中，
     更新window计数，并在window[c]恰好等于needle[c]时，valid++。
     当窗口已经包含t所有字符时，尝试收缩窗口。如果当前窗口更短，更新最小长度和起始位置。
     移除s[left]，如果该字符在t中且移除后数量不在满足要求，则valid--。

*/
class Solution {
public:
    #define INT_MAX 2147483647
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        unordered_map<char, int> needle, window;
        for (auto item: t) needle[item]++;
        int left = 0, right = 0, valid = 0, start = 0, minLen = INT_MAX;
        while (right < n) {
            char c = s[right];
            right ++;
            if (needle.count(c)) {
                window[c] ++;
                if (window[c] == needle[c])
                    valid += 1;
            }
            while (valid == needle.size()) {
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }
                char d = s[left];
                left ++;
                if (needle.count(d)) {
                    if (window[d] == needle[d]) {
                        valid --;
                    }
                    window[d] --;
                }
            }
        }
        if (minLen == INT_MAX) return "";
        else return s.substr(start, minLen);
    }
};

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    Solution sol;
    string ans = sol.minWindow(s, t);
    cout << ans << endl;
    return 0; 
}