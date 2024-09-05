/*#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int i,int j,int row,int col,int arr[3][3],vector<vector<bool>>&visited){
    if(((i>=0&&i<row)&&(j>=0&&j<=col))&&
        arr[i][j]==1 &&
        visited[i][j]==false
    ){
        return true;
    }
    else{
        return false;
    }
}
void findPath(int arr[3][3],int row,int col,int i,int j,vector<vector<bool>>&visited,vector<string>&path,string output){
     //base case:- if we reach the destination 
     if(i==row-1&&j==col-1){
        path.push_back(output);
        return;
     }
     //down = i+1,j
     if(isSafe(i+1,j,row,col,arr,visited)){
        visited[i+1][j]=true;
        findPath(arr,row,col,i+1,j,visited,path,output + "D");
        //backtracking call 
        visited[i+1][j] = false;
     }
     //left = i,j-1
    if(isSafe(i,j-1,row,col,arr,visited)){
        visited[i][j-1]=true;
        findPath(arr,row,col,i,j-1,visited,path,output + "L");
        //backtracking call 
        visited[i][j-1] = false;
     }


     //right = i,j+1
    if(isSafe(i,j+1,row,col,arr,visited)){
        visited[i][j+1]=true;
        findPath(arr,row,col,i,j+1,visited,path,output + "R");
        //backtracking call 
        visited[i][j+1] = false;
    }

     //up = i-1,j
    if(isSafe(i-1,j,row,col,arr,visited)){
        visited[i-1][j]=true;
        findPath(arr,row,col,i-1,j,visited,path,output + "U");
        //backtracking call 
        visited[i-1][j] = false;
     }
}
int main(){
    int arr[3][3] = {
        {1,0,0},
        {1,1,0},
        {1,1,1}
    };
    int row = 3;
    int col = 3;
    vector<vector<bool>> visited(row,vector<bool>(col,false));
    visited[0][0]=true;
    vector<string>path;
    string output = "";
    findPath(arr,row,col,0,0,visited,path,output);
    for(auto value:path){
        cout<<value<<" ";
    }

}*/


//shorter version of the code
#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int i,int j,int row,int col,int arr[3][3],vector<vector<bool>>&visited){
    if(((i>=0&&i<row)&&(j>=0&&j<=col))&&
        arr[i][j]==1 &&
        visited[i][j]==false
    ){
        return true;
    }
    else{
        return false;
    }
}
void findPath(int arr[3][3],int row,int col,int i,int j,vector<vector<bool>>&visited,vector<string>&path,string output,vector<string>&direction,int moves[4][2]){
     //base case:- if we reach the destination 
     if(i==row-1&&j==col-1){
        path.push_back(output);
        return;
     }
     for(int k=0;k<4;k++){
        int new_i=i+moves[k][0];
        int new_j=j+moves[k][1];
        if(isSafe(new_i,new_j,row,col,arr,visited)){
            visited[new_i][new_j]=true;
            findPath(arr,row,col,new_i,new_j,visited,path,output + direction[k],direction,moves);
            visited[new_i][new_j]=false;
        }
     }
}
int main(){
    int arr[3][3] = {
        {1,0,0},
        {1,1,0},
        {1,1,1}
    };
    vector<string>direction = {"D","L","R","U"};
    int moves [4][2] = {
        {1,0},
        {0,-1},
        {0,1},
        {-1,0}

    };
    int row = 3;
    int col = 3;
    vector<vector<bool>> visited(row,vector<bool>(col,false));
    visited[0][0]=true;
    vector<string>path;
    string output = "";
    findPath(arr,row,col,0,0,visited,path,output,direction,moves);
    for(auto value:path){
        cout<<value<<" ";
    }
}

