### The idea is to use sliding window approach + Hashing.

He can pick only 2 type of toys, quantity can be anything. Same goes for the basket we have 2 baskets and one basket can have only 1 type of fruit.
The problem boils down to the problem of longest substring with k unique characters. Variable sized sliding window approach.
Here k is always 2 according to the given condition.

- If map.size() < k, increment j to find the window.
- If window found, calculate the answer.
- If map.size() > k, it means that he has picked more than 2 types of toys so remove the calculation for the first toy in that window. If becomes 0, erase from the map and do check again if the window size is obtained, calculate the answer.

#### Optimal Analysis:

**T(C)=O(n)

S(C)=O(n)**


### Optimal-2

```c++
int totalFruit(vector<int>& fruits) {
       int windowStart = 0;
        int ans = -1;
        unordered_map<int, int> m;

        for (int windowEnd = 0; windowEnd < fruits.size(); windowEnd++) {
          m[fruits[windowEnd]]++;

          while (m.size() > 2) {
            m[fruits[windowStart]]--;
            if (m[fruits[windowStart]] == 0) {
              m.erase(fruits[windowStart]);
            }
            windowStart++;
          }

          ans = max(ans, windowEnd - windowStart + 1);
        }
        return ans;
    }
 ```
    
### BRUTE
Analysis:
T(C)=O(n2)
S(C)=O(n2)

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
