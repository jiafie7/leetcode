// Source : https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/
// Author : Garfield Zhang
// Date   : 2021-04-17

/***************************************************************************************************
 *
 * Given the root of a Binary Search Tree (BST), 
 * return the minimum difference between the values of any two different nodes in the tree.
 *
 * Example 1:
 * Input: root = [4,2,6,1,3]
 * Output: 1
 
 * Example 2:
 * Input: root = [1,0,48,null,null,12,49]
 * Output: 1
 *
 * Constraints:
 * The number of nodes in the tree is in the range [2, 100].
 * 0 <= Node.val <= 10^5
 * 
 ***************************************************************************************************/

// Method 1: Recursive

class Solution {
public:
    void dfs(TreeNode* root, int &pre, int &ans)
    {
        if (!root) return;
        dfs(root->left, pre, ans);
        if (pre == -1) {
            pre = root->val;
        } else {
            ans = min(ans, root->val - pre);
            pre = root->val;
        }
        dfs(root->right, pre, ans);
    }

    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX, pre = -1;
        dfs(root, pre, ans);
        return ans;
    }
};

// Method 2: Iteration

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX, pre = -1;
        stack<TreeNode*> stk;

        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            if (pre == -1) {
                root = stk.top();
                stk.pop();
                pre = root->val;
            } else {
                root = stk.top();
                stk.pop();
                ans = min(ans, root->val - pre);
                pre = root->val;
            }
            root = root->right;
        }

        return ans;
    }
};
