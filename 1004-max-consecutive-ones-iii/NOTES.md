Similar to character replacement question
​
Can be done in place.
​
### TC -> O(N) and SC -> O(1)
```
int longestOnes(vector<int>& nums, int k) {
int mx = 0;
int l = 0;
int zc = 0;
for(int r = 0; r < nums.size(); r++){
if(nums[r] == 0){
zc++;
}
while(zc > k) {
if(nums[l] == 0){
zc--;
}
l++;
}
mx = max(mx, r-l+1);
}
return mx;
}
```