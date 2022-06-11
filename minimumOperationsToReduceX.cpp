#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int minOperations(vector<int>& arr, int t);
int main(){
    int n;
    cout<<"Enter size of the array"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array";
    for(int i = 0; i<n ;i++){
        cin>>arr[i];
    }
    int t;
    cout<<"Enter value of X"<<endl;
    cin>>t;
    int output = minOperations(arr, t);
    cout<<output;
}
int minOperations(vector<int>& arr, int X){
    // sliding window approach
    int left = 0, sum = 0, res = INT_MAX, sz = arr.size(), right = 0;
    for(int i = 0; i<arr.size(); i++){
        sum += arr[i]; // find sum of all elements of array
    }
    while(left<=right){
        if(sum >= X){ // if sum of all elements is greater than target
            if(sum == X){ // if sum equals to target
                res = min(res, left+sz-right); // fin res which is length of the remaining elements which are adding up to target
            }
            if(right < sz){ // if your sum is not equal to target yet then increase right pointer towards end of array and subtract its value from sum
                sum -= arr[right++];
            }
            else{
                break; // if both of the condition not true then break the loop
            }
        }
        else{
            sum += arr[left++]; // if sum is less than target then add value at left to sum 
        }
    }

      return res == INT_MAX? -1: res;
    }
