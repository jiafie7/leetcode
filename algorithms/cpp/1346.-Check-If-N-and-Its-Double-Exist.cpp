// Source : https://leetcode.cn/problems/check-if-n-and-its-double-exist/
// Author : Garfield Zhang
// Date   : 2022-08-31

/*************************************************************************************************************************
 *
 * Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).
 *
 * More formally check if there exists two indices i and j such that :
 *   i != j
 *   0 <= i, j < arr.length
 *   arr[i] == 2 * arr[j]
 *
 * Example 1:
 * Input: arr = [10,2,5,3]
 * Output: true
 * Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.
 *
 * Example 2:
 * Input: arr = [3,1,7,11]
 * Output: false
 * Explanation: In this case does not exist N and M, such that N = 2 * M.
 *
 ************************************************************************************************************************/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> hash;
        for (int x: arr) {
            if (hash.count(x * 2) || x % 2 == 0 && hash.count(x / 2))
                return true;
            hash.insert(x);
        }
        return false;
    }
};

 
