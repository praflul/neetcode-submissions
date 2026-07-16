class Solution {
public:
    void bfs(vector<vector<int>> &adj,vector<bool> &visited,int src){
        queue<int> q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            int node=q.front(); q.pop();
            for(int child: adj[node]){
                if(!visited[child]){
                    q.push(child);
                    visited[child]=true;
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
        int res=0;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                res++;
                bfs(adj,visited,i);
            }
        }
        return res;
    }
};
