class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m1, m2;
        int windowStart = 0, windowEnd = 0;
        bool result = false;
         
        for(auto character : s1){
            m1[character]++;
        }
        
        while(windowEnd < s2.length()){
            m2[s2[windowEnd]]++;
            
            if(windowEnd-windowStart+1 < s1.length()){
                windowEnd++;
            }else if(windowEnd-windowStart+1 == s1.length()){
                if(m1==m2){
                    result = true;
                    break;
                }else{
                    m2[s2[windowStart]]--;
                    if(m2[s2[windowStart]] == 0){
                        m2.erase(s2[windowStart]);
                    }
                    windowStart++;
                    windowEnd++;
                }
            }
        }
        return result;        
    }
};