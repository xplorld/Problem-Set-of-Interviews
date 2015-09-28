/*
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
Return:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
Note: For the return value, each inner list's elements must follow the lexicographic order.
 */

class Solution {
public:
    string getKey(string s) {
        string t = s;
        int sz = s.size();
        for (int i = 0; i < sz; ++i) {
            t[i] = 'a' + (s[i] >= s[0] ? s[i] - s[0] : s[i] - s[0] + 26);
        }
        return t;
    }

    vector<vector<string>> groupStrings(vector<string>& strings) {
        int sz = strings.size();
        vector<vector<string>> result;
        unordered_map <string, vector<string>> m;
        for (const auto &str: strings) {
            m[getKey(str)].push_back(str);
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            sort(it->second.begin(), it->second.end());
            result.push_back(it->second);
        }
        return result;
    }
};

