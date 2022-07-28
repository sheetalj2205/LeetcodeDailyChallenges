/*Appraoch: check if two strings have same chars or not/ Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
1) create a hash table and increase count of char for one string and decrease count for second string.
2) check if element of hash table is equal to its initial value or not (if not then return false)
*/
#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t);

int main(){
    string s, t;
    cout<<"Enter strings ";
    cin>>s>>t;
    cout<< isAnagram(s, t);
}

bool isAnagram(string s, string t){
    vector<int> vec(26,-1);
        if(s.size() != t.size()){
            return false;
        }
        for(int i = 0; i<s.size(); i++){
            vec[s[i] - 'a']++;
            vec[t[i] - 'a']--;
        }
        if(count(vec.begin(), vec.end(), -1) == 26){ //time complexity of count function - O(n)
            return true;
        }
        return false;
        
}


