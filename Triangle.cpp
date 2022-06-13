#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int triangle(vector<vector<int>>& arr);
int main(){
    int n,m;
    cout<<"Enter size of the array and columns"<<endl;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(n,0));
    cout<<"Enter array";
    for(int i = 0; i<n ;i++){
        for(int j = 0; j<i+1; j++){
               cin>>arr[i][j];
        }
    }
    int output = triangle(arr);
    cout<<output;
}
int triangle(vector<vector<int>>& arr){
    //top bottom approach
    for(int i = 0; i<arr.size(); i++){
        for(int j  = 0; j<arr[0].size(); j++){
            int sum = 0;
            if(j == 0){
                sum = arr[i][j] + arr[i-1][j];
            }
            else if(j == arr[i].size()-1){
                sum = arr[i][j] + arr[i-1][arr[i-1].size()-1];
            }
            else{
                int mn = min(arr[i-1][j-1], arr[i-1][j]);
                sum = mn + arr[i][j];
            }
            arr[i][j] = sum;

        }
    }
    vector<int> a = arr[arr.size()-1];
    return *min_element(a.begin(),a.end());

    // bottom-up approach
    for(int i  = arr.size()-2; i>=0; i--){ // start from last second row to get min from last row
        for(int j = 0; j<arr[i].size(); j++){
            int mn = min(arr[i+1][j], arr[i+1][j+1]); // find min from upper row
            arr[i][j] = arr[i][j] + mn;//update
        }

    }
    return arr[0][0];
}
