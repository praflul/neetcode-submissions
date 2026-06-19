class Solution {
public:
    int maxArea(vector<int>& heights) {
        // unordered_map<int, int> m;
        int l=0,r=heights.size()-1;
        int res = (r-l)*min(heights[r],heights[l]);
        while(l<r){
            if(heights[r]>heights[l]){
                int temp = heights[l];
                while(heights[l]<=temp&&l<r) l++;
                res=max(res,(r-l)*min(heights[r],heights[l]));
            }
            else{
                int temp = heights[r];
                while(heights[r]<=temp&&l<r) r--;
                res = max(res,(r-l)*min(heights[r],heights[l]));
            }
        }
        return res;
    }
};
