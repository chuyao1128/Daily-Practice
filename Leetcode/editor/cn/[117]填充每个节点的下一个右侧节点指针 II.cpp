//给定一个二叉树
//
// struct Node {
//  int val;
//  Node *left;
//  Node *right;
//  Node *next;
//}
//
// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
//
// 初始状态下，所有 next 指针都被设置为 NULL。
//
//
//
// 进阶：
//
//
// 你只能使用常量级额外空间。
// 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
//
//
//
//
// 示例：
//
//
//
// 输入：root = [1,2,3,4,5,null,7]
//输出：[1,#,2,3,#,4,5,7,#]
//解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。
//
//
//
// 提示：
//
//
// 树中的节点数小于 6000
// -100 <= node.val <= 100
//
//
//
//
//
//
// Related Topics 树 深度优先搜索
// 👍 250 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
//队列BFS
class Solution {
public:
    Node *connect(Node *root) {
        if (!root)
            return nullptr;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            Node *cur = nullptr;
            for (int i = 0; i < n; i++) {
                Node *temp = q.front();
                q.pop();
                if (cur) {
                    cur->next = temp;
                }
                cur = temp;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }
        return root;
    }
};

/**
 * next指针代替队列
 * 一旦在某层的节点之间建立了next指针，那这层节点实际上形成了一个链表。因此，如果先去建立某一层的next指针，再去遍历这一层，就无需再使用队列了。
 * 从根节点开始。因为第0层只有一个节点，不需要处理。可以在上一层为下一层建立next指针。
 * 该方法最重要的一点是：位于第x层时为第x+1层建立next指针。一旦完成这些连接操作，移至第x+1层为第x+2层建立next指针。
 * 当遍历到某层节点时，该层节点的next指针已经建立。这样就不需要队列从而节省空间。
 * 每次只要知道下一层的最左边的节点（nextStart），就可以从该节点开始，像遍历链表一样遍历该层的所有节点。
 */
class Solution_2 {
public:
    void helper(Node *&p, Node *&last, Node *&nextStart) {
        if (last) {
            last->next = p;
        }
        if (!nextStart) {
            nextStart = p;
        }
        last = p;
    }
    Node *connect(Node *root) {
        if (!root) {
            return nullptr;
        }
        Node *start = root;
        while (start) {
            Node *last = nullptr;
            Node *nextStart = nullptr;
            for (Node *p = start; p != nullptr; p = p->next) {
                if (p->left)
                    helper(p->left, last, nextStart);
                if (p->right)
                    helper(p->right, last, nextStart);
            }
            start = nextStart;
        }
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
