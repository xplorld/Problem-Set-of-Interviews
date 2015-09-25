/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = ¡°coding¡±, word2 = ¡°practice¡±, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 */

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int recent1 = -1, recent2 = -1;
        int result = INT_MAX;
        int sz = words.size();
        for (int i = 0; i < sz; ++i) {
            if (words[i] == word1) {
                if (recent2 != -1) {
                    result = min(result, i - recent2);
                }
                recent1 = i;
            } else if (words[i] == word2) {
                if (recent1 != - 1) {
                    result = min(result, i - recent1);
                }
                recent2 = i;
            }
        }
        return result;
    }
};
