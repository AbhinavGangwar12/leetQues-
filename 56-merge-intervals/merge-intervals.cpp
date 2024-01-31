class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        if(n == 1){
            return ans;
        }
        int i=0,j=1;
        while(j<n){
            if(ans[i][1] >= intervals[j][0]){
                int x = ans[i][0];
                int y = (ans[i][1] > intervals[j][1]) ? ans[i][1] : intervals[j][1] ;
                ans.pop_back();
                ans.push_back({x,y});
                j++;
            }
            else {
                i++;
                ans.push_back(intervals[j++]);
            }
        }
        return ans;
    }
};