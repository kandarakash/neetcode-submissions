class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,int i, int j, int index){
        int n = board.size();
        int m = board[0].size();
        if(index == word.size()){
            return true;
        }
        if( i < 0 || j <0||i>=n || j>=m || board[i][j] != word[index]
        || board[i][j] == '#'){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#';
        bool res = solve(board,word,i+1,j,index+1)||solve(board,word,i-1,j,index+1)||solve(board,word,i,j+1,index+1)||solve(board,word,i,j-1,index+1);
        board[i][j] = temp;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0;i<=n-1;i++){
            for(int j = 0;j<=m-1;j++){
                if(solve(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
