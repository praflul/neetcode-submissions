class Solution {
public:
    void dfs(vector<int>& nums, vector<int>& subset,vector<vector<int>>& res,int i){
        if(i>=nums.size()){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i++]);
        dfs(nums,subset,res,i);
        subset.pop_back();
        dfs(nums,subset,res,i);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> res;
        int i=0;
        dfs(nums,subset,res,i);
        return res;
    }
};
