#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solveNQueensII(int n);
int main(){
    int n;
    cout<<"Enter n for the matrix";
    cin>>n;
    solveNQueensII(n);
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
int solve (int col, vector<string> &board, int n){
    int count = 0;
    if(col == n){
        return 1;
    }
    for(int row = 0; row<n; row++){
    if(isSafe(row, col, board, n)){ //check is it safe to place queen there or not
         board[row][col] = 'Q';
         count += solve(col+1, board, n); //recursion for next column
         board[row][col] = '.'; //after coming back from recursion replace "Q" with "." and place "Q" in next row(as per the loop)
    }
    }
    return count;
}

void solveNQueensII(int n){
    vector<string> board(n); //vector which has n strings of size n. Similarly like a chess board
    string s (n, '.'); // string of size n which has n dots.
    for(int i=0; i<n; i++){
        board[i] = s; //filling board
    }
    int c = solve(0,board,n);
    cout<<c;
}

