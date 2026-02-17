#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*

思路：采用滑动窗口方法，首先用needle维护单词和每个单词出现的次数，然后遍历左边界。
     如果窗口符合条件（所有单词都出现且个数相同），则记录起始下标。注意暴力解法会超时。

推荐：多路滑动窗口     
*/
class Solution {
public:
    /*
    // 解法一：暴力滑动窗口
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), m = words.size(), k = words[0].size(), len = m * k;
        unordered_map<string, int> needle, window;
        for (auto item: words) needle[item]++;
        vector<int> ans;
        for (int left = 0; left <= (n - len); left ++) {
                      
            window.clear();
            int i = 0;
            for (; i < m; i ++) {
                string item = s.substr(left + i * k, k);                
                if (!needle.count(item)) break;
                window[item]++;
                if (window[item] > needle[item]) break;
            }
            if (i == m) ans.push_back(left);
        }
        return ans;
    }
    */
    // 解法二：多路滑动窗口
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), m = words.size(), k = words[0].size();
        unordered_map<string, int> needle;
        for (auto& w: words) needle[w]++;
        vector<int> ans;
        for (int i = 0; i < k; i ++) {
            unordered_map<string, int> window;
            int left = i, count = 0;
            for (int j = i; j <= n - k; j += k) {
                string word = s.substr(j, k);
                if (needle.count(word)) {
                    window[word] ++;
                    count ++;
                    while (window[word] > needle[word]) {
                        string leftWord = s.substr(left, k);
                        window[leftWord]--;
                        left += k;
                        count --; 
                    }
                    if (count == m) {
                        ans.push_back(left);
                        string leftWord = s.substr(left, k);
                        window[leftWord]--;
                        left += k;
                        count --;
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = j + k;
                }
            }
        }
        return ans;
    }
};

int main() {
    //string s = "barfoothefoobarman";
    //vector<string> words = {"foo","bar"};
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","good"};
    Solution sol;
    vector<int> ans = sol.findSubstring(s, words);
    for (auto item: ans) cout << item << " ";
    cout << endl;
    return 0; 
}