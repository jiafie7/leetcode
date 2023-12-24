// Source : https://leetcode.cn/problems/max-chunks-to-make-sorted-ii/
// Author : Garfield Zhang
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

// O(n)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stk;
        for (int x: arr) {
            int t = x;
            while (stk.size() && stk.top() > x) {
                t = max(t, stk.top());
                stk.pop();
            }
            stk.push(t);
        }
        return stk.size();
    }
};

// O(nlogn)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        unordered_map<int, int> cnt;
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        int res = 0;
        for (int i = 0; i < arr.size(); i ++ ) {
            int x = arr[i], y = sortedArr[i];
            cnt[x] ++ ;
            if (cnt[x] == 0)
                cnt.erase(x);
            cnt[y] -- ;
            if (cnt[y] == 0)
                cnt.erase(y);
            if (cnt.size() == 0)
                res ++ ;
        }
        return res;
    }
};

