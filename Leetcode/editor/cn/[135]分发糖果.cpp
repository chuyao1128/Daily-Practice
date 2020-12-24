//老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
//
// 你需要按照以下要求，帮助老师给这些孩子分发糖果：
//
//
// 每个孩子至少分配到 1 个糖果。
// 相邻的孩子中，评分高的孩子必须获得更多的糖果。
//
//
// 那么这样下来，老师至少需要准备多少颗糖果呢？
//
// 示例 1:
//
// 输入: [1,0,2]
//输出: 5
//解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
//
//
// 示例 2:
//
// 输入: [1,2,2]
//输出: 4
//解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
//     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。
// Related Topics 贪心算法
// 👍 346 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        if (!n) {
            return 0;
        }
        int res = 1;
        int inc = 1;//递增序列长度
        int dec = 0;//递减序列长度
        int pre = 1;//前一个同学的糖果
        for (int i = 1; i < n; i++) {
            if (ratings[i] >= ratings[i - 1]) {
                dec = 0;
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                inc = pre;
                res += pre;
            } else {
                dec++;
                if (dec == inc) {
                    dec++;
                }
                res += dec;//加递减序列长度相当于给该递减序列中的同学都多加一个糖果
                pre = 1;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
