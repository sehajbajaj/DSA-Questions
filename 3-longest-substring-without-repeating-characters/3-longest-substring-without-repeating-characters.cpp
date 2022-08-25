class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        unordered_set<char> us;

        int windowStart = 0;
        for (int windowEnd = 0; windowEnd < s.size(); ++windowEnd) {
            while (us.find(s[windowEnd]) != us.end()) {
                us.erase(s[windowStart]);
                windowStart++;
            }
            us.insert(s[windowEnd]);
            result = max(result, windowEnd - windowStart + 1);
        }
        return result;
    }
};