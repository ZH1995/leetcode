#include <iostream>
#include <vector>
using namespace std;

/*

思路：维护四个变量top、bottom、left、right表示当前可遍历的边界，每遍历一圈就收缩一次边界。

*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        vector<int> ans;
        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j ++) ans.push_back(matrix[top][j]);
            ++top;
            for (int i = top; i <= bottom; i ++) ans.push_back(matrix[i][right]);
            --right;
            if (top <= bottom) {
                for (int j = right; j >= left; j --) ans.push_back(matrix[bottom][j]);
                --bottom;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i --) ans.push_back(matrix[i][left]);
                ++left;
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    }; 
    Solution sol;
    vector<int> ans = sol.spiralOrder(matrix);
    for (auto item: ans) cout << item << endl;
    cout << endl;
    return 0; 
}