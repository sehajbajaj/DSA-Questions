class Solution {
public:
    void dfs(int node, vector<int> adj[], bool vis[]){
        vis[node] = true;
        
        for(auto nbr : adj[node]){
            if(vis[nbr] == false){
                dfs(nbr, adj, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        vector<int> adj[n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 and i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        bool vis[n];
        for(int i = 0; i < n; i++){
            vis[i] = false;
        }
        
        int noOfProvinces = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == false){
                noOfProvinces++;
                dfs(i, adj, vis);
            }
        }
        return noOfProvinces;
    }
};