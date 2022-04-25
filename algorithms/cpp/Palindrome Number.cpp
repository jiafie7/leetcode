// Source : https://leetcode-cn.com/problems/palindrome-number/
// Author : Hang Zhang
// Date   : 2022-04-25

/***************************************************************************************************************
 *
 * Given an integer x, return true if x is palindrome integer.
 *
 * An integer is a palindrome when it reads the same backward as forward.
 *
 * For example, 121 is a palindrome while 123 is not.
 *
 * Example 1:
 * Input: x = 121
 * Output: true
 * Explanation: 121 reads as 121 from left to right and from right to left.
 * 
 * Example 2:
 * Input: x = -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 * 
 * Example 3:
 * Input: x = 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 *
 ***************************************************************************************************************/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x && x % 10 == 0) return false;
        int t = 0;
        while (t <= x) {
            t = t * 10 + x % 10;
            if (t == x || t == x / 10) return true;
            x /= 10;
        }
        //if (t == x) return true;
        return false;
    }
};

