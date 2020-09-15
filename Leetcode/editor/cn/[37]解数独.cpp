//编写一个程序，通过已填充的空格来解决数独问题。
//
// 一个数独的解法需遵循如下规则：
//
//
// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
//
//
// 空白格用 '.' 表示。
//
//
//
// 一个数独。
//
//
//
// 答案被标成红色。
//
// Note:
//
//
// 给定的数独序列只包含数字 1-9 和字符 '.' 。
// 你可以假设给定的数独只有唯一解。
// 给定数独永远是 9x9 形式的。
//
// Related Topics 哈希表 回溯算法
// 👍 560 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int row[9][9];   //行
    int cloumn[9][9];//列
    int block[9][9]; //九宫格

public:
    bool backtrack(vector<vector<char>> &board, int i, int j) {
        if (i > 8)//遍历完最后一行
            return true;
        if (board[i][j] == '.') {
            for (char ch = '1'; ch <= '9'; ch++) {//填数
                if (row[i][ch - '1'] == 1 || cloumn[j][ch - '1'] == 1 || block[(i / 3) * 3 + j / 3][ch - '1'] == 1)
                    continue;//不符合则跳过
                board[i][j] = ch;
                row[i][ch - '1'] = cloumn[j][ch - '1'] = block[(i / 3) * 3 + j / 3][ch - '1'] = 1;//置1表示数字ch已填
                if (backtrack(board, i + (j + 1) / 9, (j + 1) % 9))                               //往后推一个位置，在第i+(j+1)/9行，第(j+1)%9列，找出一组解即可
                    return true;
                // 回溯
                board[i][j] = '.';
                row[i][ch - '1'] = cloumn[j][ch - '1'] = block[(i / 3) * 3 + j / 3][ch - '1'] = 0;
            }
        } else
            return backtrack(board, i + (j + 1) / 9, (j + 1) % 9);
        return false;
    }
    void solveSudoku(vector<vector<char>> &board) {
        memset(row, 0, sizeof(row));
        memset(cloumn, 0, sizeof(cloumn));
        memset(block, 0, sizeof(block));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    row[i][board[i][j] - '1'] = cloumn[j][board[i][j] - '1'] = block[(i / 3) * 3 + j / 3][board[i][j] - '1'] = 1;//已有数字置1
                }
            }
        }
        backtrack(board, 0, 0);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
