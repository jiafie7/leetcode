// Source : https://leetcode-cn.com/problems/scramble-string/
// Author : Garfield Zhang
// Date   : 2021-04-22

/*******************************************************************************************************************
 *
 * We can scramble a string s to get a string t using the following algorithm:
 *
 * 1. If the length of the string is 1, stop.
 * 2. If the length of the string is > 1, do the following:
 *   a. Split the string into two non-empty substrings at a random index, 
 *       i.e., if the string is s, divide it to x and y where s = x + y.
 *    b. Randomly decide to swap the two substrings or to keep them in the same order. 
 *       i.e., after this step, s may become s = x + y or s = y + x.
 *    c. Apply step 1 recursively on each of the two substrings x and y.
 *
 * Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.
 *
 * Example 1:
 * Input: s1 = "great", s2 = "rgeat"
 * Output: true
 * Explanation: One possible scenario applied on s1 is:
 * "great" --> "gr/eat" // divide at random index.
 * "gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
 * "gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at ranom index each of them.
 * "g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
 * "r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
 * "r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
 * The algorithm stops now and the result string is "rgeat" which is s2.
 * As there is one possible scenario that led s1 to be scrambled to s2, we return true.
 *
 * Example 2:
 * Input: s1 = "abcde", s2 = "caebd"
 * Output: false
 *
 * Example 3:
 * Input: s1 = "a", s2 = "a"
 * Output: true
 *
 * Constraints:
 * s1.length == s2.length
 * 1 <= s1.length <= 30
 * s1 and s2 consist of lower-case English letters.
 *
 ********************************************************************************************************************/

// DP O(n^4)
// 1.状态表示：f[i, j, k]
//   1.1 集合：s1[i ~ i + k - 1]与s2[j, j + k - 1]所有匹配方案的集合
//   1.2 属性：集合是否非空
// 2.状态计算
//   将f[i, j, k]表示的集合按s1第一段的长度划分划分成k - 1类。
//   设s1第一段的长度为u。则s1[i ~ i + k - 1]与s2[j, j + k - 1]有两种匹配方案，分别判断即可：
//   (1) f[i][j][u] && f[i + u][j + u][k - u]
//   (2) f[i][j + k - u][u] && f[i + u][j][k - u]

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector<vector<vector<bool>>> f(n, vector<vector<bool>>(n, vector<bool>(n + 1)));
        for (int k = 1; k <= n; ++ k) {
            for (int i = 0; i + k - 1 < n; ++ i) {
                for (int j = 0; j + k - 1 < n; ++ j) {
                    if (k == 1) {
                        if (s1[i] == s2[j]) f[i][j][k] = true;
                    } else { 
                        for (int u = 1; u <= k - 1; ++ u) {
                            if (f[i][j][u] && f[i + u][j + u][k - u] 
                                || f[i][j + k - u][u] && f[i + u][j][k - u]) {
                                    f[i][j][k] = true;
                                    break;
                            }
                        }
                    }
                    
                }
            }
        }
        return f[0][0][n]; 
    }
};
 
 
 
 
 
 
 
