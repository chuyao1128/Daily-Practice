//给定一个二维网格和一个单词，找出该单词是否存在于网格中。 
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。 
//
// 
//
// 示例: 
//
// board =
//[
//  ['A','B','C','E'],
//  ['S','F','C','S'],
//  ['A','D','E','E']
//]
//
//给定 word = "ABCCED", 返回 true
//给定 word = "SEE", 返回 true
//给定 word = "ABCB", 返回 false 
//
// 
//
// 提示： 
//
// 
// board 和 word 中只包含大写和小写英文字母。 
// 1 <= board.length <= 200 
// 1 <= board[i].length <= 200 
// 1 <= word.length <= 10^3 
// 
// Related Topics 数组 回溯算法 
// 👍 606 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool backtrack(vector <vector<char>> &board, string word, int index, int i, int j) {
        if (board[i][j] != word[index]) //当前字符不匹配
            return false;
        if (index == word.size() - 1) //最后一个字符也匹配
            return true;
        char temp = board[i][j];
        board[i][j] = 0; //置零以免重复搜索
        index++;
        if ((i > 0 && backtrack(board, word, index, i - 1, j)) || //往上
            (i < board.size() - 1 && backtrack(board, word, index, i + 1, j)) || //往下
            (j > 0 && backtrack(board, word, index, i, j - 1)) || //往左
            (j < board[0].size() - 1 && backtrack(board, word, index, i, j + 1)) //往右
                ) {
            return true; //相邻任一位置匹配即可
        }
        board[i][j] = temp; //撤销选择，恢复状态
        return false;
    }

    bool exist(vector <vector<char>> &board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtrack(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
