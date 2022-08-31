// Source : https://leetcode.com/problems/number-of-days-between-two-dates/
// Author : Hang Zhang
// Date   : 2022-08-31

/************************************************************************************************************************
 *
 * Write a program to count the number of days between two dates.
 *
 * The two dates are given as strings, their format is YYYY-MM-DD as shown in the examples.
 *
 * Example 1:
 * Input: date1 = "2019-06-29", date2 = "2019-06-30"
 * Output: 1
 *
 * Example 2:
 * Input: date1 = "2020-01-15", date2 = "2019-12-31"
 * Output: 15
 *
 ************************************************************************************************************************/
  
  class Solution:
    
    def is_leap(self, year):
        if year % 4 == 0 and year % 100 != 0 or year % 400 == 0:
            return 1
        return 0
    
    def get_days(self, year, month):
        if month != 2: return self.months[month]
        return 28 + self.is_leap(year)
    
    def get(self, date):
        year, month, day = map(int, date.split('-'))
        days = 0
        for i in range(1971, year):
            days += 365 + self.is_leap(i)
        for i in range(1, month):
            days += self.get_days(year, i)
        return days + day
        
    
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        self.months = [
            0, 31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31
        ]
        return abs(self.get(date1) - self.get(date2));
        
  
