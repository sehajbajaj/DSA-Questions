### BEST ONE -> TC = O (n*wordLength) and SC = O(wordLength+wordsSize)
​
```
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