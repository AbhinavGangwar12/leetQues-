class Solution {
    private:
    
bool helper(vector<string> grid,int curr_column, int curr_row,int size){
    // up
    for(int i=1;(curr_row - i ) >= 0;i++){
        if(grid[curr_row - i][curr_column] == 'Q')return false;
    }
    // down
    for(int i=1;(curr_row + i ) < size ;i++){
        if(grid[curr_row + i][curr_column] == 'Q')return false;
    }
    // left
    for(int i=1;(curr_column - i ) >= 0;i++){
        if(grid[curr_row][curr_column-i] == 'Q')return false;
    }
    // right
    for(int i=1;(curr_column + i ) < size;i++){
        if(grid[curr_row][curr_column+i] == 'Q')return false;
    }
    // diagonals
    // up
    for(int i=1;(curr_row - i ) >= 0 && (curr_column - i) >= 0;i++){
        if(grid[curr_row - i][curr_column - i] == 'Q')return false;
    }
    // down
    for(int i=1;(curr_row + i ) < size && (curr_column + i) < size;i++){
        if(grid[curr_row + i][curr_column +i] == 'Q')return false;
    }
    // second d_up
    for(int i=1;(curr_row - i ) >= 0 && (curr_column + i) < size;i++){
        if(grid[curr_row - i][curr_column +i] == 'Q')return false;
    }
    // second d_down
    for(int i=1;(curr_row + i ) < size && (curr_column - i) >= 0;i++){
        if(grid[curr_row + i][curr_column -i] == 'Q')return false;
    }
    return true;
}

void foo(vector<string> &grid,int row,int size,vector<vector<string>> &ans){
    if(row >= size){
        ans.push_back(grid);
        return;
    }
    for(int x = 0;x<size;x++){
        if(helper(grid,x,row,size)){
            grid[row][x] = 'Q';
            foo(grid,row+1,size,ans);
            grid[row][x] = '.';
        }
    }
    return;
}
public:
    vector<vector<string>> solveNQueens(int n) {
         vector<string> grid(n,string(n,'.'));
        vector<vector<string>> ans;
        foo(grid,0,n,ans);
        return ans;
    }
};