### Using 2-ptr approach
​
- Take res = 1.
- Traverse over the array starting from 1.
- While traversing, check if number at i and res-1 are not same, shift the i-th element to res-th position.
- Do nothing if equal.
​
### TC -> O(N) and SC -> O(1)
**Time taken: 11ms, 90.81%**
​
```
int removeDuplicates(vector<int>& nums) {
int res = 1;
for(int i = 1; i < nums.size(); i++){
if(nums[i] != nums[res-1]){
nums[res] = nums[i];
res++;
}
}
return res;
}
```