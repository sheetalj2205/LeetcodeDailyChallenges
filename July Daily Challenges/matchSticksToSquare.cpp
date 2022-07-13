#include<bits/stdc++.h>
using namespace std;

bool isSquare(vector<int> arr);

int main(){
    cout<<"enter size of array ";
    int n, sum;
    cin>>n;
    cout<<"Enter array ";
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<isSquare(arr);
}
bool isSquare(vector<int> arr){
    int sum = 0, n = arr.size();
    for(int i = 0; i<n; i++){
        sum += arr[i];
    }
    int target = sum/4, count = 0;
    if(sum % 4 != 0){
        return false;
    }
    for(int i = 0; i<n; i++){
        if(arr[i] == target){
            count++;
        }
    }
    int dp[n+1][target+1];
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<target+1; j++){
            dp[i][0] = 1;
            dp[0][j] = 0;
        }

    }
    dp[0][0] = 1;
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<target+1; j++){
             if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j - arr[i-1]] + dp[i-1][j];
             }
             else if (arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
             }
        }
    }
   return dp[n][target] == 4;

}
