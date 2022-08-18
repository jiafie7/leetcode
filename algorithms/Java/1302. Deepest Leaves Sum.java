// Source : https://leetcode.cn/problems/deepest-leaves-sum/
// Author : Hang Zhang
// Date   : 2022-08-18

/**************************************************************************************************************************
 *
 * Given the root of a binary tree, return the sum of values of its deepest leaves.
 *
 * Example 1:
 * Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
 * Output: 15
 *
 * Example 2:
 * Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
 * Output: 19
 *
 **************************************************************************************************************************/
 
 /**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int depth = -1, sum = 0;

    private void dfs(TreeNode root, int d) {
        if (root == null) return;
        if (d > depth) {
            depth = d;
            sum = root.val;
        } else if (d == depth){
            sum += root.val;
        }
        dfs(root.left, d + 1);
        dfs(root.right, d + 1);
    }

    public int deepestLeavesSum(TreeNode root) {
        dfs(root, 0);
        return sum;
    }
}
 
 
