/*Approach: An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:
s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...

why this quest can be solved by dp?
-> here we have choice (char of string a can be equal to string n or char of string b, choose b/w them)
-> optimal solution

this quest is same as finding string a is completely present in string n or not



*/
#include<bits/stdc++.h>
using namespace std;

bool interleaveString(string a, int n1, string b, int n2, string n, int size);

int main(){
    string a, b, n;
    cout<<"Enter strings ";
    cin>>a>>b>>n;
    int n1 = a.size();
    int n2 = b.size();
    int size = n.size();
    cout<<interleaveString(a, n1, b, n2, n, size);
}
//Recursive approach - giving TLE
/*bool interleaveString(string a, int n1, string b, int n2, string n, int size){
// base condition
if(n1 == 0 && n2 == 0 && size == 0){
    return true;
}
else if(n1>=0 && a[n1-1] == n[size-1] && n2>=0 && b[n2-1] == n[size-1]){
    return interleaveString(a,n1-1,b,n2,n,size-1) || interleaveString(a, n1, b, n2-1, n, size-1);
}
else if(n1>=0 && a[n1-1] == n[size-1]){
    return interleaveString(a, n1-1, b, n2, n, size-1);
   
}
else if(n2>=0 && b[n2-1] == n[size-1]){
    return interleaveString(a, n1, b, n2-1, n, size-1);
   
}
else return false;
}
*/
bool isInterleave(string s1, string s2, string s3) {
        vector<int>cur(s2.size()+1,0),prev(s2.size()+1,0);
        if(s3.size()!=s1.size()+s2.size()){
            return false;
        }
        for(int i=s1.size();i>=0;i--){
            for(int j=s2.size();j>=0;j--){
                int k=i+j;
                if(i==s1.size()&&j==s2.size()){
                    cur[j]=1;
                }
                else if(s3[k]==s2[j]&&s3[k]==s1[i]){
                    cur[j]= prev[j]||cur[j+1];
                }
                else if(s1[i]==s3[k]){
                    cur[j]= prev[j];
                }
                else if(s3[k]==s2[j]){
                    cur[j]= cur[j+1];
                }
                else{
                    cur[j]= false;
                }  
            }
            prev=cur;
        }
        return cur[0];
    }
