#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int longestSubstring(string s);
int main(){
    string s;
    cout<<"Enter string"<<endl;
    cin>>s;
    int ans = longestSubstring(s);
    cout<<ans;
}

int longestSubstring(string s){
   vector<int> temp(256,-1); // as ASCII value is upto 256 for all the characters

   int start = -1;
   int j = 0;
   for(int i = 0; i<s.size(); i++){
       if(temp[s[i]] > start){
           start = temp[s[i]];

       }
        temp[s[i]] = i;
        j = max(j, i-start);


   }
   return j;


}
