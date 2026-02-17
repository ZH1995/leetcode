#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*

思路：根据题意，分别检查每一行、每一列、每一个3*3矩阵中均不出现重复数字。
     注意每个3*3矩阵的遍历方式，外面两层循环（blockRow、blockCol）遍历每个矩阵左上角的坐标，
     再用两层循环（i、j）遍历小矩阵的内部。

*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        unordered_set<char> hash;
        for (int i = 0; i < n; i ++) {
            hash.clear();
            for (int j = 0; j < m; j ++) {
                if (board[i][j] != '.') {
                    if (!hash.count(board[i][j])) hash.insert(board[i][j]);
                    else return false;
                }
            }
        }
        for (int j = 0; j < m; j ++) {
            hash.clear();
            for (int i = 0; i < n; i ++) {
                if (board[i][j] != '.') {
                    if (!hash.count(board[i][j])) hash.insert(board[i][j]);
                    else return false;
                }
            }
        }
        for (int blockRow = 0; blockRow < 3; blockRow ++) {
            for (int blockCol = 0; blockCol < 3; blockCol ++) {
                hash.clear();
                for (int i = 0; i < 3; i ++) {
                    for (int j = 0; j < 3; j ++) {
                        int row = blockRow * 3 + i;
                        int col = blockCol * 3 + j;
                        if (board[row][col] != '.') {
                            if (!hash.count(board[row][col])) hash.insert(board[row][col]);
                            else return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution sol;
    bool ans = sol.isValidSudoku(board);
    cout << ans << endl;
    return 0; 
}