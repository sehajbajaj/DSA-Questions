#### Using Recursion & HashMap.
​
* Here we’ll first take all the elements count in hashmap, as there could be duplicated elements, this will help us not to take the same elements twice for the same location.
* In our help function, we’ll pass the index value and given array size.
* Base condition when current index will be equal to given array size then we’ll push temp in ans vector, if(index == n) ans.push_back(temp)
* Else we’ll iterate the map & push value one by one to temp, at any point if the map value became 0, we’ll continue from that.
* After the function call, we’ll remove the current element from temp & run the loop again.
​
#### Time complexity: O(n*k), where k is the size of unique elements & n is the size of given array.
​