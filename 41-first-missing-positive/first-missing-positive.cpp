class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int x = nums.size();
        vector<bool> b(x+1,false);
        for(auto i : nums){
            if(i>0 and i<=nums.size()){
                b[i] = true;
            }
        }
        for(int i=1;i<b.size();i++){
            if(b[i] == false)return i;
        }
        return x+1;
    }
};