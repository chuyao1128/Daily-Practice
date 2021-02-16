//N 对情侣坐在连续排列的 2N 个座位上，想要牵到对方的手。 计算最少交换座位的次数，以便每对情侣可以并肩坐在一起。 一次交换可选择任意两人，让他们站起来交
//换座位。 
//
// 人和座位用 0 到 2N-1 的整数表示，情侣们按顺序编号，第一对是 (0, 1)，第二对是 (2, 3)，以此类推，最后一对是 (2N-2, 2N-1)
//。 
//
// 这些情侣的初始座位 row[i] 是由最初始坐在第 i 个座位上的人决定的。 
//
// 示例 1: 
//
// 
//输入: row = [0, 2, 1, 3]
//输出: 1
//解释: 我们只需要交换row[1]和row[2]的位置即可。
// 
//
// 示例 2: 
//
// 
//输入: row = [3, 2, 0, 1]
//输出: 0
//解释: 无需交换座位，所有的情侣都已经可以手牵手了。
// 
//
// 说明: 
//
// 
// len(row) 是偶数且数值在 [4, 60]范围内。 
// 可以保证row 是序列 0...len(row)-1 的一个全排列。 
// 
// Related Topics 贪心算法 并查集 图 
// 👍 190 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class UnionSet {
private:
    vector<int> parent; //节点 x 的根节点是 parent[x]
    vector<int> size; //以 x 为根节点的树的节点个数为 size[x]
    int count; //联通分量

public:
    //构造函数
    UnionSet(int n) : parent(n), size(n) {
        count = n;//一开始互不联通
        for (int i = 0; i < n; i++) {
            parent[i] = i; //父节点指针初始指向自己
            size[i] = 1; //初始每棵树只有一个节点
        }
    }

    //查找根节点
    int find(int x) {
        //根节点的 parent[x] == x
        if (parent[x] != x) {
            //路径压缩，遍历过程中所有父节点直接指向根节点，减少后续查找次数
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    //合并两个节点
    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        //处于同一个并查集，不需要合并
        if (rootX == rootY) {
            return;
        }
        //将两棵树合并为一棵，小树接在大树下面，即合并两个并查集
        if (size[rootX] < size[rootY]) {
            swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
        count--;
    }

    int getCount() {
        return count;
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int> &row) {
        int n = row.size();
        int N = n / 2; //情侣对数
        UnionSet us(n / 2); //构建并查集
        for (int i = 0; i < n; i += 2) {
            // 若row[i]与row[i+1]是情侣，则情侣编号相同，所以本来就是联通分量
            // 若row[i]与row[i+1]不是情侣，则联通分量-1
            us.merge(row[i] / 2, row[i + 1] / 2);
        }
        //至少交换的次数 = 所有情侣的对数 - 并查集里连通分量的个数
        return N - us.getCount();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
