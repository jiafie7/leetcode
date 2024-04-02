// Source : https://leetcode.com/problems/longest-valid-parentheses/description/
// Author : Garfield Zhang
// Date   : 2024-04-02

/****************************************************************************************
 *
 * Given a string containing just the characters '(' and ')', return the length 
 * of the longest valid (well-formed) parentheses substring.
 *
 ****************************************************************************************/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int res = 0;
        for (int i = 0, start = -1; i < s.size(); i ++ ) {
            if (s[i] == '(') stk.push(i);
            else {
                if (stk.size()) {
                    stk.pop();
                    if (stk.size())
                        res = max(res, i - stk.top());
                    else
                        res = max(res, i - start);
                }
                else {
                    start = i;
                }
            }
        }
        return res;
    }
};
