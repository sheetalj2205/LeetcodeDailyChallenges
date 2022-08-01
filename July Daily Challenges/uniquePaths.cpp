/*Approach: DP problem
1) There are three approaches to solve this problem: recursive, memoization and tabulation(bottom-up)
2) In recursive TC is of exponential and SC is of path length
3) In memoization TC is of O(m*n) and SC is of O(path length) + m*n(space of dp)
4) In tabulation TC and SC both are of O(m*n);
*/

#include<bits/stdc++.h>
using namespace std;

int maxPaths(int n, int m);

int main(){
    int n, m;
    cout<<"Enter row and columns of matrix ";
    cin>>n>>m;
    cout<<maxPaths(n-1, m-1);
}

int maxPaths(int n, int m){
    /*recursive solution
    //base condition
    if(n == 0 && m == 0){
        return 1;
    }
    if(n<0 || m<0){
        return 0;
    }
    //choice diagram code - decrease row and column while moving upward and left
    int up = maxPaths(n-1, m);
    int left = maxPaths(n, m-1);

    return up+left;
    */
   /* bottom-up Approach*/
   int dp[n+1][m+1];
   for(int i = 0; i<=n; i++){
    for(int j = 0; j<=m; j++){
        if(i == 0 && j == 0){
            dp[0][0] = 1; //base case when you are at 0,0 pos
        }
        else{
            int up = 0, left = 0;
            if(i>0) up = dp[i-1][j]; //go one step up
            if(j>0) left = dp[i][j-1]; //go one step left
            dp[i][j] = up+left;
        }
    }
   }

    return dp[n][m];

}
