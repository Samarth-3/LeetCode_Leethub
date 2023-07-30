class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++){
           vector<bool> rowCheck(9, false);
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int num = board[i][j] - '1';
                    if(rowCheck[num]==true){
                        return false;
                    }
                    rowCheck[num]=true;
                }
            }
        }
        
        for(int j=0;j<9;j++){
           vector<bool> colCheck(9, false);
            for(int i=0;i<9;i++){
                if(board[i][j]!='.'){
                    int num = board[i][j] - '1';
                    if(colCheck[num]==true){
                        return false;
                    }
                    colCheck[num]=true;
                }
            }
        }
        
        for(int i=0;i<9;i++){
            int rowStart=(i/3)*3;
            int colStart=(i%3)*3;
            vector<bool> boxCheck(9, false);
            for(int j=rowStart;j<rowStart+3;j++){
                for(int w=colStart;w<colStart+3;w++){
                    if(board[j][w]!='.'){
                        int num = board[j][w] - '1';
                        if(boxCheck[num]){
                            return false;
                        }
                        boxCheck[num]=true;
                    }
                }
            }
        }
        
       return true; 
    }
};