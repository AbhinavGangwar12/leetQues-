class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]*nums[i]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};