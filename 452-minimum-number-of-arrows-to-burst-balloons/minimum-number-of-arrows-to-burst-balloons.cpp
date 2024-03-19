class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort(points.begin(),points.end());
        // int size = points.size();
        // vector<int> map(size,1);
        // for(int i = 0,j=size-1;i<j;i++,j--){
        //     int x = 1;
        //     if(points[i][1] == points[j][0]){
        //         x = 0;
        //         map[i] = 0;
        //         map[j] = 0;
        //     }
        //     if(x==1)break;
        // }
        // int ans = 0;
        // for(int i=0;i<size;i++){
        //     if(map[i]!=0){
        //         for(int j = i+1;j < size;j++){
        //             if((i!=j)and(map[j] != 0)and(points[i][1] >= points[j][0])){
        //                 map[j] = 0;
        //             }
        //         }
        //         ans++;
        //         map[i] = 0;
        //     }
        // }
        // return ans;
        if (points.empty()) return 0;
        
        sort(points.begin(), points.end());
        
        int arrows = 1;
        int end = points[0][1];
        
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > end) {
                arrows++;
                end = points[i][1];
            } else {
                end = min(end, points[i][1]);
            }
        }
        
        return arrows;
    }
};