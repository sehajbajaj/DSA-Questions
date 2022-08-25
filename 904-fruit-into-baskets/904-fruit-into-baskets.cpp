class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      int i =0, j = 0;
      int ans = -1;
      unordered_map<int, int> m;
        int k = 2;


      while(j < fruits.size()){
        m[fruits[j]]++;

        if(m.size() <= k){
          ans = max(ans, j-i+1);
          j++;
        }else if(m.size() > k){
          while(m.size() > k){
            m[fruits[i]]--;
            if(m[fruits[i]] == 0){
              m.erase(fruits[i]);
            }
            i++;
          }
          if(m.size() <= k){
            ans = max(ans, j-i+1);
          }
          j++;
        }
      }
      return ans;
    }
};