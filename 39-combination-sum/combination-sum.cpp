class Solution {
    public:
    void backtrack(vector<int>& nums,int i,int cumsum,int target,vector<int>& temp,vector<vector<int>>& ans){
        if(cumsum > target)return;
        if(i == nums.size()){
            if(cumsum == target){
                ans.push_back(temp);
            }
            return;
        }
        // including
        cumsum+=nums[i];
        temp.push_back(nums[i]);
        backtrack(nums,i,cumsum,target,temp,ans);
        cumsum-=nums[i];
        temp.pop_back();
        // excluding
        backtrack(nums,i+1,cumsum,target,temp,ans);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(candidates,0,0,target,temp,ans);
        return ans;
    }
};