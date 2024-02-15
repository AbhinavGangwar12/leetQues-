class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<long long> prefix_sum;
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            prefix_sum.push_back(sum);
        }
        for(int i=nums.size()-1;i>=2;i--){
            if(nums[i] < prefix_sum[i-1])return prefix_sum[i];
        }
        return -1;
    }
};