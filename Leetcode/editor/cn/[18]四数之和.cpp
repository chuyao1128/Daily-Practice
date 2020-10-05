//给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c +
// d 的值与 target 相等？找出所有满足条件且不重复的四元组。
//
// 注意：
//
// 答案中不可以包含重复的四元组。
//
// 示例：
//
// 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
//
//满足要求的四元组集合为：
//[
//  [-1,  0, 0, 1],
//  [-2, -1, 1, 2],
//  [-2,  0, 0, 2]
//]
//
// Related Topics 数组 哈希表 双指针
// 👍 606 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return {};

        sort(nums.begin(), nums.end());
        int n_size = nums.size();

        for (int i = 0; i < n_size - 3; i++) {
            // 不存在
            if (target <= 0 && nums[i] > 0) break;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            // 此时条件不满足
            if (nums[i] + nums[n_size - 3] + nums[n_size - 2] + nums[n_size - 1] < target) continue;
            // 重复项
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n_size - 2; j++) {
                // 不存在
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                // 此时条件不满足
                if (nums[i] + nums[j] + nums[n_size - 2] + nums[n_size - 1] < target) continue;
                // 重复项
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int start = j + 1, end = n_size - 1;
                while (start < end) {
                    int sum = nums[i] + nums[j] + nums[start] + nums[end];
                    if (sum < target) start++;
                    else if (sum > target)
                        end--;
                    else {
                        result.push_back({nums[i], nums[j], nums[start], nums[end]});
                        int last_start = start, last_end = end;
                        // 剔除重复项
                        while (start < end && nums[start] == nums[last_start]) start++;
                        while (start < end && nums[end] == nums[last_end]) end--;
                    }
                }
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
