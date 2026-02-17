#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/*

思路：先用哈希表记录下s中出现的字符及个数，然后遍历t，每次自减计数，如果减到小于0，则返回false。
     最后遍历哈希表，如果发现计数非0，则返回false，反之返回true。

推荐：使用wchar_t支持宽字符和Unicode。
*/
class Solution {
public:
    /*
    // 解法一：
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        unordered_map<char, int> hash;
        for (auto c: s) hash[c] ++;
        for (auto c: t) {
            if (--hash[c] < 0) return false;
        }
        for (auto c: s) if (hash[c] != 0) return false;
        return true;
    }
    */
    // 解法二：
    bool isAnagram(string s, string t) {
        unordered_map<wchar_t, int> hash;
        for (auto c: s) hash[c]++;
        for (auto c: t) if (--hash[c] < 0) return false;
        for (auto c: s) if (hash[c] != 0) return false;
        return true;
    }
};

int main() {
    string s = "anagram", t = "nagaram";
    //string s = "rat", t = "car";
    //string s = "ab", t = "a";
    Solution sol;
    bool ans = sol.isAnagram(s, t);
    cout << ans << endl;
    return 0; 
}