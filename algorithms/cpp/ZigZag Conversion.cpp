// Source : https://leetcode-cn.com/problems/zigzag-conversion/
// Author : Hang Zhang 
// Date   : 2022-04-23

/**************************************************************************************************************
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string s, int numRows);=
 *
 * Example 1:
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * Example 2:
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 * Example 3:
 * Input: s = "A", numRows = 1
 * Output: "A"
 *
 ************************************************************************************************************/

class Solution {
public:
    string convert(string s, int n) {
        string res;
        if (n == 1) return s;
        for (int i = 0; i < n; i ++ ) {
            if (i == 0 || i == n - 1) {
                for (int j = i; j < s.size(); j += n * 2 - 2) {
                    res += s[j];
                }
            }
            else {
                for (int j = i, k = n * 2 - 2 - i; j < s.size() || k < s.size(); j += n * 2 - 2, k += n * 2 - 2) {
                    if (j < s.size()) res += s[j];
                    if (k < s.size()) res += s[k];
                }
            }
        }

        return res;
    }
};

