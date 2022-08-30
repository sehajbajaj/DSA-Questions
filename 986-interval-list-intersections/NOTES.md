### Using 2-ptrs
​
**Valid intersection will only be when the start point is less than or equal to end point.**
​
- Find the start and the end points of the interval that can be an intersection.
- start = max of starting intervals of both the lists
- end = min of ending intervals of both the lists
- Check if the interval formed is valid or not. (start <= end)
- Push in the ans vector.
- Check if the end point of interval in 1st list is less than end point in the 2nd list, increment ptr1, else increment ptr2.
​
### TC -> O(N) and SC -> O(N)