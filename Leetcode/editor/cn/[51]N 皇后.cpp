//n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
//
//
//
// 上图为 8 皇后问题的一种解法。
//
// 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
//
// 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
//
//
//
// 示例：
//
// 输入：4
//输出：[
// [".Q..",  // 解法 1
//  "...Q",
//  "Q...",
//  "..Q."],
//
// ["..Q.",  // 解法 2
//  "Q...",
//  "...Q",
//  ".Q.."]
//]
//解释: 4 皇后问题存在两个不同的解法。
//
//
//
//
// 提示：
//
//
// 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
//
// Related Topics 回溯算法
// 👍 564 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

//每个Q的行不能相等，列不能相等，正反对角线不能相等
//正对角线的行与列的差值是相等的，用一个一维数组来存储
//反对角线的行与列的和是相等的，也能用一个一维数组来存储
class Solution {
public:
    vector<vector<string>> res;
    vector<string> board;//棋盘
    vector<int> col;     //列
    vector<int> dg;      //正对角线
    vector<int> adg;     //反对角线

    vector<vector<string>> solveNQueens(int n) {
        board.resize(n, string(n, '.'));
        col.resize(n, 0);
        dg.resize(2 * n, 0);
        adg.resize(2 * n, 0);
        dfs(0, n);
        return res;
    }
    void dfs(int row, int n) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !dg[row - i + n] && !adg[row + i]) {
                col[i] = dg[row - i + n] = adg[row + i] = 1;
                board[row][i] = 'Q';
                dfs(row + 1, n);
                col[i] = dg[row - i + n] = adg[row + i] = 0;
                board[row][i] = '.';
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
