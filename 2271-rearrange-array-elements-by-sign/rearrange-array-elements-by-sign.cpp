class Solution {
    private:
    void swap(int& n,int& m){
        int temp = n;
        n = m;
        m = temp;
    }
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // int low=0,high = nums.size()-1;
        // while(low < high){
        //     while((low%2==0 && nums[low] > 0 && low<nums.size()) || (low%2!=0 && nums[low] < 0 && low < nums.size())){
        //         low++;
        //     }
        //     while((high%2==0 && nums[high] > 0 && high >-1) || (high%2!=0 && nums[high] < 0 && high >-1)){
        //         high--;
        //     }
        //     if(low < high){swap(nums[low],nums[high]);}
        // }
        // return nums;
        int n = nums.size();
        int m = n/2;
        vector<int> positive;
        vector<int> negative;
        for(int i=0;i<n;i++){
            if(nums[i] < 0)negative.push_back(nums[i]);
            else if(nums[i] > 0)positive.push_back(nums[i]);
        }
        vector<int> ans;
        for(int i=0;i<m;i++){
            ans.push_back(positive[i]);
            ans.push_back(negative[i]);
        }
        return ans;
    }
};