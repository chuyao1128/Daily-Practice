//给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
//
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
//
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
//
//
//
// 示例 1：
//
//
//输入：k = 2, prices = [2,4,1]
//输出：2
//解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
//
// 示例 2：
//
//
//输入：k = 2, prices = [3,2,6,5,0,3]
//输出：7
//解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
//     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3
//。
//
//
//
// 提示：
//
//
// 0 <= k <= 109
// 0 <= prices.length <= 1000
// 0 <= prices[i] <= 1000
//
// Related Topics 动态规划
// 👍 362 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if (!n) {
            return 0;
        }

        k = min(k, n / 2);
        vector<vector<int>> buy(n, vector<int>(k + 1)); //持有一支股票
        vector<vector<int>> sell(n, vector<int>(k + 1));//无股票

        buy[0][0] = -prices[0];
        sell[0][0] = 0;
        for (int i = 1; i <= k; i++) {
            buy[0][i] = sell[0][i] = INT_MIN / 2;//为啥一定要÷2啊。。。
        }

        for (int i = 1; i < n; i++) {
            buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
            for (int j = 1; j <= k; j++) {
                buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
                sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
            }
        }

        return *max_element(sell[n - 1].begin(), sell[n - 1].end());
    }
};
//leetcode submit region end(Prohibit modification and deletion)
