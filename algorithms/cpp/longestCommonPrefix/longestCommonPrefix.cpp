// Source : https://leetcode.cn/problems/design-circular-deque/
// Author : Garfield Zhang
// Date   : 2024-03-16

/****************************************************************************************
 * 
 * Write a function to find the longest common prefix string amongst an array of strings.
 * 
 * If there is no common prefix, return an empty string "".
 *
 ****************************************************************************************/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (strs.empty()) return res;

        for (int i = 0;; i ++ ) {
            if (i >= strs[0].size()) return res;
            char c = strs[0][i];
            for (auto& str: strs)
                if (i >= str.size() || str[i] != c)
                    return res;
            res += c;    
        }
        return res;
    }
};