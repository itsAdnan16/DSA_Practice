/*#include<iostream>
#include <vector>
using namespace std;
    void PrintSolution(vector<vector<char>>&board,int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
    }
    bool is_safe(vector<vector<char>>&board,int n,int row,int col){
        //checking for the row
        int i=row;
        int j=col;
        while(j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            j--;
        }
        //checking for the left upper diagnol
         i=row;
         j=col;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        //checking for left upper diagnol
         i=row;
         j=col;
        while(i<n && j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i++;
            j--;

        }
        return true;

    }
    void FindSolution(vector<vector<char>>&board,int col,int n){
        //base case
        if(col>=n){
            PrintSolution(board,n);
            return;
        }
        for(int row=0;row<n;row++){
            if(is_safe(board, n, row,col)){
                board[row][col]='Q';
                FindSolution(board,col+1,n);
                //backtracking
                board[row][col]='-';
            }
        }
    }
int main(){
    int n=8;
    vector<vector<char>> board(n,vector<char>(n,'-'));
    int col = 0;
    FindSolution(board,col,n);
}*/

//2nd solution for nqueen problem
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void PrintSolution(vector<vector<char>>&board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
    cout<<endl;

}
bool isSafe(vector<vector<char>>&board,int col,int row,int n,unordered_map<int,bool>&LLD,unordered_map<int,bool>&ULD,unordered_map<int,bool>&row_check){
    if(row_check[row]==true){
        return false;
    }
    if(ULD[n-1 + col -row]==true){
        return false;
    }
    if(LLD[row+ col]==true){
        return false;
    }
    return true;

}
void FindSolution(vector<vector<char>>&board,int col,int n,unordered_map<int,bool>&LLD,unordered_map<int,bool>&ULD,unordered_map<int,bool>&row_check){
    //base
    if(col>=n){
        PrintSolution(board,n);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(board,col,row,n,LLD,ULD,row_check)){
            board[row][col]='Q';
            row_check[row]=true;
            LLD[row+col]=true;
            ULD[n-1 + col -row]=true;
            FindSolution(board,col+1,n,LLD,ULD,row_check);
            //backtracking calls 
            board[row][col]='-';
            row_check[row]=false;
            LLD[row+col]=false;
            ULD[n-1 + col -row]=false;

        }
    }
}
int main(){
    int n = 4;
    vector<vector<char>> board(n,vector<char>(n,'-'));
    unordered_map<int,bool> row_check; //for checking left side of the row
    unordered_map<int,bool>LLD;//lower left diagnol
    unordered_map<int,bool>ULD;//upper left diagnol
    FindSolution(board,0,n,LLD,ULD,row_check);
}
