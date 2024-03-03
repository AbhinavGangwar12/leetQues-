class Solution {
    private:
        bool matrix_helper(vector<vector<char>>& grid,int row,int col,char target){
    int rows = (row/3) * 3;
    int cols = (col/3) * 3;
    for(int i = 0; i <3;i++){
        for(int j = 0;j<3;j++){
            if(grid[rows+i][cols+j] == target)return false;
        }
    }
    return true;
}

bool helper(vector<vector<char>>& grid,int row,int col,char target){
    // right
    for(int i =1 ; (col + i) < 9;i++){
        if(grid[row][col+i] == target)return false;
    }
    // left
    for(int i =1 ; (col - i) >= 0;i++){
        if(grid[row][col-i] == target)return false;
    }
    // down
    for(int i =1 ; (row + i) < 9;i++){
        if(grid[row+i][col] == target)return false;
    }
    // up
    for(int i =1 ; (row - i) >= 0;i++){
        if(grid[row-i][col] == target)return false;
    }
    return true;
}

bool foo(vector<vector<char>>& board){
     for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == '.'){
                for(char a='1';a <= '9';a++){
                    if(matrix_helper(board,i,j,a) and helper(board,i,j,a)){
                        board[i][j] = a;
                        if(foo(board))return true;
                        else board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}


public:
    void solveSudoku(vector<vector<char>>& board) {
        foo(board);
    }
};