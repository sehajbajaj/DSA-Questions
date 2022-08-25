class Solution {
public:
    
    //TC -> O(N) and SC -> O(N)
    int characterReplacement(string s, int k) {
        int windowStart = 0;
        int maxLen = -1;
        unordered_map<char, int> m;
        int maxLetterCount = -1;
        
        for(int windowEnd = 0; windowEnd < s.length(); windowEnd++){
            //1. Calculation - Put the characters in map and calculate max character
            m[s[windowEnd]]++;
            maxLetterCount = max(maxLetterCount, m[s[windowEnd]]);     
            
            //2. Window Size Found -> remaining characters are less than k
            //3. Window size not found -> remaining characters are more than k
            while(windowEnd-windowStart+1 - maxLetterCount > k){
                m[s[windowStart]]--;
                windowStart++;
            }
            
            //Calculate ans
            maxLen = max(maxLen, windowEnd-windowStart+1);
        }
        return maxLen;
    }
};