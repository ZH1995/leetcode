#include <iostream>
#include <vector>
using namespace std;

/*

思路：先转置矩阵，然后再左右翻转每一行。

*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i ++) {
            for (int left = 0, right = m - 1; left < right; left ++, right --) {
                swap(matrix[i][left], matrix[i][right]);
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    }; 
    Solution sol;
    sol.rotate(matrix);
    for (int i = 0; i < matrix.size(); i ++) {
        for (int j = 0; j < matrix[0].size(); j ++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0; 
}