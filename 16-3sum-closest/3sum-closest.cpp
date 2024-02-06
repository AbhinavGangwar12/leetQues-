class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        int min_dif= INT_MAX;
        for(int i = 0;i<nums.size()-1;i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                int temp = nums[i] + nums[j] + nums[k];
                if (temp == target) return temp;
                if(temp > target)k--;
                else j++;
                int dif = abs(temp - target);
                if(dif < min_dif){
                    min_dif = dif;
                    sum = temp;
                }
            }
        }
        return sum;
    }
};