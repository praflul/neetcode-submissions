class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> prevMap;

        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];
            if (prevMap.contains(diff)) {
                return {prevMap[diff], i};
            }
            prevMap[nums[i]]=i;
        }
    }
};
