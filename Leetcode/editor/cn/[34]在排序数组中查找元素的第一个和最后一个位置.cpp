//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//
// 如果数组中不存在目标值 target，返回 [-1, -1]。
//
// 进阶：
//
//
// 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
//
//
//
//
// 示例 1：
//
//
//输入：nums = [5,7,7,8,8,10], target = 8
//输出：[3,4]
//
// 示例 2：
//
//
//输入：nums = [5,7,7,8,8,10], target = 6
//输出：[-1,-1]
//
// 示例 3：
//
//
//输入：nums = [], target = 0
//输出：[-1,-1]
//
//
//
// 提示：
//
//
// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums 是一个非递减数组
// -109 <= target <= 109
//
// Related Topics 数组 二分查找
// 👍 691 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int n = nums.size();
        vector<int> res(2);
        res[0] = res[1] = -1;
        if ((n == 0) || (nums[0] > target) || (nums[n - 1] < target)) {
            return res;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target && res[0] == -1) {
                res[0] = res[1] = i;
            } else if (nums[i] == target && res[0] != -1) {
                res[1] = i;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
