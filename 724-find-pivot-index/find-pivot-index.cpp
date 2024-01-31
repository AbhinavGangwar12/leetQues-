class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left_sum[nums.size()];
        int right_sum[nums.size()];
        int ls = 0,rs = 0;
        int i=0,j = nums.size()-1;
        while(i<nums.size() && j > -1){
            ls += nums[i];
            left_sum[i++] = ls;
            rs += nums[j];
            right_sum[j--] = rs;
        }
        for(int i = 0;i<nums.size();i++){
            if(left_sum[i] == right_sum[i])return i;
        }
        return -1;
    }
};