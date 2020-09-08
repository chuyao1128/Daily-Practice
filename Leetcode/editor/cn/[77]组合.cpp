//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
//
// 示例:
//
// 输入: n = 4, k = 2
//输出:
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//]
// Related Topics 回溯算法
// 👍 362 👎 0

//回溯算法模板
//result = []
//def backtrack(路径, 选择列表):
//    if 满足结束条件:
//        result.add(路径)
//        return
//    for 选择 in 选择列表:
//        做选择
//        backtrack(路径, 选择列表)
//        撤销选择

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> res;

public:
    void backtrack(int n, int k, int start, vector<int> &track) {
        if (k == track.size()) {//到达树的底部
            res.push_back(track);
            return;
        }
        for (int i = start; i <= n; i++) {
            track.push_back(i);           //选择
            backtrack(n, k, i + 1, track);//回溯
            track.pop_back();             //撤销选择
        }
    }
    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || k <= 0)
            return res;
        vector<int> track;
        backtrack(n, k, 1, track);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
