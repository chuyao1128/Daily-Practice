//给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
// candidates 中的每个数字在每个组合中只能使用一次。
//
// 说明：
//
//
// 所有数字（包括目标数）都是正整数。
// 解集不能包含重复的组合。
//
//
// 示例 1:
//
// 输入: candidates = [10,1,2,7,6,1,5], target = 8,
//所求解集为:
//[
//  [1, 7],
//  [1, 2, 5],
//  [2, 6],
//  [1, 1, 6]
//]
//
//
// 示例 2:
//
// 输入: candidates = [2,5,2,1,2], target = 5,
//所求解集为:
//[
//  [1,2,2],
//  [5]
//]
// Related Topics 数组 回溯算法
// 👍 378 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> res;

public:
    void backtrack(vector<int> &candidates, int target, int start, vector<int> &track) {
        if (target == 0) {
            res.push_back(track);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (target - candidates[i] < 0) {
                continue;
            }
            if (i > start && candidates[i] == candidates[i - 1]) {//同一递归层级，相同数字只使用一次
                continue;
            }
            track.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, track);
            track.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<int> track;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, track);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
