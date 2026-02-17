#include <iostream>
#include <unordered_map>
using namespace std;

/*

思路：建立两个哈希表，分别表示s->t、t->s的映射关系。

*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size(), m = t.size();
        unordered_map<char, char> st, ts;
        for (int i = 0; i < n; i ++) {
            if (st.count(s[i]) && st[s[i]] != t[i]) return false;
            if (ts.count(t[i]) && ts[t[i]] != s[i]) return false;
            st[s[i]] = t[i];
            ts[t[i]] = s[i];
        }
        return true;
    }
};

int main() {
    //string s = "paper", t = "title";
    //string s = "foo", t = "bar";
    string s = "badc", t = "baba";
    Solution sol;
    bool ans = sol.isIsomorphic(s, t);
    cout << ans << endl;
    return 0; 
}