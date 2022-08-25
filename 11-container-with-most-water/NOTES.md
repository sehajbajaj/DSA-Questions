### Brute Force
​
- Calculate the area considering every left line and every right line.
- Initialise left = 0 and right as left + 1.
- Keep calculating the area = (right-left) x min(a[left], a[right])
- Also keep calculating the maximum area that will be the final result.
- Basically we will be checking every possible combination of left and right lines forming a container.
​
### TC -> O(N2) and SC -> O(1)
​
```
int maxArea(vector<int>& height) {
int result = 0;
for(int left = 0; left < height.size(); left++){
for(int right = left+1; right < height.size(); right++){
int area = (right-left) * min(height[left], height[right]);
result = max(result, area);
}
}
return result;
}
```
​
### Using 2-ptr approach - we will be using the fact that we don't want minimum heights.
​
- Intialise left = 0 and right = size - 1. This helps us to maximise the width and in turn the area.
- While left < right
- Calculate the area = (right-left) x min(a[right], a[left]).
- Keep calculating the maximum answer.
- How to update the pointers ?
- Always update the pointer with lesser height. i.e if a[left] < a[right], left++ else do right--. The second condition also takes care of the edge case when both the left and right have same heights.
​
### TC -> O(N) and SC -> O(1)
​
​
​