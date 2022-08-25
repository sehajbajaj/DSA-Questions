​
**Optimal:- Analysis:
T(C)=O(n)
S(C)=O(n)**
​
​
1. Store the jth element in the map
2. When to decide has the window been found or not? If the map’s size becomes equal to the length of the substring, it means window is found as it indicates that there are no repeating characters. Calculate the length.
3. If in case map’s size is less than the length of the substring, it means we have taken repeating characters into consideration in order to prevent this we start removing calculations for the ith element from the map. If it becomes 0, simply erase it.
​
```c++
int lengthOfLongestSubstring(string s) {
  unordered_map<char, int> h;
  int ans = 0, i = 0, j = 0;
  while(j<s.length()) {
    h[s[j]]++;
    while(h[s[j]]>1) {
      h[s[i++]]--;
    }
    ans = max(ans, (((j++)-i)+1));
  }
  return ans;
}
```
​
### Optimal-2
​
```c++
int lengthOfLongestSubstring(string s) {
  int winS = 0, winE = 0;
  unordered_map<char, int> m;
  int ans = 0;
  while(winE < s.length()){
    //1. calculation step
    m[s[winE]]++;
    //2. Window found
    if(m.size() == winE-winS+1){
      ans = max(ans, winE-winS+1); //calculating ans
      winE++;
    }else if(m.size() < winE-winS+1){  //3. Window not Found, dupes found
      while(m.size() < winE-winS+1){
        m[s[winS]]--;               //Sliding window
        if(m[s[winS]] == 0){
          m.erase(s[winS]);
        }
        winS++;
      }
      ans = max(ans, winE-winS+1);
      winE++;
    }
  }
  return ans;
}
```
​
​
