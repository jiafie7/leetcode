// Source : https://leetcode.cn/problems/max-chunks-to-make-sorted-ii/
// Author : Hang Zhang
// Date   : 2022-08-15

/********************************************************************************************************************************
 *
 * You are given an integer array arr.
 * We split arr into some number of chunks (i.e., partitions), and individually sort each chunk.
 * After concatenating them, the result should equal the sorted array.
 * Return the largest number of chunks we can make to sort the array.
 *
 * Example 1:
 * Input: arr = [5,4,3,2,1]
 * Output: 1
 * Explanation:
 * Splitting into two or more chunks will not return the required result.
 * For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
 *
 ******************************************************************************************************************************/

class Solution {
    public int maxChunksToSorted(int[] arr) {
        Stack<Integer> stk = new Stack<>();
        for (int x: arr) {
            int t = x;
            while (stk.size() > 0 && stk.peek() > x) {
                t = Math.max(t, stk.peek());
                stk.pop();
            }
            stk.push(t);
        }
        return stk.size();
    }
}
