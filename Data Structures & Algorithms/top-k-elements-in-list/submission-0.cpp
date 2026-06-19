class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        vector<vector<int>> freq(nums.size()+1);
        for(int i:nums){
            count[i]++;
        }
        for(const auto& p : count){
            freq[p.second].push_back(p.first);
        }
        vector<int> res;
        for(int i=freq.size()-1;i>0;i--){
            for(int j : freq[i]){
                res.push_back(j);
                if(res.size()==k){
                    return res;
                }
            }
        }
    }
};
