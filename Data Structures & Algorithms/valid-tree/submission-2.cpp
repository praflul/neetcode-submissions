class Solution {
public:
    bool isCycle(vector<vector<int>>& adj,vector<bool> &visited,int node,int parent){
        if(visited[node]) return true;
        visited[node]=true;
        for(int child:adj[node]){
            if(child!=parent&&isCycle(adj,visited,child,node)) return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        if(isCycle(adj,visited,0,-1)) return false;
        for(int i=0;i<n;i++) if(!visited[i]) return false;
        return true;
    }
};
