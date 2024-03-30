// Source : https://leetcode.com/problems/divide-two-integers/description/
// Author : Garfield Zhang
// Date   : 2024-03-30

/****************************************************************************************
 *
 * Given two integers dividend and divisor, divide two integers without using 
 * multiplication, division, and mod operator.
 *
 * The integer division should truncate toward zero, which means losing its 
 * fractional part. For example, 8.345 would be truncated to 8, and -2.7335 
 * would be truncated to -2.
 *
 * Return the quotient after dividing dividend by divisor.
 *
 * Note: Assume we are dealing with an environment that could only store 
 * integers within the 32-bit signed integer range: [−231, 231 − 1]. For this 
 * problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, 
 * and if the quotient is strictly less than -231, then return -231.
 *
 ****************************************************************************************/

class Solution {
public:
    int divide(int dividend, int divisor) {
        typedef long long LL;
        vector<LL> exp;
        bool is_minus = false;
        if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0) is_minus = true;
        
        LL a = abs((LL)dividend), b = abs((LL)divisor);
        for (LL i = b; i <= a; i = i + i) exp.push_back(i);  // i + i 就相当于每次*2

        LL res = 0;
        for (int i = exp.size() - 1; i >= 0; i -- ) {
            if (a >= exp[i]) {
                a -= exp[i];
                res += (LL)1 << i;
            }
        }

        if (is_minus) res = -res;
        if (res > INT_MAX) res = INT_MAX;
        if (res < INT_MIN) res = INT_MIN;

        return res;
    }
};
