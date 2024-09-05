class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, char value) {
        int n = board.size();

        for(int i=0; i<n; i++) {
            //row check
            if(board[row][i] == value)
                return false;
            
            //col check
            if(board[i][col] == value) 
                return false;

            //3*3 box check
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == value) 
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        int n = board.size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                //check for empty cell
                if(board[i][j] == '.') {
                    //try to fill with values ranging from 1 to 9
                    for(char val = '1'; val<='9'; val++) {
                        //check for safety
                        if(isSafe(i,j, board, val)) {
                            //insert
                            board[i][j] = val;
                            //recursion sambal lega
                            bool remainingBoardSolution = solve(board);
                            if(remainingBoardSolution == true) {
                                return true;
                            }
                            else {
                                //backtrack
                                board[i][j] = '.';
                            }
                        }
                    }
                    //if 1 se 9 tak koi bhi value se solution
                    //nahi nikla ,current cell pr, 
                    //that means piche kahin pr galti h , 
                    //go back by returning false
                return false;
                }
            }
        }
        //all cells filled 
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};


























class Solution {
public:
    bool is_safe(vector<vector<char>>& board, int i, int j, char number) {
        // same as before        
    }

    bool solve(vector<vector<char>>& board) {
        
        // Check if board is already solved
        bool isSolved = true;
        for(auto& row : board) {
            for(char num : row) {
                if(num == '.') {
                    isSolved = false;
                    break;
                }
            }
            if(!isSolved) break;
        }
        if(isSolved) return true;
        
        int n = board[0].size();
      
        // Backtracking with state save/restore 
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {   
                if(board[i][j]=='.') {
                    for(char num='1'; num<='9'; num++) {
                            
                        if(is_safe(board,i,j,num)) {
                            
                            // Save current value
                            char origNum = board[i][j];
                            
                            board[i][j] = num;
                            bool solved = solve(board);
                            if(solved)
                                return true;
                            
                            // Restore on backtrack
                            board[i][j] = origNum;                             
                        }
                        
                    }
                    return false;
                }
            }
        }
    
        return true;
    }
        
    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board);  
    }
};
Let me know if any part is unclear!

Copy


dont give me a new solution just improve my own solution

A
Sure, here is how we can improve your existing solution to handle pre-solved boards and do proper backtracking state restore:

cpp


Copy code

Explain
class Solution {
public:
    bool is_safe(vector<vector<char>>& board,int i,int j,char number){
    int n = board[0].size();
    for(int k=0;k<n;k++){
        //for checking the row
        if(board[i][k]==number){
            return false;
        }
        //for checking column
        if(board[k][j]==number){
            return false;
        }
        //for checking 3*3 cell
        if(board[3*(i/3)+(k/3)][3*(j/3)+(k%3)] == number){
            return false;
        }
    }
    return true;
    }
    bool solve(vector<vector<char>>& board) {
      
        int n = board[0].size();
      
        // Check already solved 
        bool isSolved = true;
        for(auto& row : board) {
            for(char num : row) {
                if(num == '.') {
                    isSolved = false; 
                    break;
                }
            }
            if(!isSolved) break;
        }
        if(isSolved) return true;
        
        // Backtracking
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){   
                if(board[i][j]=='.') {       
                    for(char number='1';number<='9';number++){
                    
                        if(is_safe(board,i,j,number)){
                            
                            // Save current state
                            char origNum = board[i][j];
                            
                            board[i][j] = num;
                            bool solveRest = solve(board);
                            if(solveRest)
                                return true;
                                
                           // Restore on backtrack
                           board[i][j] = origNum;
                            
                        }
                    }    
                    return false;              
                }
            }
        }
        return true;
    }

    // Other methods same as before
        bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board);
        }
        
    };
    
