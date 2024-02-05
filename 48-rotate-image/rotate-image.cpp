class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for(int i=0;i<size;i++){
            for(int j=i;j<size;j++){
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
        for(int i = 0;i<size;i++){
            int left = 0;
            int right = size-1;
            while(left < right){
                swap(matrix[i][left],matrix[i][right]);
                left++;
                right--;
            }
        }
    }
};