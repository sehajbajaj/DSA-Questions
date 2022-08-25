### Brute Force

- One basic idea would be to traverse the height[] array and add the water trapped at each tower. The critical question is: how do we find the amount of water trapped by any tower height[i]? Let's think!
- We initialize the variable trappedWater to store the total trapped water with 0.
- Now we traverse the height[] from from i = 0 to n - 1. Inside the loop, we initialize variables leftMaxHeight and rightMaxHeight to store the maximum height of the tower on the left and right sides of the current tower height[i]. For each height[i]:
- We run a loop from j = i to 0 and find the maximum height of the tower on the left side. We store this value in the variable leftMaxHeight.
- Similarly, we run a loop from j = i to n - 1 and find the maximum height of the tower on the right side. We store this value in the variable rightMaxHeight.
- trappedWater = trappedWater + min(leftMaxHeight, rightMaxHeight) - height[i]

## TC -> O(N2) and SC -> O(1)

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int trappedWater = 0;
        
        for(int i = 0; i < height.size(); i++){
            int leftMaxHeight = 0, rightMaxHeight = 0;
            
            for(int j = i; j >= 0; j--){
                leftMaxHeight = max(leftMaxHeight, height[j]);
            }
            
            for(int j = i; j < height.size(); j++){
                rightMaxHeight = max(rightMaxHeight, height[j]);
            }
            
            trappedWater += min(leftMaxHeight, rightMaxHeight) - height[i];
        }
        return trappedWater;
    }
};
```

### Using Extra Space 

- One idea would be to do some pre-processing to calculate both values for each tower and store them in two separate extra memory of size n.
- If we know the left[i - 1], then we can easily calculate the left[i] in O(1). Here is the formula: left[i] = max (left[i - 1], height[i]).
- Similarly, if we know right[i + 1], then we can easily calculate the right[i] in O(1). Here is the formula: right[i] = max (right[i + 1], height[i]).
- Now, we traverse the height[] array and calculate the total amount of water.

### TC -> O(N) ans SC -> O(2N)

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int trappedWater = 0;
        
        int n = height.size();
        int leftMaxHeight[n], rightMaxHeight[n];
        
        leftMaxHeight[0] = height[0];
        for(int i = 1; i < n; i++){
            leftMaxHeight[i] = max(leftMaxHeight[i-1], height[i]);
        }
        
        rightMaxHeight[n-1] = height[n-1];
        for(int i= n-2; i >= 0; i--){
            rightMaxHeight[i] = max(rightMaxHeight[i+1], height[i]);
        }
        
        for(int i = 0; i < n; i++){
            trappedWater += min(leftMaxHeight[i], rightMaxHeight[i]) - height[i];
        }
        return trappedWater;
    }
};
```

### Using Stack 

- The idea would be to track the area confined between the current tower and all the previous smaller towers in a sequence.
- We create a stack S to store the indices of the towers.
- Now we traverse the height[] array using a loop: while(i < n).
- If we found a current tower height[i] larger than the tower at the top of the stack, we can say that the tower at the top is confined between the current tower and a previous tower in the stack. Hence, we pop the value from the stack and add water trapped between towers to the total water trapped. We can continue this step in a loop until we find the current tower smaller than the tower at the top of the stack or the stack becomes empty.
	- Region length = current index - index of the top stack element - 1
	- Region height = min (height of the current tower, height of tower at the top of the stack) - the height of the popped tower
	- Water trapped = Region length x Region height
- If the current tower is smaller than or equal to the tower at the top, we push the index of the current tower to the stack and move to the next tower height[i]. It means the current tower is confined with the tower at the top of the stack.

### TC -> O(N) and SC -> O(N)

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int trappedWater = 0;
        
        for(int i = 0; i < height.size(); i++){
            while(!s.empty() and height[i] > height[s.top()]){
                int tp = s.top();
                s.pop();
                
                if(s.empty()){
                    break;
                }
                
                int regionLength = i - s.top() - 1;
                int regionHeight = min(height[i], height[s.top()]) - height[tp];
                
                trappedWater += regionLength * regionHeight;
            }
            s.push(i);
        }
        return trappedWater;
    }
};
```

### Using 2 pointers

- Based on the formula used in the 2nd approach, the water trapped by any tower depends on the minimum of maximum height of towers on both sides. So instead of maintaining two arrays of size n for storing leftMaxHeight and a rightMaxHeight, can we think of maintaining two variables to store the maximum till a given point? Think!
- We first calculate the water trapped on smaller elements out of height[left] and height[right], then move the pointer associated with the smaller element. We move the pointers till the left doesn't cross the right. In terms of an analogy, we can think of height[left] and height[right] as a wall of a partial container where we fix the higher one and flow water from the lower part. Think!
	- We declare and Initialise left and right pointers.
	- We also Initialise variables trappedWater, leftMaxHeight, and rightMaxHeight.
	- Now we run a loop to scan the array i.e. while (left <= right)
		- If (height[left] < height[right]) and (height[left] < leftMaxHeight), then we calculate the trapped water stored by the both towers and increase the left pointer. But if (height[left] > leftMaxHeight), then we update value of leftMaxHeight and increase the left pointer.
		- If (height[left] > height[right]) and height[right] < rightMaxHeight), then we calculate the trapped water stored by the both towers and decrease the right pointer. But if (height[right] > rightMaxHeight), then we update value of rightMaxHeight and decrease the right pointer.

### TC ->O(N) and SC -> O(1)

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int trappedWater = 0;
        int leftMaxHeight = 0, rightMaxHeight = 0;
        
        while(left <= right){
            if(height[left] < height[right]){
                if(height[left] > leftMaxHeight){
                    leftMaxHeight = height[left];
                }else{
                    trappedWater += leftMaxHeight - height[left];
                }
                left++;
            }else{
                if(height[right] > rightMaxHeight){
                    rightMaxHeight = height[right];
                }else{
                    trappedWater += rightMaxHeight - height[right];
                }
                right--;
            }
        }
        return trappedWater;
    }
};
```
