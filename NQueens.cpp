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
        ans.push_back(board);
    }
    for(int row = 0; row<n; row++){
    if(isSafe(row, col, board, n)){
         board[row][col] = 'Q';
         solve(col+1, board, ans, n);
         board[row][col] = '.';
    }
    }
}

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> ans;  //ans
    vector<string> board(n); 
    string s (n, '.');
    for(int i=0; i<n; i++){
        board[i] = s; //filling board(first row)
    }
    solve(0,board,ans,n); // calling function
    return ans;
}

