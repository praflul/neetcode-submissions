class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix[0].size(),n=matrix.size();
        int l=0,r=n*m-1;
        int mid;
        while(l<=r){
            mid=(l+r)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]<target) l=mid+1;
            else if (matrix[row][col]>target) r=mid-1;
            else return true;
        }
        return false;
    }
};
