class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        int count = 0;
        int n = nums.size();
        int sum = 0;
        m[0] = 1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem = sum-k;
            count += m[rem];
            m[sum] += 1;
        }
        return count;
    }
};