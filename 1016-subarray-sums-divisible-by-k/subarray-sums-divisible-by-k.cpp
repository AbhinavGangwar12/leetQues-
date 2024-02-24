class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // int sum=0;
        // int ans=0;
        // unordered_map<int,int> mp;
        // mp[0]++;
        // for(int i=0;i<nums.size();i++)
        // {
        //     sum+=nums[i];
        //     int rem=sum%k;
        //     if(rem<0)
        //     {
        //         rem+=k;
        //     }
        //     ans+=mp[rem];
        //     mp[rem]++;
        // }
        // return ans;

        vector<int> mod_k(k, 0);
        mod_k[0] = 1;
        
        int sum = 0, count = 0;
        for (int num : nums) {
            sum = (sum + num % k + k) % k;
            count += mod_k[sum];
            mod_k[sum]++;
        }

        return count;

    }
};