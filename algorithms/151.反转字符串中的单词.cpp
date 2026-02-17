#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

/*

思路：先把所有前导空格都过滤掉，然后遍历字符串，将每次遍历到的单词都存入数组。
     注意需要特判下最后一个单词是否已经存入了数组，接下来逆序遍历数组即可。

推荐：使用stringstream，可以极大地节省代码量。注意需要#include <sstream>
*/
class Solution {
public:
    /*
    // 解法一：C++的string
    string reverseWords(string s) {
        int n = s.size(), i = 0;
        string cur = "", ans = "";
        // 过滤前导空格
        while (i < n && s[i] == ' ') {
            i ++;
        }
        vector<string> vec;
        while (i < n) {
            if (s[i] != ' ') {
                cur += s[i];
            } else {
                if (!cur.empty()) {
                    vec.push_back(cur);
                    cur = "";
                }
            }
            i ++;
        }
        if (!cur.empty()) vec.push_back(cur);
        int m = vec.size();
        for (i = m - 1; i >= 0; i --) {
            ans += vec[i];
            if (i != 0) ans += " ";
        }
        return ans;
    }
    */
    // 解法二：stringstream
    string reverseWords(string s) {
        stringstream ss(s);
        string word, ans;
        vector<string> vec;
        while (ss >> word) vec.push_back(word);
        for (int i = vec.size() - 1; i >= 0; i --) {
            ans += vec[i];
            if (i != 0) ans += " ";
        }
        return ans;
    }
};

int main() {
    //string s = "  hello world  ";
    //string s = "the sky is blue";
    string s = "a good   example";
    Solution sol;
    string ans = sol.reverseWords(s);
    cout << ans << endl;
    return 0; 
}