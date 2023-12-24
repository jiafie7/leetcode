// Source : https://leetcode.com/problems/number-of-days-between-two-dates/
// Author : Garfield Zhang
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

class Solution {
public:
    const int months[13] = {
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    int is_leap(int year) {
        if (year % 4 == 0 && year % 100 || year % 400 == 0)
            return 1;
        return 0;
    }

    int get_days(int year, int month) {
        if (month != 2) return months[month];
        return is_leap(year) + 28;
    }

    int get(string date) {
        int year, month, day;
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
        int res = 0;
        for (int i = 1971; i < year; i ++ )
            res += 365 + is_leap(i);
        for (int i = 1; i < month; i ++ )
            res += get_days(year, i);
        return res + day;
    }

    int daysBetweenDates(string date1, string date2) {
        return abs(get(date1) - get(date2));
    }
};


