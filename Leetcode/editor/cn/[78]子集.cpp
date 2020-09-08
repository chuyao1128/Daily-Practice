//给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
//
// 说明：解集不能包含重复的子集。
//
// 示例:
//
// 输入: nums = [1,2,3]
//输出:
//[
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
//  [1,2],
//  []
//]
// Related Topics 位运算 数组 回溯算法
// 👍 740 👎 0

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
    void backtrack(vector<int> &nums, int start, vector<int> &track) {
        res.push_back(track);
        for (int i = start; i < nums.size(); i++) {
            track.push_back(nums[i]);     //做选择
            backtrack(nums, i + 1, track);//回溯
            track.pop_back();             //撤销选择
        }
    }
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<int> track;//记录走过的路径
        backtrack(nums, 0, track);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
