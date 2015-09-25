/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.
 */

class Solution {
public:
    bool judge(char lhs, char rhs) {
        if (lhs > rhs) {
            return judge(rhs, lhs);
        }
        if (lhs == rhs) {
            string same = "018";
            return same.find(lhs) != string::npos;
        }
        if (lhs == '6' && rhs == '9') return true;
        return false;
    }
    bool isStrobogrammatic(string num) {
        int sz = num.size();
        for (int i = 0; i <= (sz >> 1); ++i) {
            if (!judge(num[i], num[sz - i - 1])) {
                return false;
            }
        }
        return true;
    }
};
