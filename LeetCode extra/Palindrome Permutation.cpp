/*
Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.

Hint:

        Consider the palindromes of odd vs even length. What difference do you notice?
Count the frequency of each character.
If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?
 */

class Solution {
public:
    bool canPermutePalindrome(string s) {
        int numOfOdds = 0;
        int alphabet[256] = {0};
        for (auto &ch: s) {
            ++alphabet[ch];
        }
        for (int i = 0; i < 256; ++i) {
            if (alphabet[i] & 1) {
                ++numOfOdds;
            }
        }
        return numOfOdds <= 1;
    }
};
