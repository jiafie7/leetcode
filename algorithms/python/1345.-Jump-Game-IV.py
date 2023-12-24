// Source : https://leetcode.cn/problems/jump-game-iv/
// Author : Garfield Zhang
// Date   : 2022-08-30

/*************************************************************************************************************************
 *
 * Given an array of integers arr, you are initially positioned at the first index of the array.
 *
 * In one step you can jump from index i to index:
 *   i + 1 where: i + 1 < arr.length.
 *   i - 1 where: i - 1 >= 0.
 *   j where: arr[i] == arr[j] and i != j.
 *   
 * Return the minimum number of steps to reach the last index of the array.
 * Notice that you can not jump outside of the array at any time.
 *
 * Example 1:
 * Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
 * Output: 3
 * Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
 *
 *************************************************************************************************************************/
  
  class Solution:
    def minJumps(self, arr: List[int]) -> int:
        n, INF = len(arr), 1e8
        hash = {}
        for i in range(n):
            val = arr[i]
            if val not in hash: hash[val] = []
            hash[val].append(i)
        dist = [INF for i in range(n)]
        q = deque()
        dist[0] = 0
        q.append(0)

        while q:
            t = q.popleft()
            for i in range(t - 1, t + 2):
                if i >= 0 and i < n and dist[i] > dist[t] + 1:
                    dist[i] = dist[t] + 1
                    q.append(i)
            val = arr[t]
            if val in hash:
                for i in hash[val]:
                    if dist[i] > dist[t] + 1:
                        dist[i] = dist[t] + 1
                        q.append(i)
                del hash[val]
        return dist[n - 1]
  
