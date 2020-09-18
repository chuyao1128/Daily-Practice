//给定一个可包含重复数字的序列，返回所有不重复的全排列。 
//
// 示例: 
//
// 输入: [1,1,2]
//输出:
//[
//  [1,1,2],
//  [1,2,1],
//  [2,1,1]
//] 
// Related Topics 回溯算法 
// 👍 434 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector <vector<int>> res;
    vector<bool> visited;
public:
    void backtrack(vector<int> &nums, vector<int> &track) {
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // visited[i - 1] == true，说明同一树支nums[i - 1]使用过
            // visited[i - 1] == false，说明同一树层nums[i - 1]使用过
            // 如果同一树层nums[i - 1]使用过则直接跳过
            if ((i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) || visited[i])
                continue;
            visited[i] = true;
            track.push_back(nums[i]);
            backtrack(nums, track);
            visited[i] = false;
            track.pop_back();
        }
    }

    vector <vector<int>> permuteUnique(vector<int> &nums) {
        if (nums.size() == 0)
            return {};
        sort(nums.begin(), nums.end());
        visited.resize(nums.size(), false);
        vector<int> track;
        backtrack(nums, track);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
