#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*

思路：遍历字符串数组，对每一个字符串排序。通过哈希表记录已排序字符串对应的原字符串数组，最后遍历一下哈希表即可。

*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hash;
        for (int i = 0; i < n; i ++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            hash[temp].push_back(strs[i]);
        }
        for (auto& item: hash) {
            ans.push_back(item.second);
        }
        return ans;
    }
};

int main() {
    //vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    //vector<string> strs = {""};
    vector<string> strs = {"a"};
    Solution sol;
    vector<vector<string>> ans = sol.groupAnagrams(strs);
    for (auto vec: ans) {
        for (auto item: vec)
            cout << item << " ";
        cout << endl;
    }    
    return 0; 
}