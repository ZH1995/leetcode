#include <iostream>
#include <unordered_map>
using namespace std;

/*

思路：用-1表示活变死，2表示死变活。第一次遍历标记特殊值，第二次遍历还原。
     注意第一次遍历的时候值为1或者-1都代表原来是活的。
     八个方向可以使用二维数组，代码更优雅。

*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size(), m = magazine.size();
        unordered_map<char, int> hash;
        for (int i = 0; i < m; i ++) hash[magazine[i]] ++;
        for (int i = 0; i < n; i ++) {
            if (!hash.count(ransomNote[i])) {
                return false;
            } else {
                hash[ransomNote[i]] --;
                if (hash[ransomNote[i]] < 0) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    //string ransomNote = "a", magazine = "b";
    string ransomNote = "aa", magazine = "aab";
    Solution sol;
    bool ans = sol.canConstruct(ransomNote, magazine);
    cout << ans << endl;
    return 0; 
}