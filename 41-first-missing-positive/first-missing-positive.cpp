class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> b(nums.size()+1);
        for(auto i : nums){
            if(i>0 and i<=nums.size()){
                b[i] = true;
            }
        }
        for(int i=1;i<b.size();i++){
            if(b[i] == false)return i;
        }
        return nums.size()+1;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]>0 and nums[i]<nums.size()){
        //         swap(nums[i],nums[nums[i]]);
        //         nums[i] = INT_MIN;
        //     }
        // }
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i] != INT_MIN){
        //         return i+1;
        //     }
        // }
        // return nums.size() + 1;
    }
};