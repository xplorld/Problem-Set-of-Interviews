/*
Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?

Related problem: Rotate Array
 */

class Solution {
public:
    void reverseWords(string &s) {
        int sz = s.size();
        reverseStr(s, 0, sz - 1);
        int start = 0;
        for (int i = 0; i < sz; ++i) {
            if (s[i] == ' ') {
                reverseStr(s, start, i - 1);
                start = i + 1;
            }
        }
        reverseStr(s, start, sz - 1);
    }
    
    void reverseStr(string &s, int start, int end) {
        int mid = ((end - start) >> 1) + start;
        for (int i = start; i <= mid; ++i) {
            swap(s[i], s[start + end - i]);
        }
    }
};
