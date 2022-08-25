### Using cyclic Sort
​
- While traversing over the list, keep checking the following:
- If current element is not equal to i+1 => means its not the right element for current position.
- Check if the current element is not at correct position (current element -1), swap the current element with the element at the correct position.
- Else return the current element because if this element is already at its correct position but the position that's holding it is not correct => its a duplicate element (one is at the right position and the duplicate one is at the wrong position).
- Else do the next iteration, i++. (the current position holds the right element)
- Return -1 if no duplicate
​
### TC -> O(N) and SC -> O(1)
​
**Time taken: 132 ms, 87.16%**
```
int findDuplicate(vector<int>& nums) {
int i = 0;
while(i < nums.size()){
if(nums[i]!= i+1){
int correct = nums[i]-1;
if(nums[i]!= nums[correct]){
swap(nums[i], nums[correct]);
}else{
return nums[i];
}
}else{
i++;
}
}
return -1;
}
}
```
​