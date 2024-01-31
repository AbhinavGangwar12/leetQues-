class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // vector<int> buffer(nums[n-1]);
        // for(int i=0;i<buffer.size();i++){
        //     buffer[i] = 0;
        // }
        // for(int i=0;i<n;i++){
        //     buffer[nums[i]]++;
        // }
        // int res_max = 0;
        // int res = -1;
        // for(int i = 0;i<buffer.size();i++){
        //     if(buffer[i] > res_max){
        //         res_max = buffer[i];
        //         res = i;
        //     }
        // }
        // return res;
        int candidate, count = 0;
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
    }
};