/* Approach: select elements which has to be removed from the array to make it size half of the original array
*/
#include<bits/stdc++.h>
using namespace std;

int minSetSize(vector<int>& arr);

int main(){
    int n;
    cout<<"Enter Array size ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<minSetSize(arr);
}

int minSetSize(vector<int>& arr){
    // hash table can also be used but it is giving runtime error for one case as it is occupying more space
        int n = arr.size();
        //first calculate frequency of each element
        unordered_map<int, int> hash;
        for(int i = 0; i<n; i++){
            hash[arr[i]]++;
        }
        //insert them in heap (max freq on top)
        priority_queue<int> q;
        for(auto i : hash){
            q.push(i.second);
        }
        int ans = 0, sum = 0;
        //then remove those elements which has max freq
        while(sum<n/2){
            sum += q.top();
            q.pop();
            ans++;
        }
        return ans;
        
}
