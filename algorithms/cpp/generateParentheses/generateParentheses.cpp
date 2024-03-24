// Source : https://leetcode.com/problems/generate-parentheses/description/
// Author : Garfield Zhang
// Date   : 2024-03-24

/****************************************************************************************
 *
 * Given n pairs of parentheses, write a function to generate all combinations of 
 * well-formed parentheses.
 *
 ****************************************************************************************/

class Solution {
public:
    vector<string> res;

    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return res;
    }

    void dfs(int n, int lc, int rc, string seq) {
        if (lc == n && rc == n) res.push_back(seq);
        else {
            if (lc < n) dfs(n, lc + 1, rc, seq + '(');
            if (rc < n && rc < lc) dfs(n, lc, rc + 1, seq + ')');
        }
    }
};
