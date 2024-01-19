class Solution {
public:
    int minimum(int a,int b,int c){
        return min(a, std::min(b, c));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 1)return *min_element(matrix[0].begin(),matrix[0].end());
        for(int i = 1;i<row;i++){
            for(int j=0;j<row;j++){
                int left = (j>0) ? matrix[i-1][j-1] : INT_MAX;
                int mid = matrix[i-1][j];
                int right = (j<row-1) ? matrix[i-1][j+1] : INT_MAX;
                matrix[i][j] += minimum(left,mid,right);
            }
        }
        return *min_element(matrix[row-1].begin(),matrix[row-1].end());
    }
};