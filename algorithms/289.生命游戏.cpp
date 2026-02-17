#include <iostream>
#include <vector>
using namespace std;

/*

思路：用-1表示活变死，2表示死变活。第一次遍历标记特殊值，第二次遍历还原。
     注意第一次遍历的时候值为1或者-1都代表原来是活的。
     八个方向可以使用二维数组，代码更优雅。

*/
class Solution {
public:
    /*
    // 解法一：
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                int count = 0;
                if ( (i-1) >= 0 && (board[i-1][j] == 1 || board[i-1][j] == -1)) count ++;
                if ( (i+1) < n && (board[i+1][j] == 1 || board[i+1][j] == -1)) count ++;
                if ( (j-1) >= 0 && (board[i][j-1] == 1 || board[i][j-1] == -1)) count ++;
                if ( (j+1) < m && (board[i][j+1] == 1 || board[i][j+1] == -1)) count ++;
                if ( (i-1) >= 0 && (j-1) >= 0 && (board[i-1][j-1] == 1 || board[i-1][j-1] == -1)) count ++;
                if ( (i-1) >= 0 && (j+1) < m && (board[i-1][j+1] == 1 || board[i-1][j+1] == -1)) count ++;
                if ( (i+1) < n && (j-1) >= 0 && (board[i+1][j-1] == 1 || board[i+1][j-1] == -1)) count ++;
                if ( (i+1) < n && (j+1) < m && (board[i+1][j+1] == 1 || board[i+1][j+1] == -1)) count ++;
                if (board[i][j] == 1) {
                    if (count < 2 || count > 3) {
                        board[i][j] = -1;
                    }
                } else if (board[i][j] == 0) {
                    if (count == 3) {
                        board[i][j] = 2;
                    }
                }
            }
        }
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (board[i][j] == 2) board[i][j] = 1;
                else if (board[i][j] == -1) board[i][j] = 0; 
            }
        }
    }
    */
    // 解法二：
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        int dirs[8][2] = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1},
            {-1, -1}, {-1, 1}, {1, 1}, {1, -1}
        };
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                int count = 0;
                for (int d = 0; d < 8; d ++) {
                    int ni = i + dirs[d][0], nj = j + dirs[d][1];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && 
                        (board[ni][nj] == 1 || board[ni][nj] == -1)) {
                        count ++;
                    }
                }
                if (board[i][j] == 1) {
                    if (count < 2 || count > 3) board[i][j] = -1;
                } else if (board[i][j] == 0) {
                    if (count == 3) board[i][j] = 2;
                }
            }
        }
        for (int i = 0; i < n ; i ++) {
            for (int j = 0; j < m; j ++) {
                if (board[i][j] == 2) board[i][j] = 1;
                else if (board[i][j] == -1) board[i][j] = 0;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    }; 
    Solution sol;
    sol.gameOfLife(matrix);
    for (int i = 0; i < matrix.size(); i ++) {
        for (int j = 0; j < matrix[0].size(); j ++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0; 
}