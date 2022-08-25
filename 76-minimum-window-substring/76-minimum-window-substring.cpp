class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        pair<int, int> ans;
        int windowStart = 0, windowEnd = 0;
        
        for(auto ele : t){
            mp[ele]++;
        }
        
        int count = mp.size();
        int counter = INT_MAX;
        
        while(windowEnd < s.length()){
            //1. Calculation
            if(mp.find(s[windowEnd]) != mp.end()){
                mp[s[windowEnd]]--;
                if(mp[s[windowEnd]] == 0){
                    count--;
                }
            }
            
            //2. Window not found
            if(count > 0){
                windowEnd++;
            }
            //3. Window found
            else if(count == 0){
                
                while(count == 0){
                    //4. Ans
                    if(windowEnd-windowStart+1 < counter){
                        counter = windowEnd-windowStart+1;
                        ans = {windowStart, counter};
                    } 
                
                    //5. Slide
                    if(mp.find(s[windowStart]) != mp.end()){
                        mp[s[windowStart]]++;
                        if(mp[s[windowStart]] == 1){
                            count++;
                        }
                    }
                    windowStart++;
                }
                windowEnd++;
            }
        }
        return counter == INT_MAX ? "" : s.substr(ans.first, ans.second);
    }
};