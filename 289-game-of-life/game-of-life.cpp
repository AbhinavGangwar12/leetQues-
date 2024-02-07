class Solution {
    private:
    bool helper(vector<vector<int>>& board,int i,int j,int m,int n){
        int live = 0;
        int x[8] = {0,1,1,1,0,-1,-1,-1};
        int y[8] = {1,1,0,-1,-1,-1,0,1};
        for(int _ = 0;_ < 8;_++){
            int a = i + x[_];
            int b = j + y[_];
            if((a>-1 && a<m) && (b>-1 && b<n)){
                if(board[a][b] == 1)live++;
            }
        }
        if((board[i][j] == 0 && live == 3) || (board[i][j] == 1 && live == 2) || (board[i][j] == 1 && live == 3)){
            return true;
        }
        return false;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> temp(m, vector<int>(n, 0));
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         temp[i][j] = 0;
        //     }
        // }
        for(int i=0;i<m;i++){
            for(int j = 0;j < n;j++){
                temp[i][j] = helper(board,i,j,m,n);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j] = temp[i][j];
            }
        }
    }
};