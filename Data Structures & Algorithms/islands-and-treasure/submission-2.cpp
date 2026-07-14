class Solution {
    int INF=2147483647;
    int directions[4][2]={{0,1},{0,-1},
                        {1,0},{-1,0}};
public:
    // int dfs(vector<vector<int>>& grid,vector<vector<int>> &visited,int r,int c){
    //     if(r<0||c<0||r>=grid.size()||c>=grid[0].size()||grid[r][c]==-1||visited[r][c]==1) return -1;
    //     else if(grid[r][c]==0) {
    //         // res[r][c]=0;
    //         return 0;
    //     }
    //     visited[r][c]=1;
    //     vector<int> arr(4,-1);
    //     arr[0]=dfs(grid,visited,r+1,c);
    //     arr[1]=dfs(grid,visited,r-1,c);
    //     arr[2]=dfs(grid,visited,r,c+1);
    //     arr[3]=dfs(grid,visited,r,c-1);
    //     sort(arr.begin(),arr.end());
    //     visited[r][c]=0;
    //     for(int i:arr){
    //         if(i!=-1) return i+1;
    //     }
    //     return -1;
    // }
    // void bfs(vector<vector<int>>& grid,vector<vector<int>> visited,int r,int c){
    //     queue<pair<int,int>> q;
    //     q.push(make_pair(r,c));
    //     while(!q.empty()){
    //         pair<int,int> p=q.front();
    //         q.pop();
    //         for(int i=0;i<4;i++){
    //             int nr=p.first+directions[i][0];
    //             int nc=p.second+directions[i][1];
    //             if(nr>=0&&nc>=0&&nr<grid.size()&&nc<grid[0].size()&&grid[nr][nc]!=0&&grid[nr][nc]!=-1&&visited[nr][nc]==0){
    //                 grid[nr][nc]=min(grid[nr][nc],grid[p.first][p.second]+1);
    //                 visited[nr][nc]=1;
    //                 q.push(make_pair(nr,nc));
    //             }
    //         }
    //     }
    // }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int,int>> q;

        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(grid[r][c]==0){
                    q.push(make_pair(r,c));
                }
            }
        }
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=p.first+directions[i][0];
                int nc=p.second+directions[i][1];
                if(nr>=0&&nc>=0&&nr<grid.size()&&nc<grid[0].size()&&grid[nr][nc]==INF){
                    grid[nr][nc]=min(grid[nr][nc],grid[p.first][p.second]+1);
                    // visited[nr][nc]=1;
                    q.push(make_pair(nr,nc));
                }
            }
        }

        // return grid;
    }
};
