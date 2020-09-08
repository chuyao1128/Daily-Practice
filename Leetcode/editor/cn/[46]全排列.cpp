//给定一个 没有重复 数字的序列，返回其所有可能的全排列。
//
// 示例:
//
// 输入: [1,2,3]
//输出:
//[
//  [1,2,3],
//  [1,3,2],
//  [2,1,3],
//  [2,3,1],
//  [3,1,2],
//  [3,2,1]
//]
// Related Topics 回溯算法
// 👍 872 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> res;

public:
    void backtrack(vector<int> &nums, vector<int> &track) {
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            auto s = find(track.begin(), track.end(), nums[i]);
            if (s != track.end()) {//track中未找到nums[i]
                continue;
            }
            track.push_back(nums[i]);
            backtrack(nums, track);
            track.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int> &nums) {
        vector<int> track;
        backtrack(nums, track);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
