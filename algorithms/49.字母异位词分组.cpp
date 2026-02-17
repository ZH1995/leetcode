#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // 解法一：时间复杂度O(nklogk)，空间复杂度O(nk)，n是strs中字符串的数量，k是strs中字符串的最大长度
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (string s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(s);
        }
        vector<vector<string>> ret;
        for (auto it : hash) {
            ret.push_back(it.second);
        }
        return ret;
    }
};

void showOutput(vector<vector<string>> strs) {
    for (vector<string> strVec : strs) {
        for (string s : strVec) {
            cout << s << ",";
        }
        cout << endl;
    }
    cout << endl;
}


int main() {
    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> output = s.groupAnagrams(strs);
    showOutput(output);
}