#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxErasure(vector<int>& arr);
int main(){
    int n;
    cout<<"Enter size of the array"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array";
    for(int i = 0; i<n ;i++){
        cin>>arr[i];
    }
    int output = maxErasure(arr);
    cout<<output;
}

int maxErasure(vector<int>& arr){
    // sliding window - shrink or expand window
    vector<bool> freq(10001, false);
    int i = 0, j = 0, size = arr.size(), curr = 0, ans = 0;
    while(j < size){ // iterate till j < size

        while(freq[arr[j]]){  //if value of j in map is true then iterate it until it becomes false
            curr -= arr[i]; //for this subtract arr[i] from curr sum
            freq[arr[i++]] = false; //make value of arr[i] false in map and increase i
        }
        curr += arr[j]; //add arr[j] in sum
          freq[arr[j++]] = true; //make its value true in map and increase j value
        ans = max(ans, curr);

    }
    return ans;

}
