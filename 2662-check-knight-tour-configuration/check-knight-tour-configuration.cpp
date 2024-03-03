class Solution {
    const int moves[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
    // bool isValid(vector<vector<int>>& temp,int row,int col){
    //     int size = temp.size();
    //     if((row < size) and (row >= 0) and (col < size) and (col >= 0) and (temp[row][col] == -1))return true;
    //     return false;
    // }
    // bool tour(vector<vector<int>>& grid,int row,int col,int move_count,int max_moves){
    //     if(move_count == max_moves)return true;
    //     for(int i = 0;i<8;i++){
    //         int next_row = row + moves[i][0];
    //         int next_col = col + moves[i][1];
    //         if(isValid(grid,next_row,next_col)){
    //             grid[next_row][next_col] = move_count;
    //             if(tour(grid,next_row,next_col,move_count+1,max_moves))return true;
    //             grid[next_row][next_col] = -1;
    //         }
    //     }
    //     return false;
    // }
    bool isValid(vector<vector<int>>& temp,int row,int col){
        int size = temp.size();
        if((row < size) and (row >= 0) and (col < size) and (col >= 0))return true;
        return false;
    }
    bool tour(vector<vector<int>>& grid,int row,int col,int move_count,int max_moves){
        if(move_count == max_moves)return true;
        for(int i = 0;i<8;i++){
            int next_row = row + moves[i][0];
            int next_col = col + moves[i][1];
            if(isValid(grid,next_row,next_col) and grid[next_row][next_col] == move_count){
                if(tour(grid,next_row,next_col,move_count+1,max_moves))return true;
            }
        }
        return false;
    }
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0] != 0)return false;
        int SIZE = grid.size();
        // vector<vector<int>> temp(SIZE,vector<int>(SIZE,-1));
        // int row = 0,col = 0;
        // temp[row][col] = 0;
        int max_moves = SIZE*SIZE;
        // if(tour(temp,row,col,1,max_moves))return true;
        // return false;

        return tour(grid,0,0,1,max_moves);
    }
};