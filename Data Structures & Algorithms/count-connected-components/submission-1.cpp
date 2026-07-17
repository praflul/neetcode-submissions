// class Solution {
// public:
//     void bfs(vector<vector<int>> &adj,vector<bool> &visited,int src){
//         queue<int> q;
//         q.push(src);
//         visited[src]=true;
//         while(!q.empty()){
//             int node=q.front(); q.pop();
//             for(int child: adj[node]){
//                 if(!visited[child]){
//                     q.push(child);
//                     visited[child]=true;
//                 }
//             }
//         }
//     }
//     int countComponents(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> adj(n);
//         vector<bool> visited(n,false);
//         int res=0;
//         for(int i=0;i<edges.size();i++){
//             adj[edges[i][0]].push_back(edges[i][1]);
//             adj[edges[i][1]].push_back(edges[i][0]);
//         }
//         for(int i=0;i<n;i++){
//             if(!visited[i]){
//                 res++;
//                 bfs(adj,visited,i);
//             }
//         }
//         return res;
//     }
// };
class DSU{
public:
    vector<int> parent,size;
    int noOfComp;
    DSU(int n){
        size.resize(n,1);
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        noOfComp=n;
    };
    int find(int node){
        if(parent[node]==node) return node;
        parent[node]=find(parent[node]);
        return parent[node];
    }
    bool unite(int a,int b){
        int ra=find(a),rb=find(b);
        if(ra==rb) return false;
        if(size[ra]<size[rb]) swap(a,b);
        parent[rb]=ra;
        size[ra]+=size[rb];
        noOfComp--;
        return true;
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto& edge:edges){
            dsu.unite(edge[0],edge[1]);
        }
        return dsu.noOfComp;
    }
};
