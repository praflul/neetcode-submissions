class Solution {
public:
    int calcHours(vector<int>& piles, int k){
        int hours=0;
        for(int i=0;i<piles.size();i++){
            hours+=(piles[i] + k - 1) / k;
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = 0;
        for (int p : piles) maxPile = max(maxPile, p);

        int left = 1, right = maxPile;
        int res = maxPile;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (calcHours(piles, mid) <= h) {
                res = mid;    
                right = mid - 1; 
            } else {
                left = mid + 1;  
            }
        }
        return res;
    }
};
