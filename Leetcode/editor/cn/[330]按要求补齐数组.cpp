//给定一个已排序的正整数数组 nums，和一个正整数 n 。从 [1, n] 区间内选取任意个数字补充到 nums 中，使得 [1, n] 区间内的任何数字都
//可以用 nums 中某几个数字的和来表示。请输出满足上述要求的最少需要补充的数字个数。
//
// 示例 1:
//
// 输入: nums = [1,3], n = 6
//输出: 1
//解释:
//根据 nums 里现有的组合 [1], [3], [1,3]，可以得出 1, 3, 4。
//现在如果我们将 2 添加到 nums 中， 组合变为: [1], [2], [3], [1,3], [2,3], [1,2,3]。
//其和可以表示数字 1, 2, 3, 4, 5, 6，能够覆盖 [1, 6] 区间里所有的数。
//所以我们最少需要添加一个数字。
//
// 示例 2:
//
// 输入: nums = [1,5,10], n = 20
//输出: 2
//解释: 我们需要添加 [2, 4]。
//
//
// 示例 3:
//
// 输入: nums = [1,2,2], n = 5
//输出: 0
//
// Related Topics 贪心算法
// 👍 199 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minPatches(vector<int> &nums, int n) {
        long long maxi = 1;
        int res = 0;
        int i = 0;
        while (maxi <= n) {
            if (i < nums.size() && nums[i] < maxi + 1) {
                // 确认并更新数组可以覆盖的范围
                maxi += nums[i];
                i++;
            } else {
                // 无法根据现有数字构建更大覆盖范围则贪心加入 maxi 将覆盖范围扩大一倍
                maxi += maxi;
                res++;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
