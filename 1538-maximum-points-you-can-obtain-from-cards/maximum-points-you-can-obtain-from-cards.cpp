class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // vector<int> prefix(cardPoints.size());
        // int sum = 0;
        // for(int i=0;i<cardPoints.size();i++){
        //     sum += cardPoints[i];
        //     prefix.push_back(sum);
        // }
        // int maxi = INT_MIN;
        // for(int i = k-1;i<prefix.size();i++){
        //     if( (i-k)>=0){
        //         int sum = prefix[i] - prefix[i-k];
        //         maxi = max(maxi,sum);
        //     }
        // }
        // return maxi;
        int ans = 0,size = cardPoints.size();
        for(int i=0;i<k;i++){
            ans+=cardPoints[i];
        }
        int curr = ans;
        for(int i=0;i<k;i++){
            curr = curr - cardPoints[k-i-1] + cardPoints[size-i-1];
            ans = max(ans,curr);
        }
        return ans;
    }
};