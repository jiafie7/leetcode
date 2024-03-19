// Source : https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
// Author : Garfield Zhang
// Date   : 2024-03-19

/****************************************************************************************
 *
 * Given a string containing digits from 2-9 inclusive, return all possible letter
 * combinations that the number could represent. Return the answer in any order.
 *
 * A mapping of digits to letters (just like on the telephone buttons) is given below.
 * Note that 1 does not map to any letters.
 *
 ****************************************************************************************/

class Solution {
public:
    vector<string> res;
    string str[10] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        dfs(digits, 0, "");
        return res;
    }

    void dfs(string digits, int u, string path) {
        if (u == digits.size()) res.push_back(path);
        else {
            for (auto c: str[digits[u] - '0'])
                dfs(digits, u + 1, path + c);
        }
    }
};