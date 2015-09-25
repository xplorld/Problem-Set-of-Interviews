/*
This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = ��makes��, word2 = ��coding��, return 1.
Given word1 = "makes", word2 = "makes", return 3.

Note:
You may assume word1 and word2 are both in the list.
 */

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int sz = words.size();
        int result = INT_MAX;
        if (word1 == word2) {
            int recent = -1;
            for (int i = 0; i < sz; ++i) {
                if (words[i] == word1) {
                    if (recent != -1) {
                        result = min(result, i - recent);
                    }
                    recent = i;
                }
            }
            return result;
        }
        int recent1 = -1, recent2 = -1;
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
