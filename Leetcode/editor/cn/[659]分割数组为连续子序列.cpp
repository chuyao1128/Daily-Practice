//给你一个按升序排序的整数数组 num（可能包含重复数字），请你将它们分割成一个或多个子序列，其中每个子序列都由连续整数组成且长度至少为 3 。
//
// 如果可以完成上述分割，则返回 true ；否则，返回 false 。
//
//
//
// 示例 1：
//
// 输入: [1,2,3,3,4,5]
//输出: True
//解释:
//你可以分割出这样两个连续子序列 :
//1, 2, 3
//3, 4, 5
//
//
//
//
// 示例 2：
//
// 输入: [1,2,3,3,4,4,5,5]
//输出: True
//解释:
//你可以分割出这样两个连续子序列 :
//1, 2, 3, 4, 5
//3, 4, 5
//
//
//
//
// 示例 3：
//
// 输入: [1,2,3,4,4,5]
//输出: False
//
//
//
//
// 提示：
//
//
// 输入的数组长度范围为 [1, 10000]
//
//
//
// Related Topics 堆 贪心算法
// 👍 195 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPossible(vector<int> &nums) {
        unordered_map<int, int> nc;  //记录每个数字出现次数
        unordered_map<int, int> tail;//记录以i为结尾的长度大于3的子序列个数
        for (auto num : nums) {
            nc[num]++;
        }
        for (auto num : nums) {
            if (nc[num] == 0) {//当前数字次数用完，则跳过
                continue;
            } else if (nc[num] > 0 && tail[num - 1] > 0) {//若有以num-1为结尾的子序列，则将num添加到该序列结尾
                nc[num]--;
                tail[num - 1]--;
                tail[num]++;
            } else if (nc[num] > 0 && nc[num + 1] > 0 && nc[num + 2] > 0) {//若无num-1为结尾的子序列，如果num+1，num+2有剩余次数，则新建num+2为结尾的子序列
                nc[num]--;
                nc[num + 1]--;
                nc[num + 2]--;
                tail[num + 2]++;
            } else {
                return false;
            }
        }
        return true;
    }
}
}
;
//leetcode submit region end(Prohibit modification and deletion)
