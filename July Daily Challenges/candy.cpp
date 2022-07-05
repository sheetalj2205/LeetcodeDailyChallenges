#include<bits/stdc++.h>
using namespace std;

/*Approach: use two vectors for left neighbour and right neighbour same as size of array and initialize them with 1, as left neighbour should be less than element so start loop from i=1 and check i-1 when arr[i-1] < arr[i] then add 1 to L_candy[i-1] ele to get L_candy[i], similary do for right neigbour start loop from i = n-2 to check its right neighbour i+1

Another approch: use peak and valley approach
*/

int minCandy(vector<int> &ratings);

int main(){
    cout<<"Enter size of array ";
    int n;
    cin>>n;
    cout<<"Enter array ";
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<minCandy(arr);
}

int minCandy(vector<int>& ratings) {
        int n = ratings.size(), ans = 0;
        vector<int>L_candy(n,1);
        vector<int>R_candy(n,1);
        
        for(int i =1; i<n; i++){
            if(ratings[i] > ratings[i-1]){ //check left neighbour is smaller than ele or not
              L_candy[i] = L_candy[i-1] + 1;
            }
        }
        for(int i = n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){ //check right neighbour is smaller than ele or not
                R_candy[i] = R_candy[i+1] + 1;
            }
        }
        for(int i =0; i<n; i++){
            ans += max(R_candy[i], L_candy[i]); // take max of both the values to find min candies
        }
       return ans;
    }
