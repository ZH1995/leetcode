#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    /* 解法一： 时间复杂度：O(n)，空间复杂度O(n)
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> ms;
        for (char c : s) {
            ms[c] ++;
        }
        for (char c : t) {
            if (--ms[c] < 0) return false;
        }
        return true;
    }
    */
    // 解法二：时间复杂度O(nlogn)，空间复杂度O(logn)
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

};

int main() {
    Solution sol;
    //string s = "anagram", t = "nagaram";
    //string s = "rat", t = "car";
    //string s = "a", t = "ab";
    string s = "aacc", t = "ccac";
    bool ret = sol.isAnagram(s, t);
    cout << ret << endl;
}