//找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
//
// 说明：
//
//
// 所有数字都是正整数。
// 解集不能包含重复的组合。
//
//
// 示例 1:
//
// 输入: k = 3, n = 7
//输出: [[1,2,4]]
//
//
// 示例 2:
//
// 输入: k = 3, n = 9
//输出: [[1,2,6], [1,3,5], [2,3,4]]
//
// Related Topics 数组 回溯算法
// 👍 169 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> res;

public:
    void backtrack(int k, int n, int start, vector<int> &track) {
        if (track.size() == k && n == 0) {
            res.push_back(track);
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (n - i < 0)
                continue;
            track.push_back(i);
            backtrack(k, n - i, i + 1, track);
            track.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> track;
        backtrack(k, n, 1, track);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
