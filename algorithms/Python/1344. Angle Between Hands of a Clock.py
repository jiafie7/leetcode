// Source : https://leetcode.cn/problems/angle-between-hands-of-a-clock/
// Author : Garfield Zhang
// Date   : 2022-08-27

/************************************************************************************************************************
 *
 * Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.
 * Answers within 10-5 of the actual value will be accepted as correct.
 * 
 * Example 1:
 * Input: hour = 12, minutes = 30
 * Output: 165
 *
 ************************************************************************************************************************/
  
  class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        hour %= 12
        x = minutes * 6
        y = minutes * 0.5 + hour * 30
        return min(abs(x - y), 360 - abs(x - y))
  
