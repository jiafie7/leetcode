// Source : https://leetcode.cn/problems/jump-game-iv/
// Author : Hang Zhang
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

class Solution {
    public int minJumps(int[] arr) {
        int n = arr.length, INF = (int)1e8;
        Map<Integer, List<Integer>> hash = new HashMap<>();
        for (int i = 0; i < n; i ++ ) {
            int val = arr[i];
            if (hash.get(val) == null) hash.put(val, new LinkedList<Integer>());
            hash.get(val).add(i);
        }

        int[] dist = new int[n];
        Arrays.fill(dist, INF);
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        dist[0] = 0;
        while (!q.isEmpty()) {
            int t = q.remove();
            for (int i = t - 1; i <= t + 1; i ++ ) {
                if (i >= 0 && i < n && dist[i] > dist[t] + 1) {
                    dist[i] = dist[t] + 1;
                    q.add(i);
                }
            }

            int val = arr[t];
            if (hash.get(val) != null) {
                for (int i: hash.get(val)) {
                    if (dist[i] > dist[t] + 1) {
                        dist[i] = dist[t] + 1;
                        q.add(i);
                    }
                }
                hash.remove(val);
            }
        }
        return dist[n - 1];
    }
}

