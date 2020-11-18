//假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对 (h, k) 表示，其中 h 是这个人的身高，k 是应该排在这个人前面且身高大于或等于 h 的人数
//。 例如：[5,2] 表示前面应该有 2 个身高大于等于 5 的人，而 [5,0] 表示前面不应该存在身高大于等于 5 的人。
//
// 编写一个算法，根据每个人的身高 h 重建这个队列，使之满足每个整数对 (h, k) 中对人数 k 的要求。
//
//
//
//
// 示例：
//
//
//输入：[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
//输出：[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
//
//
//
// 提示：
//
//
// 总人数少于 1100 人。
//
// Related Topics 贪心算法
// 👍 675 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        int n = people.size();
        vector<vector<int>> res(n);
        for (auto person : people) {
            int spaces = person[1] + 1;
            for (int i = 0; i < n; i++) {
                if (res[i].empty()) {
                    spaces--;
                    if (!spaces) {
                        res[i] = person;
                        break;
                    }
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
