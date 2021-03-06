#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longestSubseq(string word1,int n, string word2, int m);
int main(){
    string word1, word2;
    cout<<"Enter strings"<<endl;
    cin>>word1;
    cin>>word2;
    
    int n = word1.size();
    int m = word2.size();
    int len = longestSubseq(word1, n, word2, m);
    int ans = n- len + m - len;
    cout<< ans ;
}
int longestSubseq(string word1, int n, string word2, int m){
    //first approach - recursion - three important things: 1) base condition 2) choice diagram 3) I/P smallest
    
    if(n == 0 || m == 0){ //base condition i.e. smallest valid input
        return 0;
    }
    else if(word1[n-1] == word2[m-1]){
        return 1 + longestSubseq(word1, n-1, word2, m-1); //if both values/chars are equal then check for next chars, adding 1 because of that one similar char
    }
    return max(longestSubseq(word1, n, word2, m-1), longestSubseq(word1, n-1, word2, m)); //if chars are not equal then this condition takes max value from both the recursions
    //------------------------------------------------------
    // top-down approach DP
    int dp[n+1][m+1];
    for(int i = 0; i<n+1; i++){ //use these loops for base condition of recursive solution i.e when either length of word1 or word2 is zero
        for(int j  = 0; j<m+1; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i = 1; i<n+1; i++){
        for(int j  = 1; j<m+1; j++){
            if(word1[i-1] == word2[j-1]){ //check if chars are equal or not
                dp[i][j] = 1 + dp[i-1][j-1]; // if they are equal add one to the previous value of dp[i][j]      
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]); //similar to recursive solution when chars are not equal, check one by one(take first word whole leaving second word's last or first char and vice versa ) and take max from them
            }
        }
    }
    return dp[n][m];
}
