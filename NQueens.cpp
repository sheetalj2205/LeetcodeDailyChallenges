#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> solveNQueens(int n);
int main(){
    int n;
    cout<<"Enter n for the matrix";
    cin>>n;
    solveNQueens(n);
}

bool isSafe(int row, int col, vector<string> board, int n){
    int dupcol = col;
    int duprow = row;

    while(col>=0){
        if(board[row][col] == 'Q') return false;
        col--;
    }

    row = duprow;
    col = dupcol;

    while(row>=0 && col>=0){
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    row = duprow;
    col = dupcol;

    while(row<n && col>=0){
        if(board[row][col] == 'Q') return false;
        row++;
        col--;
    }
    return true;
}
void solve (int col, vector<string> &board, vector<vector<string>> &ans, int n){
    if(col == n){
        ans.push_back(board); //base case when all columns are filled
        return;
    }
    for(int row = 0; row<n; row++){
    if(isSafe(row, col, board, n)){ //check is it safe to place queen there or not
         board[row][col] = 'Q';
         solve(col+1, board, ans, n); //recursion for next column
         board[row][col] = '.'; //after coming back from recursion replace "Q" with "." and place "Q" in next row(as per the loop)
    }
    }
}

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> ans;  //ans
    vector<string> board(n); //vector which has n strings of size n. Similarly like a chess board
    string s (n, '.'); // string of size n which has n dots.
    for(int i=0; i<n; i++){
        board[i] = s; //filling board
    }
    solve(0,board,ans,n); // calling function
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<ans[i][j] <<endl;
        }
    }
    return ans;
}

