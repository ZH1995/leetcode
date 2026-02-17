#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

/*

思路：建立两个哈希表，分别表示两个映射关系。
     注意二者长度的关系。

*/
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size(), i = 0;
        unordered_map<char, string> hash;
        unordered_map<string, char> sp;
        istringstream ss(s);
        string word;
        while (ss >> word) {
            if (hash.count(pattern[i]) && hash[pattern[i]] != word) return false;
            if (sp.count(word) && sp[word] != pattern[i]) return false;
            hash[pattern[i]] = word;
            sp[word] = pattern[i];
            i++;
            if (i > n) return false;
        }
        if (i < n) return false;
        return true;
    }
};

int main() {
    //string pattern = "abba", s = "dog cat cat dog";
    //string pattern = "abba", s = "dog cat cat fish";
    //string pattern = "abba", s = "dog dog dog dog"; 
    string pattern = "a", s = "dog cat";
    Solution sol;
    bool ans = sol.wordPattern(pattern, s);
    cout << ans << endl;
    return 0; 
}