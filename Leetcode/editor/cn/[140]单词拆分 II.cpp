//给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的
//句子。
//
// 说明：
//
//
// 分隔时可以重复使用字典中的单词。
// 你可以假设字典中没有重复的单词。
//
//
// 示例 1：
//
// 输入:
//s = "catsanddog"
//wordDict = ["cat", "cats", "and", "sand", "dog"]
//输出:
//[
//  "cats and dog",
//  "cat sand dog"
//]
//
//
// 示例 2：
//
// 输入:
//s = "pineapplepenapple"
//wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
//输出:
//[
//  "pine apple pen apple",
//  "pineapple pen apple",
//  "pine applepen apple"
//]
//解释: 注意你可以重复使用字典中的单词。
//
//
// 示例 3：
//
// 输入:
//s = "catsandog"
//wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出:
//[]
//
// Related Topics 动态规划 回溯算法
// 👍 349 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
    private:
        unordered_map<int, vector<string>> res;
        unordered_set<string> wordSet;

    public:
        void backtrack(string s, int index) {
            if (!res.count(index)) {//未访问过的下标
                if (index == s.size()) {
                    res[index] = {""};
                    return;
                }
                res[index] = {};
                for (int i = index + 1; i <= s.size() + 1; i++) {
                    string word = s.substr(index, i - index);
                    if (wordSet.count(word)) {//单词表中有word
                        backtrack(s, i);
                        for (auto s : res[i]) {
                            res[index].push_back(s.empty() ? word : word + " " + s);
                        }
                    }
                }
            }
        }
        vector<string> wordBreak(string s, vector<string> & wordDict) {
            wordSet = unordered_set(wordDict.begin(), wordDict.end());
            backtrack(s, 0);
            return res[0];
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
