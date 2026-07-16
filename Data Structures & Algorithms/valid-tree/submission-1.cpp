class Solution {
public:
    bool isCycle(vector<vector<int>>& adj,vector<int> &state,int node,int parent){
        if(state[node]==2) return false;
        if(state[node]==1) return true;
        state[node]=1;
        for(int child:adj[node]){
            if(child!=parent&&isCycle(adj,state,child,node)) return true;
        }
        state[node]=2;
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> state(n,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        if(isCycle(adj,state,0,-1)) return false;
        for(int i=0;i<n;i++) if(state[i]==0) return false;
        return true;
    }
};
