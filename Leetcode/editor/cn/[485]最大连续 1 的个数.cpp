//给定一个二进制数组， 计算其中最大连续 1 的个数。 
//
// 
//
// 示例： 
//
// 
//输入：[1,1,0,1,1,1]
//输出：3
//解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
// 
//
// 
//
// 提示： 
//
// 
// 输入的数组只包含 0 和 1 。 
// 输入数组的长度是正整数，且不超过 10,000。 
// 
// Related Topics 数组 
// 👍 199 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//一次遍历
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        res = 0;
        int cnt = 0;
        if (nums.size() == 1) {
            return nums[0];
        }
        for (const auto &x : nums) {
            if (x) {
                cnt++;
            } else {
                res = max(res, cnt);
                cnt = 0;
            }
        }
        res = max(res, cnt);
        return res;
    }
};

//滑动窗口
class Solution_1 {
private:
    int res;
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        res = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        while (r < n) {
            if (nums[r]) {
                r++;
            } else {
                res = max(res, r - l);
                r++;
                l = r;
            }
        }
        res = max(res, r - l);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
