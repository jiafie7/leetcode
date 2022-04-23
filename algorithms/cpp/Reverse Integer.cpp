// Source : https://leetcode-cn.com/problems/reverse-integer/
// Author : Hang Zhang
// Date   : 2022-04-23

/******************************************************************************************************************
 *
 * Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
 *
 * Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
 *
 * Example 1:
 * Input: x = 123
 * Output: 321
 * 
 * Example 2:
 * Input: x = -123
 * Output: -321
 * 
 * Example 3:
 * Input: x = 120
 * Output: 21
 *
 *********************************************************************************************************************/

class Solution {
public:
    // int 
    int reverse(int x) {    
        int res = 0;
        while (x) {
            if (res > 0 && res > (INT_MAX - x % 10) / 10) return 0;
            if (res < 0 && res < (INT_MIN - x % 10) / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (res > INT_MAX) return 0;
        if (res < INT_MIN) return 0;
        return res;
    }
    
    // long
    // int reverse(int x) {
    //     long res = 0;
    //     while (x) {
    //         res = res * 10 + x % 10;
    //         x /= 10;
    //     }
    //     if (res > INT_MAX) return 0;
    //     if (res < INT_MIN) return 0;
    //     return res;
    // }
};
