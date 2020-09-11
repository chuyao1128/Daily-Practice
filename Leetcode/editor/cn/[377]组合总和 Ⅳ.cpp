//给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。
//
// 示例:
//
//
//nums = [1, 2, 3]
//target = 4
//
//所有可能的组合为：
//(1, 1, 1, 1)
//(1, 1, 2)
//(1, 2, 1)
//(1, 3)
//(2, 1, 1)
//(2, 2)
//(3, 1)
//
//请注意，顺序不同的序列被视作不同的组合。
//
//因此输出为 7。
//
//
// 进阶：
//如果给定的数组中含有负数会怎么样？
//问题会产生什么变化？
//我们需要在题目中添加什么限制来允许负数的出现？
//
// 致谢：
//特别感谢 @pbrother 添加此问题并创建所有测试用例。
// Related Topics 动态规划
// 👍 198 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * dp[i]=dp[i-nums[0]]+dp[i-nums[1]]+dp[i=nums[2]]+...，即de[i]为dp[i-nums[j]]之和
 * dp[i]为以nums[j]为结尾的排列个数
 * 例nums=[1,3,4],target=7，则dp[7]=dp[6]+dp[4]+dp[3]
 * 对于7而言，以1为结尾的排列个数为dp[6]，以3为结尾的排列个数为dp[4]，以4为结尾的排列个数为dp[3]
 * dp[0]=1，假如target = nums[j]，那么dp[target-nums[j]]就是dp[0]，此时相当于一个数字就可以组合出target，这也是一个结果
 */
class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        if (nums.size() == 0)
            return 0;
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                //当i==nums[j]时，以nums[j]为结尾的所有排列只有一个，所以直接使dp[0]=1实现这一目的
                dp[i] += (i - nums[j] >= 0 ? dp[i - nums[j]] : 0);
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
