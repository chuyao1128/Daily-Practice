//在本问题中，有根树指满足以下条件的有向图。该树只有一个根节点，所有其他节点都是该根节点的后继。每一个节点只有一个父节点，除了根节点没有父节点。
//
// 输入一个有向图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成。附加的边的两个顶点包含在1到N中间，这条附加的边
//不属于树中已存在的边。
//
// 结果图是一个以边组成的二维数组。 每一个边 的元素是一对 [u, v]，用以表示有向图中连接顶点 u 和顶点 v 的边，其中 u 是 v 的一个父节点。
//
//
// 返回一条能删除的边，使得剩下的图是有N个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。
//
// 示例 1:
//
// 输入: [[1,2], [1,3], [2,3]]
//输出: [2,3]
//解释: 给定的有向图如下:
//  1
// / \
//v   v
//2-->3
//
//
// 示例 2:
//
// 输入: [[1,2], [2,3], [3,4], [4,1], [1,5]]
//输出: [4,1]
//解释: 给定的有向图如下:
//5 <- 1 -> 2
//     ^    |
//     |    v
//     4 <- 3
//
//
// 注意:
//
//
// 二维数组大小的在3到1000范围内。
// 二维数组中的每个整数在1到N之间，其中 N 是二维数组的大小。
//
// Related Topics 树 深度优先搜索 并查集 图
// 👍 176 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

class Solution {
private:
    vector<int> ancestor;//记录节点的祖先
    int n;               // 边的数量
    // 并查集初始化
    void init() {
        ancestor.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            ancestor[i] = i;
        }
    }

    // 并差价查找根节点
    int find(int u) {
        return u == ancestor[u] ? u : ancestor[u] = find(ancestor[u]);
    }

    // 将[u,v]这条边加入并查集
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            ancestor[v] = u;
        }
    }

    // 判断 u 和 v是有相同根节点
    bool same(int u, int v) {
        return find(u) == find(v);
    }

    // 删一条边之后判断是不是树
    bool isTreeAfterRemoveEdge(const vector<vector<int>> &edges, int deleteEdge) {
        init();// 初始化并查集
        for (int i = 0; i < n; i++) {
            if (i == deleteEdge) continue;
            if (same(edges[i][0], edges[i][1])) {// 构成有向环，一定不是树
                return false;
            }
            join(edges[i][0], edges[i][1]);
        }
        return true;
    }

    // 在有向图里找到删除的那条边，使其变成树
    vector<int> getRemoveEdge(const vector<vector<int>> &edges) {
        init();                                  // 初始化并查集
        for (int i = 0; i < n; i++) {            // 遍历所有的边
            if (same(edges[i][0], edges[i][1])) {// 构成有向环了，就是要删除的边
                return edges[i];
            }
            join(edges[i][0], edges[i][1]);
        }
        return {};
    }

public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        n = edges.size();   // 边的数量
        int inDegree[n + 1];// 记录节点入度
        memset(inDegree, 0, sizeof(inDegree));
        for (int i = 0; i < n; i++) {
            inDegree[edges[i][1]]++;// 统计入度
        }
        vector<int> vec;// 记录入度为2的边的序号（2条边）
        // 找入度为2的节点所对应的边，注意要倒叙，因为优先返回最后出现在二维数组中的答案
        for (int i = n - 1; i >= 0; i--) {
            if (inDegree[edges[i][1]] == 2) {
                vec.push_back(i);
            }
        }
        // 如果有入度为2的节点，那么一定是对应两条边删一条，选择删除后构成树的边
        if (vec.size() > 0) {
            if (isTreeAfterRemoveEdge(edges, vec[0])) {
                return edges[vec[0]];
            } else {
                return edges[vec[1]];
            }
        }
        // 如果没有入度为2的节点，那么一定存在有向环，删除环路中最后一条访问的边
        return getRemoveEdge(edges);
    }
};
//leetcode submit region end(Prohibit modification and deletion)