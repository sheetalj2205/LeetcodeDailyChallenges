#include<bits/stdc++.h>
using namespace std;

int fib(int n);

int main(){
    int n;
    cout<<"Enter number ";
    cin>>n;
    cout<<fib(n);
}
 int fib(int n) {
        /*Recursive solution
        //base condition
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        return fib(n-1)+fib(n-2);
        */
        //top-down approach
        vector<int> dp(n+1, -1);
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        dp[0] = 0, dp[1] =1 ;
        for(int i = 2; i<n+1; i++){
            dp[i] = dp[i-1] + dp[i-2];
       }
       return dp[n]; 
    }
