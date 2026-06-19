class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int res=0;
        // unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            int cons=0;
            s.insert(nums[i]);
            int num=nums[i];
            while(s.contains(num)){
                cons++;
                num--;
            }
            num=nums[i];
            while(s.contains(num)){
                cons++;
                num++;
            }
            if(--cons>res){
                res=cons;
            }
            // m[nums[i]]=--cons;
        }
        // for(const auto& entry : m){
        //     cout<<entry.first<<"="<<entry.second<<endl;
        // }
        return res;
    }
};
