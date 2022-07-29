/*Approach: A word will match pattern only when -
Every letter word[i] can be mapped to a unique letter pattern[i]
*/

#include<bits/stdc++.h>
using namespace std;

void findAndReplacePattern(vector<string>& words, string p);

int main(){
    int n;
    cout<<"Enter size of array of words ";
    cin>>n;
    vector<string> words(n);
    cout<<"Enter words ";
    for(int i = 0; i<n; i++){
        cin>>words[i];
    }
    string p;
    cout<<"Enter pattern ";
    cin>>p;
}
void findAndReplacePattern(vector<string> &words, string p){
    vector<string> ans;
    for(string word: words){
        //check if they are in pattern or not
        if(isMatch(word, p)){
            ans.push_back(word);
        }
    }
    for(string word : ans){
        cout<<word<<" ";
    }
}

bool isMatch(string word, string p){
    unordered_map<char, char> wordToPattern;
    unordered_map<char, char> patternToWord;

    /*
    Create two maps for mapping of both the strings with each other
    -> if in any of the map count of any char in the string is 1 then it will return false as maps have single key, value pair
    -> if in any map value of particular key at index i is not equals to the char of other string at index i the return false
    -> else in all the cases map one char with other
    */

    for(int i = 0; i<word.size(); i++){
        if((wordToPattern.count(word[i]) && wordToPattern[word[i]] != p[i]) ||
        patternToWord.count(p[i]) &&
        patternToWord[p[i]] != word[i]){
            return false;
        }

        wordToPattern[word[i]] = p[i];
        patternToWord[p[i]] = word[i];
    }
    return true;

}
