//给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
//
//
//
// 示例 1:
//
// 输入: nums = [1,1,1,2,2,3], k = 2
//输出: [1,2]
//
//
// 示例 2:
//
// 输入: nums = [1], k = 1
//输出: [1]
//
//
//
// 提示：
//
//
// 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
// 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
// 你可以按任意顺序返回答案。
//
// Related Topics 堆 哈希表
// 👍 477 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<int> res;

public:
    void qsort(vector<pair<int, int>> &v, int start, int end, int k) {
        int picked = rand() % (end - start + 1) + start;
        swap(v[picked], v[start]);

        int pivot = v[start].second;
        int index = start;
        for (int i = start + 1; i <= end; i++) {
            if (v[i].second >= pivot) {
                swap(v[index + 1], v[i]);
                index++;
            }
        }
        swap(v[start], v[index]);
        //如果k <= index - start，则数组v[start,end]前k大的值，就等于子数组v[start, index-1]前k大的值。
        if (k <= index - start) {
            qsort(v, start, index - 1, k);
        }
        //否则，数组v[start,end]前k大的值，就等于左侧子数组全部元素，加上右侧子数组v[index+1,end]中前 k-(index-start+1) 大的值。
        else {
            for (int i = start; i <= index; i++) {
                res.push_back(v[i].first);
            }
            if (k > index - start + 1) {
                qsort(v, index + 1, end, k - (index - start + 1));
            }
        }
    }

    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> count;//每个数字对应出现次数
        for (auto &v : nums) {
            count[v]++;
        }

        vector<pair<int, int>> values;
        for (auto &v : count) {
            values.push_back(v);
        }
        qsort(values, 0, values.size() - 1, k);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
