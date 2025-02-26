// USED dfs to count number of connected components, which is simply the number of dfs calls to traverse whole graph
// TC O(n^2) ,SC:O(n^2)
class Solution {
public:
    void dfs(vector<vector<int>> adj,vector<bool>& visited,int node){
        visited[node]=true;
        for(int i=0;i<adj[node].size();i++){
            if(adj[node][i] && !visited[i]){
                dfs(adj,visited,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt=0;
        vector<bool> visited(isConnected.size(),false);
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                dfs(isConnected,visited,i);
                cnt++;
            }
        }
        return cnt;
    }
};
