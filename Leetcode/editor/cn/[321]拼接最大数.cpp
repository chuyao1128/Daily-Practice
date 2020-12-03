//给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字。现在从这两个数组中选出 k (k <= m + n) 个数字拼接
//成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。
//
// 求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。
//
// 说明: 请尽可能地优化你算法的时间和空间复杂度。
//
// 示例 1:
//
// 输入:
//nums1 = [3, 4, 6, 5]
//nums2 = [9, 1, 2, 5, 8, 3]
//k = 5
//输出:
//[9, 8, 6, 5, 3]
//
// 示例 2:
//
// 输入:
//nums1 = [6, 7]
//nums2 = [6, 0, 4]
//k = 5
//输出:
//[6, 7, 6, 0, 4]
//
// 示例 3:
//
// 输入:
//nums1 = [3, 9]
//nums2 = [8, 9]
//k = 3
//输出:
//[9, 8, 9]
// Related Topics 贪心算法 动态规划
// 👍 312 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        //获取nums序列中长度为k的最大子序列
        vector<int> getMax(vector<int> & nums, int s) {
            vector<int> res;
            int size = nums.size();
            int del = size - s;//可丢弃的元素长度
            for (auto num : nums) {
                //当当前元素比上一个元素大且可丢弃元素长度大于0时，可丢弃上一个元素
                while (res.size() > 0 && del > 0 && num > res.back()) {
                    del--;
                    res.pop_back();//丢弃末尾元素
                }
                //未达到长度s，添加num
                if (res.size() < s) {
                    res.push_back(num);
                }
                //取够长度s，剩下的直接丢弃
                else {
                    del--;
                }
            }
            return res;
        }
        vector<int> merge(vector<int> & nums1, vector<int> & nums2) {
            vector<int> res;
            int m = nums1.size();
            int n = nums2.size();
            if (m == 0) {
                return nums2;
            }
            if (n == 0) {
                return nums1;
            }
            int i = 0;
            int j = 0;
            while (i < m && j < n) {
                //取数字大的，若相同则取下一位大的
                if (vector<int>(nums1.begin() + i, nums1.end()) > vector<int>(nums2.begin() + j, nums2.end())) {
                    res.push_back(nums1[i]);
                    i++;
                } else {
                    res.push_back(nums2[j]);
                    j++;
                }
            }
            //将剩余元素加入结果
            copy(nums1.begin() + i, nums1.end(), back_inserter(res));
            copy(nums2.begin() + j, nums2.end(), back_inserter(res));
            return res;
        }
        vector<int> maxNumber(vector<int> & nums1, vector<int> & nums2, int k) {
            vector<int> res;
            int m = nums1.size();
            int n = nums2.size();
            for (int i = 0; i <= m; i++)//从第一个数组中取 i 个元素
            {
                if (i > k) break;//最多取 k 个
                if (n >= k - i)  //第二个数组中能取剩余元素
                {
                    vector<int> vec1 = getMax(nums1, i);
                    vector<int> vec2 = getMax(nums2, k - i);
                    vector<int> result = merge(vec1, vec2);
                    res = max(result, res);
                }
            }
            return res;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
