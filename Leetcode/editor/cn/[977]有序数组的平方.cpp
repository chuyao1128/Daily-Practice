//给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
//
//
//
// 示例 1：
//
// 输入：[-4,-1,0,3,10]
//输出：[0,1,9,16,100]
//
//
// 示例 2：
//
// 输入：[-7,-3,2,3,11]
//输出：[4,9,9,49,121]
//
//
//
//
// 提示：
//
//
// 1 <= A.length <= 10000
// -10000 <= A[i] <= 10000
// A 已按非递减顺序排序。
//
// Related Topics 数组 双指针
// 👍 153 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> sortedSquares(vector<int> &A) {
        int n = A.size();
        vector<int> res(n);
        for (int i = 0, j = n - 1, cur = n - 1; i <= j;) {
            if (A[i] * A[i] > A[j] * A[j]) {
                res[cur] = A[i] * A[i];
                i++;
            } else {
                res[cur] = A[j] * A[j];
                j--;
            }
            cur--;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
