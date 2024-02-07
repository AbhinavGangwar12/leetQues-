class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        vector<int> temp(60,0);
        for(int i=0;i<time.size();i++){
            int var = time[i]%60;
            if(var == 0)count += temp[0];
            else count += temp[60-var];
            temp[var]++;
        }
        return count;
    }
};