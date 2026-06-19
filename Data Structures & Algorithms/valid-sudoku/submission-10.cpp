class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_set<char> s;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(s.contains(board[i][j])){
                        cout<<"1";
                        return false;
                    }
                    s.insert(board[i][j]);
                }
            }
        }
        for(int i=0;i<9;i++){
            unordered_set<char> s;
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    if(s.contains(board[j][i])){
                        // cout<<i<<" "<<j<<board[];
                        return false;
                    }
                    s.insert(board[j][i]);
                }
            }
        }
        for(int i=0;i<9;i++){
            unordered_set<char> s;
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    int row=(i/3)*3+j;
                    int col=(i%3)*3+k;
                    if(board[row][col]=='.') continue;
                    if(s.contains(board[row][col])){
                        cout<<"3";
                        return false;
                    }
                    s.insert(board[row][col]);
                }
            }
        }
        return true;
    }
};
