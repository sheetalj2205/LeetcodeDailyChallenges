#include<bits/stdc++.h>
using namespace std;

int findPaths(int m, int n, int N, int i, int j);

int main(){
    int m, n, maxMoves, startRow, startCol;
    cout<<"Enter m, n, maxMoves, startRow and startCol ";
    cin>>m>>n>>maxMoves>>startRow>>startCol;
    cout<<findPaths(m, n, maxMoves, startRow, startCol);
}

int mod = pow(10,9) + 7;
int helperFunction(int row, int col, int maxMoves, int x, int y,  int moves, vector<vector<vector<int>>> & dp){
        //check boundary conditions
        if(x < 0 || y < 0 || x >= row || y >= col){
            return 1;
        }
        if(moves == maxMoves){
            return 0;
        }
        if(dp[moves][x][y] != -1){
            return dp[moves][x][y] % mod;
        }
        int tempVal = 0;
        //check in all the four directions
        tempVal = (tempVal + helperFunction(row, col, maxMoves, x, y - 1, moves + 1, dp)) % mod;
        tempVal = (tempVal + helperFunction(row, col, maxMoves, x - 1, y, moves + 1, dp)) % mod;
        tempVal = (tempVal + helperFunction(row, col, maxMoves, x + 1, y, moves + 1, dp)) % mod;
        tempVal = (tempVal + helperFunction(row, col, maxMoves, x, y + 1, moves + 1, dp)) % mod;
        //update dp with tempVal
        dp[moves][x][y] = tempVal;
        return dp[moves][x][y] % mod;
    }

int findPaths(int m, int n, int N, int i, int j){
    //create 3D dp to track i, j and moves
     vector<vector<vector<int>>> dp(N + 1, vector<vector<int>> (m + 1, vector<int> (n + 1, -1)));
     //call helper function with no. of rows, cols, maxMoves, position of ball, moves and dp as param
        dp[N][m][n] = helperFunction(m, n, N, i, j, 0, dp);
        return dp[N][m][n];
}
