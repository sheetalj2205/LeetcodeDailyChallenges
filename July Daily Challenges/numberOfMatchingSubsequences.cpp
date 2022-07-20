#include<bits/stdc++.h>
using namespace std;

int number(string a, vector<string> words);

int main(){
    int n;
    cout<<"Enter size of words array ";
    cin>>n;
    string a;
    vector<string> words(n);
    cout<<"Enter string ";
    cin>>a;
    cout<<"Enter words ";
    for(int i = 0; i<words.size(); i++){
        cin>>words[i];
    }
    cout<<number(a, words);
}

int number(string a, vector<string> words){
    int count = 0, n = a.size();

    //unordered map to store the frequency of each word in words array to avoid multiple calculation

    unordered_map<string, int> mp;

    for(string word: words){
        mp[word]++;
    }
    
    //iterate map

    for(auto x: mp){
        string str = x.first;
        int start1 = 0, start2 = 0;
        int m = str.size();
        
        //check chars of both the words
        while(start1 < n && start2 < m){
            if(a[start1] == str[start2]){
                start1++, start2++;
            }
            else{
                start1++;
            }
        }if(start2 == m){
            count += x.second;
        }
    }
    return count;
}
