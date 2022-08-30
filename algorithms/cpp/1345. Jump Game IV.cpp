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
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> hash;
        int n = arr.size(), INF = 1e8;
        for (int i = 0; i < n; i ++ ) 
            hash[arr[i]].push_back(i);  // the index of the same value 

        vector<int> dist(n, INF);
        queue<int> q;
        dist[0] = 0;
        q.push(0);

        while (q.size()) {
            int t = q.front();
            q.pop();

            for (int i = t - 1; i <= t + 1; i += 2) {
                if (i >= 0 && i < n && dist[i] > dist[t] + 1) {
                    dist[i] = dist[t] + 1;
                    q.push(i);
                }
            }
            
            if (hash.count(arr[t])) {
                for (int i: hash[arr[t]]) {
                    if (dist[i] > dist[t] + 1) {
                        dist[i] = dist[t] + 1;
                        q.push(i);
                    }
                }
                hash.erase(arr[t]);
            }
        }
        return dist[n - 1];
    }
};

