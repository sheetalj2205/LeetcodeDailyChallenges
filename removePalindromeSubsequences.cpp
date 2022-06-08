#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int removePalindrome(string s);
int main(){
    string s;
    cout<<"Enter string"<<endl;
    cin>>s;
    int ans = removePalindrome(s);
    cout<<ans;
}

int removePalindrome(string s){
    // as string only contains two chars "a" and "b" so there can be only three value of output to make that string empty - 0, 1, 2
    int size = s.size();
    if(s.empty()){
       return 0; // 0 when string is empty
    }
    int low  = 0, high = s.size()-1, c = 0;
    while(low<high){
        if(s[low] == s[high]){
             c++;
        }
        low++;
        high--;
    }
    if(c == size/2){ //when string is palindrome then only 1 step is required to make it empty
        return 1;
    }
    else{
        return 2; //when string is not palindrome the we need 2 steps to make it empty, as they are subsequences we can take all a's in one step and all b's in next step
    }
}
