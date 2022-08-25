int totalFruit(vector<int>& fruits) {
int windowStart = 0;
int ans = -1;
unordered_map<int, int> m;
​
for (int windowEnd = 0; windowEnd < fruits.size(); windowEnd++) {
m[fruits[windowEnd]]++;
​
while (m.size() > 2) {
m[fruits[windowStart]]--;
if (m[fruits[windowStart]] == 0) {
m.erase(fruits[windowStart]);
}
windowStart++;
}
​
ans = max(ans, windowEnd - windowStart + 1);
}
return ans;
}
```
​
### BRUTE
​
**Analysis:
T(C)=O(n2)
S(C)=O(n2)**
​
```c++
int totalFruit(vector<int>& fruits) {
//brute force approach
int ans = 1;
int n = fruits.size();
unordered_map<int,int> our_map;
for(int i = 0; i <= n -2 ; ++i){
++our_map[fruits[i]];
for(int j = i+1 ; j < n ; j++){
++our_map[fruits[j]];
if(our_map.size() <= 2){
ans = max(ans,j-i+1);
}
if(our_map.size() > 2)
break;
}
our_map.clear();
}
return ans;
}
```
​
​