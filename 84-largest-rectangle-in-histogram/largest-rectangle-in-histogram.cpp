class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int max_area = 0;
        int n = heights.size();
        for(int i=0;i<=n;i++){
            while( (!s.empty()) and  (i==n or heights[i] < heights[s.top()])){
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? i : i - s.top() - 1;
                max_area = max(max_area , (h*w));
            }
            s.push(i);
        }
        return max_area;
    }
};