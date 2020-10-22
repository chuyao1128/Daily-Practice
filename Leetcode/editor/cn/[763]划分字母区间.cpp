//字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。
//
//
//
// 示例 1：
//
// 输入：S = "ababcbacadefegdehijhklij"
//输出：[9,7,8]
//解释：
//划分结果为 "ababcbaca", "defegde", "hijhklij"。
//每个字母最多出现在一个片段中。
//像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
//
//
//
//
// 提示：
//
//
// S的长度在[1, 500]之间。
// S只包含小写字母 'a' 到 'z' 。
//
// Related Topics 贪心算法 双指针
// 👍 294 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int last[26];
        for (int i = 0; i < S.size(); i++) {
            last[S[i] - 'a'] = i;//每个字母最后出现位置
        }
        int start = 0;
        int end = 0;
        vector<int> partition;
        for (int i = 0; i < S.size(); i++) {
            end = max(end, last[S[i] - 'a']);
            if (end == i) {
                partition.push_back(end - start + 1);//当前片段长度
                start = end + 1;
            }
        }
        return partition;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
