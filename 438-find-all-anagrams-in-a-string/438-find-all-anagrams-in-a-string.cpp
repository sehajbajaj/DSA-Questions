class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> m;
        vector<int> v;
        int k = p.length();
        
        int i = 0, j = 0;
        
        for(auto element : p){
            m[element]++;
        }
        int count = m.size();
        
        while(j < s.length()){
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]] == 0){
                    count--;
                }
            }
            
            if(j-i+1 < k){
                j++;
            }else if(j-i+1 == k){
                if(count == 0){
                    v.push_back(i);
                }
                if(m.find(s[i])!=m.end()){
                    m[s[i]]++;
                    if(m[s[i]] == 1){
                        count++;
                    }
                }
                i++;
                j++;
            }
        }
        return v;
    }
};