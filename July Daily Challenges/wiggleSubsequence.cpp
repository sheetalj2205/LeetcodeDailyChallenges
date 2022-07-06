#include<bits/stdc++.h>
using namespace std;
// Aproach: find no. of peaks and valleys and the ans would be max of both
int maxLength(vector<int> arr);

int main(){
    int n;
    cout<<"Enter size of array ";
    cin>>n;
    cout<<"Enter array ";
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<maxLength(arr);
}

int maxLength(vector<int> arr){
    int n = arr.size();
    int inc = 1, dec =  1;
    for(int i = 1; i<n; i++){
        if(arr[i-1] > arr[i]){ //means i found a peak, arr[i-1] is a peak
            inc = dec + 1;
        }
        if(arr[i] > arr[i-1]){// means valley is found means arr[i-1] is valley
            dec = inc + 1;
        }
    }
    return max(inc, dec);
}
