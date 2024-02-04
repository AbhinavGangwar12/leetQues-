class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        int left_column = 0;
        int right_column = columns -1;
        int up_row = 0;
        int down_row = rows-1;
        vector<int> ans;
        int count = 0,limit = rows*columns;

        while(count<limit){
            for(int i = left_column ;count<limit && i <= right_column ; i++){
                ans.push_back(matrix[up_row][i]);
                count++;
            }
            up_row++;

            for(int i = up_row ;count<limit && i <= down_row ; i++){
                ans.push_back(matrix[i][right_column]);
                count++;
            }
            right_column--;
            
            for(int i = right_column ;count<limit && i >= left_column ; i--){
                ans.push_back(matrix[down_row][i]);
                count++;
            }
            down_row--;

            for(int i = down_row ;count<limit && i >= up_row ; i--){
                ans.push_back(matrix[i][left_column]);
                count++;
            }
            left_column++;
        }
        return ans;
    }
};