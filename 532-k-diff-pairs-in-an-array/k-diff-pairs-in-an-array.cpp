class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // vector<pair<int,int>> v;
        // sort(nums.begin(),nums.end());
        // int count = 0;
        // int n = nums.size();
        // for(int i=0;i<n-1;i++){
        //     int low = i,high = n-1;
        //     while(low <= high){
        //         int diff = abs(nums[low] - nums[high]);
        //         pair<int,int> p = make_pair(nums[low],nums[high]);
        //         if(diff == k and low<=high){
        //             if(find(v.begin(),v.end(),p) == v.end()){
        //                 count++;
        //             }
        //             low++;
        //             high--;
        //         }
        //         else if(diff < k)low++;
        //         else high--;
        //     }
        // }
        // return count;
        map<int,int> f;
        int n = nums.size();
        for(int i=0;i<n;i++){
            f[nums[i]]++;
        }
        int count = 0;
        for(auto i : f){
            if(k == 0){
                if(i.second>1)count++;
            }
            else{
                int x = i.first;
                int r = x - k;
                if(f.find(r) != f.end()){
                    count++;
                }
            }
        }
        return count;
    }
};