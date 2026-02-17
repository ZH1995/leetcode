#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*

思路：记录数字0出现的行下标和列下标，第二次遍历数据时，只要行下标或列下表出现在哈希表里，就将该位置置为0。

推荐：使用第0行、第0列做标记，注意需要特判第0行和第0列。
*/
class Solution {
public:
    /*
    // 解法一：空间复杂度O(m+n)
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        unordered_set<int> row, col;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (row.count(i) || col.count(j)) matrix[i][j] = 0;
            }
        }
    }
    */
    // 解法二：空间复杂度O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool row0 = false, col0 = false;
        for (int i = 0; i < n; i ++) if (matrix[i][0] == 0) col0 = true;
        for (int j = 0; j < m; j ++) if (matrix[0][j] == 0) row0 = true;
        for (int i = 1; i < n; i ++) {
            for (int j = 1; j < m; j ++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < n; i ++) {
            for (int j = 1; j < m; j ++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
            }
        }
        if (col0) for (int i = 0; i < n; i ++) matrix[i][0] = 0;
        if (row0) for (int j = 0; j < m; j ++) matrix[0][j] = 0;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    }; 
    Solution sol;
    sol.setZeroes(matrix);
    for (int i = 0; i < matrix.size(); i ++) {
        for (int j = 0; j < matrix[0].size(); j ++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0; 
}