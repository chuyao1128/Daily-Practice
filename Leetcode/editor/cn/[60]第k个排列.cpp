//给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。 
//
// 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下： 
//
// 
// "123" 
// "132" 
// "213" 
// "231" 
// "312" 
// "321" 
// 
//
// 给定 n 和 k，返回第 k 个排列。 
//
// 说明： 
//
// 
// 给定 n 的范围是 [1, 9]。 
// 给定 k 的范围是[1, n!]。 
// 
//
// 示例 1: 
//
// 输入: n = 3, k = 3
//输出: "213"
// 
//
// 示例 2: 
//
// 输入: n = 4, k = 9
//输出: "2314"
// 
// Related Topics 数学 回溯算法 
// 👍 364 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factor = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}; //n!
        string ans;
        vector<int> nums;
        k--;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            int s = k / factor[n - i];
            ans += to_string(nums[s]);
            for (int j = s; j < n - i; j++) { //删除nums[s]
                nums[j] = nums[j + 1];
            }
            k %= factor[n - i];
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
