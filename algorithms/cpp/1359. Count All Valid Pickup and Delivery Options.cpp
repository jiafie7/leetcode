// Source : https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
// Author : Garfield Zhang
// Date   : 2022-09-01
  
/********************************************************************************************************************
 *
 * Given n orders, each order consist in pickup and delivery services. 
 *
 * Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i). 
 *
 * Since the answer may be too large, return it modulo 10^9 + 7.
 *
 * Example 1:
 * Input: n = 1
 * Output: 1
 * Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup 1.
 *
 ********************************************************************************************************************/

class Solution {
public:
    int countOrders(int n) {
        const int mod = 1e9 + 7;
        long long res = 1;
        for (int i = 1; i <= n; i ++ ) 
            res = res * i * (2 * i - 1) % mod;
        
        return res;
    }
};
