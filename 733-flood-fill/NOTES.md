#### DFS Algo
​
- To perform a flood fill, pixel value connected with same pixel value is required so that we can replace it with the newColor.
- We can go in any of the ways to traverse the nbrs first if they match with the color of the starting point.
- Make a copy of the given image to store the answer.
​
#### TC - O(N) + O(NxMx4) and SC - O(NxM)