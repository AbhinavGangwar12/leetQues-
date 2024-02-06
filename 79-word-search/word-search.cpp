class Solution {
    private:
       bool helper(vector<vector<char>>& board, string word,int x,int y,int k,int row,int col){
           if(k >= word.size())return true;
           if(word.size() == 1 && word[k] == board[x][y])return true;
           if(x<0 || x>=row || y<0 || y>=col || board[x][y] == '#' || word[k] != board[x][y])return false;
           board[x][y] = '#';
           int xco[4] = {0,0,1,-1};
           int yco[4] = {1,-1,0,0};
           bool ret = false;
           for(int index = 0;index < 4;index++){
               ret = ret || helper(board,word,x+xco[index],y+yco[index],k+1,row,col);
           }
           board[x][y] = word[k];
           return ret;
       }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        if(row == 0)return false;
        int col = board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(word[0] == board[i][j]){
                    if(helper(board,word,i,j,0,row,col))return true;
                }
            }
        }
        return false;
    }
};