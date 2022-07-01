#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longestString(vector<string> &arr);
int static t[27][1001];
int main(){
    int n;
    cout<<"Enter size of array of strings";
    cin>>n;
    vector<string> arr(n);
    cout<<"Enter all strings";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    memset(t, -1, sizeof(t));
    int len = longestString(arr);
    cout<< len;
}

int longestString(vector<string> &arr){
    int count = 0;
    for(int i  = 0; i<arr.size(); i++){
        int m = arr[i].size();
        string s = arr[i];
        int total = 0;
        while(m>=0){
            if(t[s[m-1] - 'a'][i] == -1){
                t[s[m-1] - 'a'][i] = 1;
                total++;
            }
            m--;
        }
        if(total == 1) count++;
    }
    return count;
}
