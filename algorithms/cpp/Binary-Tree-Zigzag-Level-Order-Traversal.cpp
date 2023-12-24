// Source : https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
// Author : Garfield Zhang 
// Date   ：2021-04-18

/*******************************************************************************************************
 *
 * Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
 * (i.e., from left to right, then right to left for the next level and alternate between).
 *
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[20,9],[15,7]]
 *
 * Example 2:
 * Input: root = [1]
 * Output: [[1]]
 *
 * Example 3:
 * Input: root = []
 * Output: []
 *
 * Constraints:
 * The number of nodes in the tree is in the range [0, 2000].
 * -100 <= Node.val <= 100
 *
 *******************************************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> queue;
        bool flag = true;

        queue.push(root);
        while (!queue.empty()) {
            deque<int> level;                //double-ended queue
            int n = queue.size();
            for (int i = 0; i < n; ++ i) {
                TreeNode* node = queue.front();
                queue.pop();
                if (flag) {
                    level.push_back(node->val);
                } else {
                    level.push_front(node->val);
                }
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
            flag = !flag;
            res.push_back(vector<int>{level.begin(), level.end()});
        }
        return res;
    }
};
