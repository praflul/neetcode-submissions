// class Solution {
// public:
//     bool isCycle(vector<vector<int>>& adj,vector<bool> &visited,int node,int parent){
//         if(visited[node]) return true;
//         visited[node]=true;
//         for(int child:adj[node]){
//             if(child!=parent&&isCycle(adj,visited,child,node)) return true;
//         }
//         return false;
//     }
//     bool validTree(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> adj(n);
//         vector<bool> visited(n,false);
//         for(int i=0;i<edges.size();i++){
//             adj[edges[i][0]].push_back(edges[i][1]);
//             adj[edges[i][1]].push_back(edges[i][0]);
//         }
//         if(isCycle(adj,visited,0,-1)) return false;
//         for(int i=0;i<n;i++) if(!visited[i]) return false;
//         return true;
//     }
// };
class DSU{
public:
    vector<int> parent,size;
    int count;
    // bool cycle;
    DSU(int n){
        // cycle=false;
        count=n;
        parent.resize(n);
        size.resize(n,1);
        iota(parent.begin(),parent.end(),0);
    };
    int find(int node){
        if(parent[node]==node) return node;
        parent[node]=find(parent[node]);
        return parent[node];
    }
    bool unite(int a,int b){
        int ra=find(a),rb=find(b);
        if(ra==rb) return false;
        if(size[ra]<size[rb]) swap(ra,rb);//ra is larger
        parent[rb]=ra;
        size[ra]+=size[rb];
        count--;
        return true;
    }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto& edge: edges){
            if(!dsu.unite(edge[0],edge[1])) return false;
        }
        if(dsu.count==1) return true;
        return false;
    }
};
