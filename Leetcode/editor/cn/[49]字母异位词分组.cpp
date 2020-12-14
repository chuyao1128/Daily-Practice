//给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
//
// 示例:
//
// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
//输出:
//[
//  ["ate","eat","tea"],
//  ["nat","tan"],
//  ["bat"]
//]
//
// 说明：
//
//
// 所有输入均为小写字母。
// 不考虑答案输出的顺序。
//
// Related Topics 哈希表 字符串
// 👍 565 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for (const auto &str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);//emplace_back比push_back效率高
        }
        for (const auto &m : mp) {
            res.emplace_back(m.second);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
