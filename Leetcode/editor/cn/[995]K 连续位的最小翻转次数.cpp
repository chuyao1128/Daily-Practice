//在仅包含 0 和 1 的数组 A 中，一次 K 位翻转包括选择一个长度为 K 的（连续）子数组，同时将子数组中的每个 0 更改为 1，而每个 1 更改为 0
//。 
//
// 返回所需的 K 位翻转的最小次数，以便数组没有值为 0 的元素。如果不可能，返回 -1。 
//
// 
//
// 示例 1： 
//
// 
//输入：A = [0,1,0], K = 1
//输出：2
//解释：先翻转 A[0]，然后翻转 A[2]。
// 
//
// 示例 2： 
//
// 
//输入：A = [1,1,0], K = 2
//输出：-1
//解释：无论我们怎样翻转大小为 2 的子数组，我们都不能使数组变为 [1,1,1]。
// 
//
// 示例 3： 
//
// 
//输入：A = [0,0,0,1,0,1,1,0], K = 3
//输出：3
//解释：
//翻转 A[0],A[1],A[2]: A变成 [1,1,1,1,0,1,1,0]
//翻转 A[4],A[5],A[6]: A变成 [1,1,1,1,1,0,0,0]
//翻转 A[5],A[6],A[7]: A变成 [1,1,1,1,1,1,1,1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= A.length <= 30000 
// 1 <= K <= A.length 
// 
// Related Topics 贪心算法 Sliding Window 
// 👍 63 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//滑动窗口
class Solution {
public:
    int minKBitFlips(vector<int> &A, int K) {
        int res = 0;
        queue<int> q;
        for (int i = 0; i < A.size(); i++) {
            //维护大小为K的窗口，此时队列中为i-K到i-1共K个元素
            if (!q.empty() && q.front() + K == i) {
                q.pop();
            }
            //判断当前位置是否需要翻转
            if (q.size() % 2 == A[i]) {
                //第i个位置已经被翻转奇数次，且当前为1，所以翻转后为0，则还需再翻转一次
                //或者第i个位置已经被翻转偶数次，且当前为0，相当于没翻转，则需要再翻转一次
                if (i + K > A.size()) {
                    return -1;
                }
                res++;
                q.push(i);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
