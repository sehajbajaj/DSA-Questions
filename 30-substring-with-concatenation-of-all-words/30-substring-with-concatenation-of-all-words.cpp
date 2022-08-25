class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> dictionary;
        
        for(auto &word : words){
            dictionary[word]++;
        }
        
        vector<int> answer;
        int n = s.length(), wordLength = words[0].length(), wordsSize = words.size();
        
        
        //iterating over the string
        //word by word
        for(int it = 0; it < wordLength; it++){
            unordered_map<string, int> observedWords;
            int left = it;
            int currLength = 0;
            
            //iterating over the string
            //from left bound till the valid string's size
            for(int i = left; i + wordLength <= n; i += wordLength){
                string temp = s.substr(i, wordLength);
                if(!dictionary.count(temp)){
                    observedWords.clear();
                    currLength = 0;
                    left = i + wordLength;
                }else{
                    observedWords[temp]++;
                    currLength++;
                    
                    //if there are excess words
                    if(observedWords[temp] > dictionary[temp]){
                        while(observedWords[temp] > dictionary[temp]){
                            string leftMost = s.substr(left, wordLength);
                            observedWords[leftMost]--;
                            currLength--;
                            left += wordLength;
                        }
                    }
                }
                
                //if all words in words array have been found
                if(currLength == wordsSize){
                    answer.push_back(left);
                    observedWords[s.substr(left, wordLength)]--;
                    currLength--;
                    left += wordLength;
                }
            }
        }
        return answer;
    }
};