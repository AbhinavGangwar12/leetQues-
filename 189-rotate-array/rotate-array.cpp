class Solution {
    private:
        void reverse(vector<int>& nums,int start,int end){
            if(start>= end)return;
            swap(nums[start],nums[end]);
            reverse(nums,start+1,end-1);
        }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if(k<n){
            reverse(nums,0,nums.size()-1);
            reverse(nums,0,k-1);
            reverse(nums,k,nums.size()-1);
        }
    }
};