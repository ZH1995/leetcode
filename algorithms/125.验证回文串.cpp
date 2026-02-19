#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    /* 解法一：时间复杂度O(n),空间复杂度O(n)
    bool isPalindrome(string s) {
        string ret = "";
        for (char c : s) {
            if (isalpha(c) || isdigit(c)) {
                if (isupper(c)) c = tolower(c);
                ret += c;
            }
        }
        int size = ret.size();
        for (int i = 0, j = size - 1; i < j ; i ++, j --)
            if (ret[i] != ret[j])
                return false;
        return true;
    }
    */
    // 解法二：时间复杂度O(n),空间复杂度O(1)
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) left ++;
            while (left < right && !isalnum(s[right])) right --;
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right]))
                    return false;
            }
            left ++;
            right --;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s = "A man, a plan, a canal: Panama";
    cout << sol.isPalindrome(s) << endl;
}