//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//
// 示例:
//
// 输入: [0,1,0,3,12]
//输出: [1,3,12,0,0]
//
// 说明:
//
//
// 必须在原数组上操作，不能拷贝额外的数组。
// 尽量减少操作次数。
//
// Related Topics 数组 双指针
// 👍 827 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int i = 0;
        int j = 0;
        while (j < nums.size()) {
            if (nums[j]) {
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
    }
};

// 左移非零，末尾补0覆盖
class Solution_1 {
public:
    void moveZeroes(vector<int> &nums) {
        int i = 0;
        int j = 0;
        while (j < nums.size()) {
            if (nums[j]) {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        while (i < nums.size()) {
            nums[i] = 0;
            i++;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
