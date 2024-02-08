class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> temp(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            temp[nums[i]]++;
        }
        int ans;
        for(int i=0;i<nums.size();i++){
            if(temp[i] > 1)ans = i;
        }
        return ans;
    }
};