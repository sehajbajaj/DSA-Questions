class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        
        vector<int> colorArray(n, -1);
        for(int i = 0; i < n; i++){
            if(colorArray[i] == -1){
                if(bfs(i, graph, colorArray) == false){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool bfs(int node, vector<vector<int>> &graph, vector<int> &colorArray){
        queue<int> q;
        q.push(node);
        colorArray[node] = 1;
        
        while(!q.empty()){
            int currentNode = q.front();
            q.pop();
            
            for(auto it : graph[currentNode]){
                if(colorArray[it] == -1){
                    q.push(it);
                    colorArray[it] = 1 - colorArray[currentNode];
                }else if(colorArray[it] == colorArray[currentNode]){
                    return false;
                }
            }
        }
        return true;
    }
};