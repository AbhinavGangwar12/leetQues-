class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int least_so_far = INT_MAX;
        int pist = 0;
        int p = 0;
        for(int i = 0;i<prices.size();i++){
            if(prices[i] < least_so_far){
                least_so_far = prices[i];
            }
            pist = prices[i] - least_so_far;
            if(p < pist){
                p = pist;
            }
        }
        return p;
    }
};