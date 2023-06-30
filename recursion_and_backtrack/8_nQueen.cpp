//Recursion && Backtracking

class Solution {
public:

    bool isSafe(int row, int col, vector<string> board, int n){
        int dup_row = row;
        int dup_col = col;

        while(row >= 0 && col >=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }

        row = dup_row;
        col = dup_col;

        while(col >= 0){
            if(board[row][col]=='Q') return false;
            col--;
        }

        row = dup_row;
        col = dup_col;

        while(row < n && col >=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }

        return true;
    }

    void nQueen(vector<vector<string>> &ans, vector<string> &ds, int n, int col){
        if(col == n){
            ans.push_back(ds);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row, col, ds, n)){
                ds[row][col] = 'Q';
                nQueen(ans, ds, n, col+1);
                ds[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> ds;
        string s;
        for(int i=0;i<n;i++) s+='.';
        for(int i=0;i<n;i++) ds.push_back(s);

        nQueen(ans, ds, n, 0);

        return ans;
    }
};




//Hashing Approach

class Solution {
public:
    void nQueen(vector<vector<string>> &ans, vector<string> &board, int n, int col, vector<int> &leftrow, vector<int> &updiag, vector<int> &lowdiag){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && updiag[n-1+col-row]==0 && lowdiag[row + col]==0){
                board[row][col] = 'Q';
                leftrow[row]=1;
                updiag[n-1+col-row]=1;
                lowdiag[row+col]=1;
                nQueen(ans, board, n, col+1, leftrow, updiag, lowdiag);
                leftrow[row]=0;
                updiag[n-1+col-row]=0;
                lowdiag[row+col]=0;
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s;
        for(int i=0;i<n;i++) s+='.';
        for(int i=0;i<n;i++) board.push_back(s);
        vector<int> leftrow(n), updiag(2*n-1), lowdiag(2*n-1);
        nQueen(ans, board, n, 0, leftrow, updiag, lowdiag);

        return ans;
    }
};
