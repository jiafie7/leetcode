// Source : https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
// Author : Hang Zhang
// Date   : 2022-09-08
  
/*************************************************************************************************************
 *
 * Given the string s, return the size of the longest substring containing each vowel an even number of times. 
 * That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.
 *
 * Example 1:
 * Input: s = "eleetminicoworoep"
 * Output: 13
 * Explanation: The longest substring is "leetminicowor" which 
 * contains two each of the vowels: e, i and o and zero of the vowels: a and u.
 *
 * Example 3:
 * Input: s = "bcbcbc"
 * Output: 6
 * Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
 *
 ************************************************************************************************************/

class Solution {
    public int findTheLongestSubstring(String s) {
        int[] cnt = new int[32];
        for (int i = 0; i < 32; i ++ ) cnt[i] = -2;
        cnt[0] = -1;
        String cs = "aeiou";
        int res = 0, state = 0;
        for (int i = 0; i < s.length(); i ++ ) {
            int k = cs.indexOf(s.charAt(i));
            if (k != -1) state ^= 1 << k;
            if (cnt[state] != -2) res = Math.max(res, i - cnt[state]);
            else cnt[state] = i;
        }
        return res;
    }
}
