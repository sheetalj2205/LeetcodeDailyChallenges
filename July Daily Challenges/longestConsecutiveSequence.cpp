#include<bits/stdc++.h>
using namespace std;

int longestSeq(vector<int> arr);

int main(){
    cout<<"Enter size of array ";
    int n;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<longestSeq(arr);
}

int longestSeq(vector<int> arr){
    /* Approach 1:
    Simply sort the array and iterate it to get the longest consecutive seq.
    Time Complexity = O(n log n) + O(n)
    */
   /*
    sort(arr.begin(), arr.end());
    int ans = 0, len =2;
    for(int i = 1; i<arr.size()-1; i++){
        int diff = arr[i] - arr[i-1];
        if(arr[i+1] - arr[i] == diff){
            len++;
        }
        ans = max(len, ans);
    }
    return ans;
    */
    /* Approach 2:
    Insert all the elements in hash set then iterate the set
    first to find the element one less than it and keep finding it till you get the least ele. 
    Time complexity : O(N) + O(N) + O(N)
    1) First to insert all elements in set
    2) for the iterations that you do over array
    3) for checking out iterations since you might have multiple consecutive sequences then also at max you do o(n) inside while loop
    Space complexity: unordered_set in C++ works in O(n) time in java it works in O(1) time.
    */
    set<int> s;
    for(int i = 0; i<arr.size(); i++){ //this is not the faster method to insert elements in set, use: unordered_set<int> s(nums.begin(),nums.end()); this is faster
        s.insert(arr[i]);
    }
    int longestStreak = 0;
    for(int num : arr){
        if(!s.count(num-1)){ //if elem less than num doesn't exist in the set
            int currNum = num;
            int currStreak = 1;

            while(s.count(currNum+1)){ 
                currNum += 1;
                currStreak++;
            }
            longestStreak = max(longestStreak, currStreak);
        }
    }
      return longestStreak;
}
