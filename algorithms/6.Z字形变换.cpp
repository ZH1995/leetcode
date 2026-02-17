#include <iostream>
#include <vector>
using namespace std;

/*

思路：用一个数组保存每一行，模拟字符在Z字形上的上下移动，最后按行拼接。
*/
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows == 1 || n <= numRows) return s;
        vector<string> rows(numRows, "");
        int row = 0;
        bool down = true;
        for (int i = 0; i < n; i ++) {
            rows[row] += s[i];
            if (row == 0) down = true;
            else if (row == numRows - 1) down = false;
            if (down) row += 1;
            else row -= 1;
        }
        string ans = "";
        for (int i = 0; i < numRows; i ++) {
            ans += rows[i];
        }
        return ans;
    }
};

int main() {
    string s = "PAYPALISHIRING";
    int numRows = 3;
    Solution sol;
    string ans = sol.convert(s, numRows);
    cout << ans << endl;
    return 0; 
}