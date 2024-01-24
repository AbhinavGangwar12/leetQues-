class Solution {
    private:
        void solution(vector<int> nums,int index,vector<int> temp,vector<vector<int>>& ans){
            if(index >= nums.size()){
                ans.push_back(temp);
                return;
            }

            solution(nums,index+1,temp,ans);
            temp.push_back(nums[index]);
            solution(nums,index+1,temp,ans);
        }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector<int>> ans;
        vector <int> temp;
        solution (nums,0,temp,ans);
        return ans;
    }
};